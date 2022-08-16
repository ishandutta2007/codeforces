#include<bits/stdc++.h>

using namespace std;
using int64 = long long;

struct SuffixArray {
  vector< int > SA;
  const string s;

  SuffixArray(const string &str) : s(str) {
    SA.resize(s.size());
    iota(begin(SA), end(SA), 0);
    sort(begin(SA), end(SA), [&](int a, int b) {
      return s[a] == s[b] ? a > b : s[a] < s[b];
    });
    vector< int > classes(s.size()), c(s.begin(), s.end()), cnt(s.size());
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
    return SA[k];
  }

  size_t size() const {
    return s.size();
  }

  bool lt_substr(const string &t, int si = 0, int ti = 0) {
    int sn = (int) s.size(), tn = (int) t.size();
    while(si < sn && ti < tn) {
      if(s[si] < t[ti]) return true;
      if(s[si] > t[ti]) return false;
      ++si, ++ti;
    }
    return si >= sn && ti < tn;
  }

  int lower_bound(const string &t) {
    int low = -1, high = (int) SA.size();
    while(high - low > 1) {
      int mid = (low + high) / 2;
      if(lt_substr(t, SA[mid])) low = mid;
      else high = mid;
    }
    return high;
  }

  pair< int, int > lower_upper_bound(string &t) {
    int idx = lower_bound(t);
    int low = idx - 1, high = (int) SA.size();
    t.back()++;
    while(high - low > 1) {
      int mid = (low + high) / 2;
      if(lt_substr(t, SA[mid])) low = mid;
      else high = mid;
    }
    t.back()--;
    return {idx, high};
  }

  void output() {
    for(int i = 0; i < size(); i++) {
      cout << i << ": " << s.substr(SA[i]) << endl;
    }
  }
};

struct LongestCommonPrefixArray {
  const SuffixArray &SA;
  vector< int > LCP, rank;

  LongestCommonPrefixArray(const SuffixArray &SA) : SA(SA), LCP(SA.size()) {
    rank.resize(SA.size());
    for(int i = 0; i < SA.size(); i++) {
      rank[SA[i]] = i;
    }
    for(int i = 0, h = 0; i < SA.size(); i++) {
      if(rank[i] + 1 < SA.size()) {
        for(int j = SA[rank[i] + 1]; max(i, j) + h < SA.size() && SA.s[i + h] == SA.s[j + h]; ++h);
        LCP[rank[i] + 1] = h;
        if(h > 0) --h;
      }
    }
  }

  int operator[](int k) const {
    return LCP[k];
  }

  size_t size() const {
    return LCP.size();
  }

  void output() {
    for(int i = 0; i < size(); i++) {
      cout << i << ": " << LCP[i] << " " << SA.s.substr(SA[i]) << endl;
    }
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
    if(l >= r) return 1 << 30;
    int b = lookup[r - l];
    return min(st[b][l], st[b][r - (1 << b)]);
  }
};


int main() {
  int N, Q;
  string S;

  cin >> N >> Q;
  cin >> S;
  SuffixArray sa(S);
  LongestCommonPrefixArray lcp(sa);
  vector< int > rev(N);
  for(int i = 0; i < N; i++) rev[sa[i]] = i;
  SparseTable< int > table(lcp.LCP);

  while(Q--) {
    int K, L;
    cin >> K >> L;
    vector< pair< int, bool > > ev;
    for(int i = 0; i < K + L; i++) {
      int x;
      cin >> x;
      --x;
      ev.emplace_back(x, i >= K);
    }
    sort(begin(ev), end(ev), [&](const pair< int, bool > &a, const pair< int, bool > &b) {
      return rev[a.first] < rev[b.first];
    });
    int64 sum[2] = {0, 0};
    int64 ret = 0;
    stack< tuple< int, int, int > > beet[2];
    for(auto &p : ev) {
      for(int k = 0; k < 2; k++) {
        if(beet[k].size()) {
          int sz = 0, update = 0;
          while(beet[k].size()) {
            int x, y, z;
            tie(x, y, z) = beet[k].top();
            auto uku = table.rmq(z + 1, rev[p.first] + 1);
            if(uku > y) break;
            update = uku;
            sum[k] -= 1LL * x * y;
            beet[k].pop();
            sz += x;
          }
          if(sz > 0) {
            sum[k] += 1LL * sz * update;
            beet[k].emplace(sz, update,  rev[p.first]);
          }
        }
      }
      ret += sum[1 ^ p.second];
      beet[p.second].emplace(1, N - p.first, rev[p.first]);
      sum[p.second] += N - p.first;
    }
    cout << ret << endl;
  }
}