#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<sstream>
#include<string>
#include<vector>
#include<set>
#include<map>
#include<numeric>
#include<cmath>
using namespace std;

typedef long long int64;
typedef pair<int,int> p2;
typedef vector<int> vi;

#define ALL(t) t.begin(),t.end()
#define FOR(i,n) for (int i=0; i<(n); i++)
#define FOREACH(i,t) for (typeof(t.begin()) i=t.begin(); i!=t.end(); i++)

template<typename T,typename TT> ostream &operator<<(ostream &s,pair<T,TT> t) {return s<<"("<<t.first<<","<<t.second<<")";}
template<typename T> ostream &operator<<(ostream &s,vector<T> t){s<<"{";FOR(i,t.size())s<<t[i]<<(i==t.size()-1?"":",");return s<<"}"<<endl; }

#define MAX 1100000
int n,m,gcd[110][110],lcm[110][110],d[MAX],cnt[110],sgn[110],add[110],deg[110],r[110];
typedef pair<int,int> p2;
typedef pair<p2,p2> p4;
map<int,vector<p4> > a;
typedef pair<int,p2> p3;
vector<p3> s[110];
vi q;
void dfs(int x,int cur_sgn=1,int cur_add=0){
  q.push_back(x);
  sgn[x]=cur_sgn;
  add[x]=cur_add;
  FOR(i,s[x].size())if(!sgn[s[x][i].first]){
    dfs(s[x][i].first,-cur_sgn,s[x][i].second.first+s[x][i].second.second-cur_add);
  }
}
int main() {
  for(int i=2;i<MAX;i++)d[i]=i;
  for(int i=2;i*i<MAX;i++)if(d[i]==i)for(int j=i*i;j<MAX;j+=i)d[j]=i;
  scanf("%d %d",&n,&m);
  FOR(i,m){
    int x,y;
    scanf("%d %d",&x,&y);
    --x;--y;
    scanf("%d %d",&gcd[x][y],&lcm[x][y]);
    gcd[y][x]=gcd[x][y];
    lcm[y][x]=lcm[x][y];
    int tmp=lcm[x][y],tmp2=gcd[x][y];
    if(tmp%tmp2)goto fail;
    while(tmp>1){
      int cnt=0,cnt2=0,div=d[tmp];
      while(tmp%div==0)++cnt,tmp/=div;
      while(tmp2%div==0)++cnt2,tmp2/=div;
      if(cnt<cnt2)goto fail;
      a[div].push_back(p4(p2(x,y),p2(cnt2,cnt)));
    }
    ++deg[x];
    ++deg[y];
  }
  FOR(i,n)r[i]=1;
  for(map<int,vector<p4> >::iterator it=a.begin();it!=a.end();it++){
    FOR(i,n)s[i].clear(),sgn[i]=0;
    int prime=it->first;
//    cout<<"prime="<<prime<<endl;
    vector<p4> &t=it->second;
    FOR(i,t.size()){
//    cout<<t[i]<<endl;
      s[t[i].first.first].push_back(p3(t[i].first.second,t[i].second));
      s[t[i].first.second].push_back(p3(t[i].first.first,t[i].second));
    }
    FOR(i,n)if(!sgn[i]){
      q.clear();
      dfs(i);
      FOR(cur_cnt,20){
        FOR(j,q.size())cnt[q[j]]=sgn[q[j]]*cur_cnt+add[q[j]];
        //cout<<cur_cnt<<"?"<<endl;FOR(i,q.size())cout<<q[i]<<"->"<<cnt[q[i]]<<endl;
        bool ok=true;
        FOR(j,q.size())ok&=!cnt[q[j]]||deg[q[j]]==s[q[j]].size();
        FOR(j,q.size())FOR(k,s[q[j]].size()){
          int x=q[j],y=s[x][k].first;
          ok&=min(cnt[x],cnt[y])==s[q[j]][k].second.first;
          ok&=max(cnt[x],cnt[y])==s[q[j]][k].second.second;
        }
        if(!ok)continue;
        FOR(j,q.size())FOR(k,cnt[q[j]])r[q[j]]*=prime;
        goto next;
      }
      goto fail;
next:;
    }
  }
  cout<<"YES"<<endl;
  FOR(i,n){
    cout<<r[i];
    if(i+1<n)cout<<" ";else cout<<endl;
  }
  return 0;
fail:
  cout<<"NO"<<endl;
  return 0;
}