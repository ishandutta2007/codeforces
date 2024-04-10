#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>

using namespace std;

struct SuffixArray{
  SuffixArray(string _s) {
    initialize(_s);
  };
  void initialize(string _s = "") {
    s=_s+"$";
    p.clear(); p.resize(s.size());
    pn.clear(); pn.resize(s.size());
    c.clear(); c.resize(s.size());
    cn.clear(); cn.resize(s.size());
    cnt.clear(); cnt.resize(alphabetSize=max(256,(int)s.size()));
  }
  void build(bool withLcp = false) {
    for(int i=0;i<s.size();++i) {
      cnt[s[i]]++;
    }
    for(int i=1;i<256;++i)
      cnt[i]+=cnt[i-1];
    for(int i=s.size()-1;i>=0;--i)
      p[--cnt[s[i]]]=i;
    int classes=1;
    c[p[0]]=0;
    for(int i=1;i<p.size();++i) {
      if (s[p[i]]!=s[p[i-1]]) ++classes;
      c[p[i]]=classes-1;
    }
    for(int h=0;(1<<h)<s.size();++h) {
      for(int i=0;i<p.size();++i) {
        pn[i]=p[i]-(1<<h);
        if (pn[i]<0) pn[i]+=s.size();
      }
      cnt.assign(alphabetSize,0);
      for(int i=0;i<pn.size();++i)
        ++cnt[c[pn[i]]];
      for(int i=1;i<cnt.size();++i)
        cnt[i]+=cnt[i-1];
      for(int i=pn.size()-1;i>=0;--i) {
        p[--cnt[c[pn[i]]]]=pn[i];
      }
      classes=1; cn[p[0]]=0;
      for(int i=1;i<p.size();++i) {
        int mid1=(p[i-1]+(1<<h))%s.size(),mid2=(p[i]+(1<<h))%s.size();
        if (c[p[i-1]]!=c[p[i]]||c[mid1]!=c[mid2]) ++classes;
        cn[p[i]]=classes-1;
      }
      c=cn;
      if (classes==s.size()) break;
    }
    if (withLcp) buildLcp();
  }
  void buildLcp() { // max common prefix with previous suffix
    lcp.clear(); lcp.resize(s.size());
    rev.clear(); rev.resize(s.size());
    for(int i=0;i<p.size();++i) rev[p[i]]=i;
    int cur=0;
    for(int i=0;i<s.size();++i) {
      if (cur>0) --cur;
      if (rev[i]==0) continue;
      while(i+cur<s.size()&&s[i+cur]==s[p[rev[i]-1]+cur]) ++cur;
      lcp[rev[i]]=cur;
    }
  }
  void output() {
    for(int i=0;i<p.size();++i)
      cout << p[i] << " ";
    cout << endl;
    for(int i=0;i<p.size();++i) {
      cout << s.substr(p[i]) << endl;
    }
    if (lcp.size()==s.size()) {
      for(int i=0;i<lcp.size();++i)
        cout << lcp[i] << " ";
      cout << endl;
    }
  }
  string s;
  int alphabetSize;
  vector <int> p,c,pn,cn,cnt,lcp,rev;
};

const int ADD = 500005;
int bal[500005];
vector<int> all[2 * ADD];

int tree[2000002];

void build(int i, int l, int r) {
  if (l == r) {
    tree[i] = bal[l];
    return;
  }
  int m = (l + r) >> 1;
  build(2 * i, l, m);
  build(2 * i + 1, m + 1, r);
  tree[i] = min(tree[2 * i], tree[2 * i + 1]);
}

int find(int i, int l, int r, int L, int R, int x) {
  if (l == L && r == R) {
    if (tree[i] >= x)
      return -1;

    if (l == r)
      return l;

    int m = (l + r) >> 1;
    if (tree[2 * i] < x)
      return find(2 * i, l, m, L, m, x);

    return find(2 * i + 1, m + 1, r, m + 1, R, x);
  }

  int m = (l + r) >> 1;
  if (R <= m) return find(2 * i, l, m, L, R, x);
  if (L > m) return find(2 * i + 1, m + 1, r, L, R, x);

  int ret = find(2 * i, l, m, L, m, x);
  if (ret != -1) return ret;

  return find(2 * i + 1, m + 1, r, m + 1, R, x);
}

int get(int x, int pos, int lst) {
  if (pos > lst && lst != -1) return 0;
  int p1 = lower_bound(all[x + ADD].begin(), all[x + ADD].end(), pos) - all[x + ADD].begin();
  int p2 = lower_bound(all[x + ADD].begin(), all[x + ADD].end(), lst) - all[x + ADD].begin();
  if (lst == -1) p2 = all[x + ADD].size();

  return p2 - p1;
}

int main() {
  int n;
  scanf("%d\n", &n);
  string s;
  getline(cin, s);

  for (int i = 0; i < s.size(); ++i) {
    if (i) bal[i] = bal[i - 1];
    bal[i] += s[i] == '(' ? 1 : -1;
    all[bal[i] + ADD].push_back(i);
  }

  SuffixArray arr(s);
  arr.build(true);
  // arr.output();

  build(1, 0, n - 1);

  long long ans = 0;
  for (int i = 1; i < arr.p.size(); ++i) {
    int pos = arr.p[i];
    int my = pos == 0 ? 0 : bal[pos - 1], lst = find(1, 0, n - 1, pos, n - 1, my);
    // cout << "Fnd: " << my << "  " << lst << " " << get(my, pos + arr.lcp[i], lst) << endl;
    ans += get(my, pos + arr.lcp[i], lst);
  }
  cout << ans << endl;

  return 0;
}