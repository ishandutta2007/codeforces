#include<cstdio>
#include<algorithm>
#include<iostream>
#include<sstream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<numeric>
#include<cmath>
#include<cstring>
using namespace std;

#define ALL(t) t.begin(),t.end()
#define FOR(i,n) for (int i=0;i<(int)(n);i++)
#define FOREACH(i,t) for (typeof(t.begin())i=t.begin();i!=t.end();i++)
typedef vector<int> vi;
typedef long long int64;

#define MOD 1000000009
int n,m,next[210][4],a[210][21],aa[210][21],longest[210];
string s[21];
main(){
  cin>>n>>m;
  FOR(i,m)cin>>s[i];
  vector<string> t;
  FOR(i,m)FOR(j,s[i].size()+1)t.push_back(s[i].substr(0,j));
  sort(t.begin(),t.end());
  t.erase(unique(t.begin(),t.end()),t.end());
  map<string,int> nr;
  FOR(i,t.size())nr[t[i]]=i;
  char b[4]={'A','C','G','T'};
  FOR(i,t.size())FOR(k,4){
    string tmp=t[i]+b[k];
    while(nr.find(tmp)==nr.end())tmp=tmp.substr(1);
    next[i][k]=nr[tmp];
//    cout<<t[i]<<" "<<b[k]<<" -> "<<t[next[i][k]]<<endl;
  }
  set<string> all(s,s+m);
  FOR(i,t.size())for(int j=1;j<=t[i].size();j++)if(all.count(t[i].substr(t[i].size()-j)))longest[i]=j;
  a[0][0]=1;
  FOR(nn,n){
    memset(aa,0,sizeof(aa));
    FOR(i,t.size())FOR(j,t[i].size()+1)if(a[i][j])FOR(k,4){
      int ii=next[i][k],jj=j+1;
      if(longest[ii]>=jj)jj=0;
      if(jj>t[ii].size())continue;
      aa[ii][jj]+=a[i][j];
//cout<<t[i]<<" "<<j<<" "<<b[k]<<" -> "<<t[ii]<<" "<<jj<<endl;
      if(aa[ii][jj]>=MOD)aa[ii][jj]-=MOD;
    }
    memcpy(a,aa,sizeof(a));
  }
  int r=0;
  FOR(i,t.size())r=(r+a[i][0])%MOD;
  printf("%d\n",r);
}