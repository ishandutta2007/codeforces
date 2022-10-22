#include<iostream>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 100001
int T,N,x,a[MAXN];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
int main(){T=get();while(T--){N=get(),x=get();ll sum=0,ans=0;For(i,1,N)sum+=a[i]=get(),ans+=(a[i]+x-1)/x;cout<<(sum+x-1)/x<<' '<<ans<<endl;}return 0;}