#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 200001
int T,N;struct A{ll a,b;bool operator<(A x)const{return a>x.a;};}a[MAXN];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
int main(){T=get();while(T--){N=get();For(i,1,N)a[i].a=get();For(i,1,N)a[i].b=get();sort(a+1,a+N+1);ll ans=a[1].a,sum=a[1].b;For(i,2,N)ans=min(ans,max(a[i].a,sum)),sum+=a[i].b;ans=min(ans,sum);cout<<ans<<endl;}return 0;}