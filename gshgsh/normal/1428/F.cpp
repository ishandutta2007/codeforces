#include<iostream>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 500001
int N,a[MAXN],f[MAXN];ll ans;
int main(){cin>>N;For(i,1,N){char c;cin>>c;a[i]=c-'0';f[i]=N+1;}int len=0;ll sum=0;FOR(i,N,1){if(a[i])len++,sum+=f[len]-i;else while(len)f[len]=i+len,len--;ans+=sum;}cout<<ans<<endl;return 0;}