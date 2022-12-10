#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cassert>
#include<map>
using namespace std;
int t,n;
long long a,b,s[1001],d[1001];
typedef pair<long long,long long> p2;
p2 fa[1001],fb[1001];
p2 f(p2 *tab,int n,long long x){
  if(n==0)return tab[0]=p2(0,0);
  if(n==1)return tab[1]=p2(x==2,x==1);
  p2 r;
  if(x<=s[n-1]){
    p2 r2=f(tab,n-1,x);
    r.first=min(r2.first,r2.second+2);
    r.second=min(r2.first,r2.second)+1+d[n-2];
  }else{
    p2 r2=f(tab,n-2,x-s[n-1]);
    r.first=r2.first+1;
    r.second=r2.second;
  }
  return tab[n]=r;
}
long long solve(int n,long long a,long long b){
  if(n==0)return 0;
  if(n==1)return a!=b;
  if(a>s[n-1])return solve(n-2,a-s[n-1],b-s[n-1]);
  if(b<=s[n-1]){
    long long r=solve(n-1,a,b);
    r=min(r,fa[n-1].first+fb[n-1].second+2);
    r=min(r,fa[n-1].second+fb[n-1].first+2);
    return r;
  }
  assert(a<=s[n-1]&&b>s[n-1]);
  return fb[n-2].first+1+min(fa[n-1].first,fa[n-1].second);
}
main(){
  ios_base::sync_with_stdio(false);
  cin>>t>>n;
  s[0]=1;
  s[1]=2;
  for(int i=2;i<=n;i++)s[i]=min(s[i-1]+s[i-2],1LL<<60);
  d[0]=0;
  d[1]=1;
  for(int i=2;i<=n;i++)d[i]=1+d[i-2];
  while(t--){
    cin>>a>>b;
    if(a>b)swap(a,b);
    n=min(n,100);
    f(fa,n,a);
    f(fb,n,b);
    cout<<solve(n,a,b)<<endl;
  }
}