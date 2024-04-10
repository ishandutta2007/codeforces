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
const int MAX=110000;
int n,m,v[MAX],p[MAX],s[MAX];
typedef pair<int,int> p2;
p2 t[MAX];
bool cmp(p2 x,p2 y){
  return min(v[x.first],v[x.second])>min(v[y.first],v[y.second]);
}
int find(int x){
  return p[x]==x?x:p[x]=find(p[x]);
}
void join(int x,int y){
  s[x]+=s[y];
  p[y]=x;
}
int main(){
  scanf("%d %d",&n,&m);
  for(int i=1;i<=n;i++)scanf("%d",&v[i]),p[i]=i,s[i]=1;
  FOR(i,m)scanf("%d %d",&t[i].first,&t[i].second);
  sort(t,t+m,cmp);
  long double ans=0.0;
  FOR(i,m){
    int x=t[i].first,y=t[i].second,cost=min(v[x],v[y]);
    x=find(x);
    y=find(y);
    if(x==y)continue;
//    cout<<s[x]<<" "<<s[y]<<" "<<cost<<endl;
    ans+=(long double)cost*s[x]*s[y];
    join(x,y);
  }
  printf("%.6lf\n",(double)(ans*2/n/(n-1)));
  return 0;
}