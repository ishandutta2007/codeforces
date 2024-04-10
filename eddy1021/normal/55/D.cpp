#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int b[20],s[5555],m[555][10],M[555][10],L[5555][10];
ll d[20][55][555];
ll D(int n,int x,int l,int f){
  if(n<0)return x%l==0;
  if(!f&&~d[n][s[l]][x]) return d[n][s[l]][x];
  ll r=0;
  for(int i=0,u=f?b[n]:9;i<=u;i++)
    r+=D(n-1,n?m[x][i]:M[x][i],L[l][i],f&&(i==u));
  return f?r:d[n][s[l]][x]=r;
}
ll c(ll x){
  int i=0; while(x) b[i++]=x%10,x/=10;
  return D(i-1,0,1,1);
}
int main(){
  memset(d,-1,sizeof(d));
  int i,j,id=0;
  for(i=0;i<=252;i++)
    for(j=0;j<10;j++){
      M[i][j]=i*10+j; m[i][j]=M[i][j]%252;
    }
  for(i=0;i<=2520;i++){
    if(i&&2520%i==0)s[i]=id++;
    for(j=0;j<10;j++)L[i][j]=j?i*j/__gcd(i,j):i;
  }
  int _;scanf("%d",&_);while(_--){
    ll l,r;
    scanf("%lld%lld",&l,&r);
    printf("%lld\n",c(r)-c(l-1));
  }
}