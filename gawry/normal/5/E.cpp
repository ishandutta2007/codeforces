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

#define MAX 1100000
int n,t[MAX];
long long ans;
int prev[MAX],next[MAX];
main(){
  scanf("%d",&n);
  for(int i=0;i<n;i++)scanf("%d",&t[i]);
  int m=*max_element(t,t+n),cnt=0;FOR(i,n)cnt+=t[i]==m;
  ans=(int64)cnt*(cnt-1)/2;
  vector<vi> fragments;
  vi tmp;
  int start=0,cur;while(t[start]!=m)start++;
  cur=start;
  while(1){
    if(t[cur]==m){
      if(tmp.size())fragments.push_back(tmp);
      tmp.clear();
    }else tmp.push_back(t[cur]);
    cur=(cur+1)%n;
    if(cur==start)break;
  }
  if(tmp.size())fragments.push_back(tmp);
//  FOR(i,fragments.size()){FOR(j,fragments[i].size())cout<<fragments[i][j]<<" ";cout<<endl;}
//  cout<<ans<<endl;
  FOR(k,fragments.size()){
    const vi &t=fragments[k];
    typedef pair<int,int> p2;
    vector<p2> s;
    FOR(i,t.size()){
      while(!s.empty()&&s.back().first<t[i])ans+=s.back().second,s.pop_back(); 
      if(!s.empty()){
        ans+=s.back().first==t[i]?s.back().second:min(1,s.back().second);
        if(s.back().first==t[i]&&s.size()>1)ans+=min(s[s.size()-2].second,1);
      }
      if(!s.empty()&&s.back().first==t[i])s.back().second++;else s.push_back(p2(t[i],1));
    }
    FOR(i,t.size())prev[i]=next[i]=0;
    int best=t[0];
    prev[0]=1;
    FOR(i,t.size())if(i&&best<=t[i]){
      prev[i]=1;
      best=t[i];
    }
    best=t.back();
    next[t.size()-1]=1;
    for(int i=t.size()-2;i>=0;i--)if(best<=t[i]){
      next[i]=1;
      best=t[i]; 
    }
    bool same=t.size()+1==n;
    FOR(i,t.size())ans+=same?prev[i]||next[i]:prev[i]+next[i];
  }
  cout<<ans<<endl;
}