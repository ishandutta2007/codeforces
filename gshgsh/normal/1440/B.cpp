#include<iostream>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 200001
int T,N,K,a[MAXN];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
int main(){T=get();while(T--){N=get(),K=get();int f=(N+1)/2-1;ll ans=0;For(i,1,N*K)a[i]=get();for(int i=f*K+1;i<=N*K;i+=N-f)ans+=a[i];cout<<ans<<endl;}return 0;}