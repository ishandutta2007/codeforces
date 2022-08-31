#include<bits/stdc++.h>

using namespace std;

using int64 = long long;

struct SuffixArray {
  vector< int > SA;
  string s;

  void Build_SA(const string &str) {
    s = str;
    SA.resize(s.size());
    iota(begin(SA), end(SA), 0);
    sort(begin(SA), end(SA), [&](const int &a, const int &b) {
      if(s[a] == s[b]) return (a > b);
      return (s[a] < s[b]);
    });
    vector< int > classes(s.size()), c(s.size()), cnt(s.size());
    for(int i = 0; i < s.size(); i++) {
      c[i] = s[i];
    }
    for(int len = 1; len < s.size(); len <<= 1) {
      for(int i = 0; i < s.size(); i++) {
        if(i > 0 && c[SA[i - 1]] == c[SA[i]] && SA[i - 1] + len < s.size() && c[SA[i - 1] + len / 2] == c[SA[i] + len / 2]) {
          classes[SA[i]] = classes[SA[i - 1]];
        } else {
          classes[SA[i]] = i;
        }
      }
      iota(begin(cnt), end(cnt), 0);
      copy(begin(SA), end(SA), begin(c));
      for(int i = 0; i < s.size(); i++) {
        int s1 = c[i] - len;
        if(s1 >= 0) SA[cnt[classes[s1]]++] = s1;
      }
      classes.swap(c);
    }
  }

  int operator[](int k) const {
    return (SA[k]);
  }

  int size() const {
    return (s.size());
  }

  bool lt_substr(string &t, int si = 0, int ti = 0) {
    int sn = s.size(), tn = t.size();
    while(si < sn && ti < tn) {
      if(s[si] < t[ti]) return (true);
      if(s[si] > t[ti]) return (false);
      ++si, ++ti;
    }
    return (si >= sn && ti < tn);
  }

  int lower_bound(string &t) {
    int low = -1, high = SA.size();
    while(high - low > 1) {
      int mid = (low + high) >> 1;
      if(lt_substr(t, SA[mid])) low = mid;
      else high = mid;
    }
    return (high);
  }

  pair< int, int > lower_upper_bound(string &t) {
    int idx = lower_bound(t);
    int low = idx - 1, high = SA.size();
    t.back()++;
    while(high - low > 1) {
      int mid = (low + high) >> 1;
      if(lt_substr(t, SA[mid])) low = mid;
      else high = mid;
    }
    t.back()--;
    return (make_pair(idx, high));
  }

  void output() {
    for(int i = 0; i < size(); i++) {
      cout << i << ": " << s.substr(SA[i]) << endl;
    }
  }
};

struct LongestCommonPrefixArray {
  vector< int > LCP, rank;

  LongestCommonPrefixArray(SuffixArray &SA) {
    Build_LCP(SA);
  }

  void Build_LCP(SuffixArray &SA) {
    string &s = SA.s;
    rank.resize(s.size());
    for(int i = 0; i < s.size(); i++) {
      rank[SA[i]] = i;
    }
    LCP.resize(s.size());
    LCP[0] = 0;
    for(int i = 0, h = 0; i < s.size(); i++) {
      if(rank[i] + 1 < s.size()) {
        for(int j = SA[rank[i] + 1]; max(i, j) + h < s.length() && s[i + h] == s[j + h]; ++h);
        LCP[rank[i] + 1] = h;
        if(h > 0) --h;
      }
    }
  }

  int operator[](int k) const {
    return (LCP[k]);
  }

  int size() const {
    return (LCP.size());
  }
};

template< typename T >
struct SparseTable {
  vector< vector< T > > st;
  vector< int > lookup;

  SparseTable(const vector< T > &v) {
    int b = 0;
    while((1 << b) <= v.size()) ++b;
    st.assign(b, vector< T >(1 << b));
    for(int i = 0; i < v.size(); i++) {
      st[0][i] = v[i];
    }
    for(int i = 1; i < b; i++) {
      for(int j = 0; j + (1 << i) <= (1 << b); j++) {
        st[i][j] = min(st[i - 1][j], st[i - 1][j + (1 << (i - 1))]);
      }
    }
    lookup.resize(v.size() + 1);
    for(int i = 2; i < lookup.size(); i++) {
      lookup[i] = lookup[i >> 1] + 1;
    }
  }

  inline T rmq(int l, int r) {
    int b = lookup[r - l];
    return min(st[b][l], st[b][r - (1 << b)]);
  }
};

int main() {
  string S, T;
  cin >> S >> T;

  int N = (int) S.size();
  int M = (int) T.size();

  int sum[2] = {};
  for(auto &p : S) p -= '0';
  for(auto &p : S) sum[p]++;

  vector< pair< int, int > > sz;
  for(int a = 1; a <= M; a++) {
    int64 rest = M - 1LL * sum[0] * a;
    if(rest <= 0) continue;
    if(rest % sum[1] != 0) continue;
    sz.emplace_back(a, rest / sum[1]);
  }

  int ret = 0;

  SuffixArray sa;
  sa.Build_SA(T);
  LongestCommonPrefixArray lcp(sa);
  SparseTable< int > sp(lcp.LCP);
  vector< int > rev(M);


  for(int i = 0; i < M; i++) rev[sa[i]] = i;


  for(auto &p : sz) {

    vector< int > range[2];
    int pos = 0;
    for(auto &q : S) {
      if(q == 0) {
        range[0].emplace_back(pos);
        pos += p.first;
      } else {
        range[1].emplace_back(pos);
        pos += p.second;
      }
    }

    if(p.first == p.second) {
      int latte = rev[range[0][0]];
      int malta = rev[range[1][0]];
      if(latte > malta) swap(latte, malta);
      if(sp.rmq(latte + 1, malta + 1) >= p.first) continue;
    }

    bool flag = true;
    for(int j = 1; j < range[0].size(); j++) {
      int latte = rev[range[0][j - 1]];
      int malta = rev[range[0][j]];
      if(latte > malta) swap(latte, malta);
      flag &= sp.rmq(latte + 1, malta + 1) >= p.first;
    }

    for(int j = 1; j < range[1].size(); j++) {
      int latte = rev[range[1][j - 1]];
      int malta = rev[range[1][j]];
      if(latte > malta) swap(latte, malta);
      flag &= sp.rmq(latte + 1, malta + 1) >= p.second;
    }

    ret += flag;

  }
  cout << ret << endl;
}