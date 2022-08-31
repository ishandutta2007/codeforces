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

  SparseTable() {}

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
  }

  inline T rmq(int l, int r) // [l, r)
  {
    int b = 32 - __builtin_clz(r - l) - 1;
    return (min(st[b][l], st[b][r - (1 << b)]));
  }
};


int main() {
  int N, po[301];

  cin >> N;
  string x;
  vector< int > cover(202020);
  for(int i = 0; i < N; i++) {
    if(i > 0) x += " ";
    string s;
    cin >> s;
    po[i] = (int) x.size();
    for(int j = 0; j <= s.size(); j++) cover[x.size() + j] = i - 1;
    for(int j = 1; j < 10; j++) cover[x.size() + s.size() - 1 + j] = i;
    x += s;
  }
  x += " ";
  po[N] = x.size();

  SuffixArray sa;


  sa.Build_SA(x);
  LongestCommonPrefixArray lcp(sa);

  vector< int > latte(lcp.size());
  for(int i = 0; i < latte.size(); i++) {
    latte[i] = lcp[i];
  }
  SparseTable< int > rmq(latte);
  vector< int > rev(x.size());
  for(int i = 0; i < x.size(); i++) {
    rev[sa[i]] = i;
  }

  const int INF = 1 << 30;


  int ret = 0;

  int beet[300][300];
  memset(beet, -1, sizeof(beet));
  for(int i = 0; i < N; i++) {
    for(int j = i + 1; j < N; j++) {
      pair< int, int > op = minmax(rev[po[i]], rev[po[j]]);
      int mex = rmq.rmq(op.first + 1, op.second + 1);
      if(mex > 0) {
        int covered = cover[po[i] + mex - 1];
        beet[i][j] = covered;
      }
    }
  }

  for(int length = 1; length <= N; length++) {
    for(int i = 0; i < N; i++) { // begin
      if(i + length > N) continue;
      int matched = 1, ptr = i + length;
      while(ptr < N) {
        if(beet[i][ptr] >= i + length - 1) {
          ++matched;
          ptr += length;
        } else {
          ++ptr;
        }
      }

      int prev_size = po[i + length] - po[i] - 1;
      int next_size = length;
      if(matched > 1) {
        ret = max(ret, (prev_size - next_size) * matched);
      }
    }
  }

  cout << x.size() - ret - 1 << endl;

}