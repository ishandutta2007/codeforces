#include<cstring>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<vector>
#include<numeric>
#include<map>
#include<set>
#include<cstdlib>
#include<string>
#include<cassert>
#include<iostream>
using namespace std;
typedef vector<int> vi;
typedef long long int64;
#define FOR(i,n)for(int i=0;i<(int)(n);i++)
struct STedge;
typedef pair<int,int> p2;
vector<p2> intervals;
struct STvertex{
  map<char,STedge> g;
  STvertex *f;
  int numer,cnt[3];
  void traverse(int);
};
struct STedge{
  int l,r;
  STvertex *v;
};
const int MOD=1000000007;
const int MAX=310000;
int delta[MAX];
STvertex *r;
const char *t;
void STvertex::traverse(int depth=0){
  cnt[0]=cnt[1]=cnt[2]=0;
  if(numer>-1){
    int pos=0;
    while(pos<3&&!(intervals[pos].first<=numer&&numer<=intervals[pos].second))++pos;
 //   cout<<path<<" "<<pos<<endl;
    if(pos<3)++cnt[pos];
    return;
  }
  for(map<char,STedge>::iterator it=g.begin();it!=g.end();it++){
    STedge &tmp=it->second;
/*    string path2=path;
    for(int i=tmp.l;i<=tmp.r;i++)path2+=t[i];*/
    tmp.v->traverse(depth+tmp.r-tmp.l+1);
    for(int i=0;i<3;i++)cnt[i]+=tmp.v->cnt[i];
    if(tmp.v->cnt[0]&&tmp.v->cnt[1]&&tmp.v->cnt[2]){
      int mult=(long long)tmp.v->cnt[0]*tmp.v->cnt[1]%MOD*tmp.v->cnt[2]%MOD;
      int len=tmp.r-tmp.l+1;
      delta[depth+1]=(delta[depth+1]+mult)%MOD;
      delta[depth+len+1]=(delta[depth+len+1]+MOD-mult)%MOD;
//      for(int i=depth+1;i<=depth+len;i++){
//        ans[i]=(ans[i]+mult)%MOD;
//      }
    }
  }
}
int l;
void Canonize(STedge &kraw, const char *x){
  if (kraw.l <= kraw.r){
    STedge e = kraw.v->g[x[kraw.l]];
    while (e.r - e.l <= kraw.r - kraw.l){
      kraw.l += e.r - e.l + 1;
      kraw.v = e.v;
      if (kraw.l <= kraw.r) e = kraw.v->g[x[kraw.l]];
    }
  }
}
bool Test_and_split(STvertex* &w, const STedge &kraw){
  w = kraw.v;
  if (kraw.l <= kraw.r){
    char c = t[kraw.l];
    STedge e = kraw.v->g[c];
    if (t[kraw.r + 1] == t[e.l + kraw.r - kraw.l + 1]) return true;
    w = new STvertex; w->numer = -1;
    kraw.v->g[c].r = e.l + kraw.r - kraw.l;
    kraw.v->g[c].v = w;
    e.l += kraw.r - kraw.l + 1;
    w -> g[t[e.l]] = e;
    return false;
  } 
  return kraw.v->g.find(t[kraw.l]) != kraw.v->g.end();
}
void Update(STedge &kraw, int n){
  STvertex *oldr = r, *w;
  while (!Test_and_split(w, kraw)){
    STedge e;
    e.v = new STvertex; e.l = kraw.r + 1; e.r = n - 1;
    e.v->numer = l++;
    w->g[t[kraw.r + 1]] = e;
    if (oldr != r) oldr->f = w;
    oldr = w;
    kraw.v = kraw.v->f;
    Canonize(kraw, t);
  }
  if (oldr != r) oldr->f = kraw.v;
}
STvertex* Create_suffix_tree(const char *x, int n){
  STvertex *top;
  STedge e;
  top = new STvertex; r = new STvertex; t = x;
  top->numer = r->numer = -1;
  e.v = r; l = 0;
  for (int i=0; i<n; ++i){
    e.r = -i; e.l = -i; top->g[x[i]] = e;
  }
  r->f = top;
  e.l = 0; e.v = r;
  FOR(i,n){
    e.r = i - 1; Update(e, n); 
    e.r++; Canonize(e, x);
  }
  return r;
}
char s1[MAX],s2[MAX],s3[MAX];
int main(){
  scanf("%s %s %s",s1,s2,s3);
  string x;
  x+=s1;
  x+='#';
  x+=s2;
  x+='$';
  x+=s3;
  x+='&';
  intervals.push_back(p2(0,strlen(s1)-1));
  intervals.push_back(p2(strlen(s1)+1,strlen(s1)+1+strlen(s2)-1));
  intervals.push_back(p2(strlen(s1)+1+strlen(s2)+1,x.size()-2));
/*  cout<<x<<endl;
string tmp[3];
for(int i=0;i<3;i++)for(int j=intervals[i].first;j<=intervals[i].second;j++)tmp[i]+=x[j];
cout<<tmp[0]<<endl<<tmp[1]<<endl<<tmp[2]<<endl;*/
  int n=x.size();
  STvertex *r = Create_suffix_tree(x.c_str(), n);
  r->traverse();
  int len=min(strlen(s1),min(strlen(s2),strlen(s3)));
  int cur=0;
  for(int i=1;i<=len;i++){
    cur=(cur+delta[i])%MOD;
    printf("%d%c",cur,i<len?' ':'\n');
  }
  return 0;
}