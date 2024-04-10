#include<iostream>
#include<cstdio>
#include<cstring>
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

#define MAX 3010
typedef pair<int,int> p2;
int c,n,m,k,x,y,z,prev[MAX][MAX];
vi s[MAX];
vector<p2> t[MAX];
main() {
  scanf("%d %d %d",&n,&m,&k);
  FOR(i,m){
    scanf("%d %d",&x,&y);
    s[x].push_back(y);
    s[y].push_back(x);
  }
  FOR(i,k){
    scanf("%d %d %d",&x,&y,&z);
    t[y].push_back(p2(x,z));
  }
  FOR(i,n)sort(t[i+1].begin(),t[i+1].end());
  vector<p2> q(1,p2(0,1));
  memset(prev,-1,sizeof(prev));
  prev[0][1]=0;
  FOR(i,q.size()){
    int x=q[i].first,y=q[i].second;
    if(y==n){
      vi r;
      while(y!=1){
        r.push_back(y);
        int z=prev[x][y];
        y=x;
        x=z;
      }
      printf("%d\n1",r.size());
      FOR(i,r.size())printf(" %d",r[r.size()-1-i]);
      puts("");
      return 0;
    }
    FOR(j,s[y].size())if(prev[y][s[y][j]]==-1){
      vector<p2>::iterator it=lower_bound(t[y].begin(),t[y].end(),p2(x,s[y][j]));
      if(it!=t[y].end()&&*it==p2(x,s[y][j]))continue;
      prev[y][s[y][j]]=x;
      q.push_back(p2(y,s[y][j]));
    }
  }
  puts("-1");
  return 0;
}