#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <memory.h>
#include <sstream>
#include <cmath>
#include <ctime>

using namespace std;

char str[1000006];

struct SuffixArray{
  SuffixArray(string _s) {
    initialize(_s);
  };
  void initialize(string _s = "") {
   s=_s;//+"$";
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

int bal[1000006];
int pref[1000006];
int suf[1000006];

int main() {
  gets(str);
  int n = strlen(str);

  SuffixArray sufa(str);
  sufa.build();
  // for (int i = 0; i < n; ++i) {
  //   cout << suf.p[i] << endl;
  // }
  int open = 0, cl = 0;
  for (int i = 0; i < n; ++i) {
    bal[i] += str[i] == '(' ? 1 : -1;
    if (i) bal[i] += bal[i - 1]; 
    if (str[i] == '(') ++open;
    else ++cl;
  }
  for (int i = 0; i < n; ++i) {
    pref[i] = bal[i];
    if (i) pref[i] = min(pref[i], pref[i - 1]);
  }
  for (int i = n - 1; i >= 0; --i) {
    suf[i] = bal[i];
    if (i + 1 < n) suf[i] = min(suf[i], suf[i + 1]);
  }
  int mx = -100000000;
  for (int i = 0; i < n; ++i) {
    int total = 0;
    total = min(suf[i] - (i > 0 ? bal[i - 1] : 0), 0);
    total = min(bal[n - 1] - (i > 0 ? bal[i - 1] : 0) + (i > 0 ? pref[i - 1] : 0), total);
    mx = max(mx, total);
  }

  // cout << mx << " " << mn << endl;
  string s = "";
  for (int i = 0; i < n; ++i) {
    int ind = sufa.p[i];
    int total = 0;
    total = min(suf[ind] - (ind > 0 ? bal[ind - 1] : 0), 0);
    total = min(bal[n - 1] - (ind > 0 ? bal[ind - 1] : 0) + (ind > 0 ? pref[ind - 1] : 0), total);
    if (total == mx) {
      s = string(-total, '(');
      for (int j = 0; j < n; ++j)
        s += str[(ind + j) % n];
      int add = -total + open - cl;
      if (add > 0)
        s += string(add, ')');
      break;
    }
  }
  printf("%s\n", s.c_str());
  return 0;
}