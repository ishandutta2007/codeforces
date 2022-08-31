#include <bits/stdc++.h>

using namespace std;

struct SuffixArray
{
  vector< int > SA;
  string s;

  void Build_SA(const string &str)
  {
    s = str;
    SA.resize(s.size());
    iota(begin(SA), end(SA), 0);
    sort(begin(SA), end(SA), [&](const int &a, const int &b)
    {
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

  int operator[](int k) const
  {
    return (SA[k]);
  }

  int size() const
  {
    return (s.size());
  }

  bool lt_substr(string &t, int si = 0, int ti = 0)
  {
    int sn = s.size(), tn = t.size();
    while(si < sn && ti < tn) {
      if(s[si] < t[ti]) return (true);
      if(s[si] > t[ti]) return (false);
      ++si, ++ti;
    }
    return (si >= sn && ti < tn);
  }

  int lower_bound(string &t)
  {
    int low = -1, high = SA.size();
    while(high - low > 1) {
      int mid = (low + high) >> 1;
      if(lt_substr(t, SA[mid])) low = mid;
      else high = mid;
    }
    return (high);
  }

  pair< int, int > lower_upper_bound(string &t)
  {
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

  void output()
  {
    for(int i = 0; i < size(); i++) {
      cout << i << ": " << s.substr(SA[i]) << endl;
    }
  }
};

struct LongestCommonPrefixArray
{
  vector< int > LCP, rank;

  LongestCommonPrefixArray(SuffixArray &SA)
  {
    Build_LCP(SA);
  }

  void Build_LCP(SuffixArray &SA)
  {
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

  int operator[](int k) const
  {
    return (LCP[k]);
  }

  int size() const
  {
    return (LCP.size());
  }
};

using int64 = long long;

int main()
{
  string S;
  cin >> S;
  SuffixArray sa;
  sa.Build_SA(S);
  LongestCommonPrefixArray lcp(sa);
 // sa.output();

  stack< pair< int64, int64 > > st;
  int64 ret = 0, sum = 0;

  for(int i = 1; i < S.size(); i++) {
    int64 proc = 1;
    while(!st.empty() && st.top().first >= lcp[i]) {
      sum -= st.top().first * st.top().second;
      proc += st.top().second;
      st.pop();
    }
    st.emplace(lcp[i], proc);
    sum += lcp[i] * proc;
    ret += sum;
  }

  int sz = (int) S.size();
  ret += 1LL * sz * (sz + 1) / 2;
  cout << ret << endl;
}