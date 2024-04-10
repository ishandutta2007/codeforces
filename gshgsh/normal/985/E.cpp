#include<algorithm>
#include<iostream>
#include<cstdio>
#include<queue>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 500001
int N,K,d,a[MAXN],q[MAXN],h,t,f[MAXN];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
int main()
{
	N=get(),K=get(),d=get();For(i,1,N)a[i]=get();sort(a+1,a+N+1);f[0]=1;q[h=t=1]=0;
	For(i,K,N){while(h<=t&&a[i]-a[q[h]+1]>d)h++;f[i]=h<=t?f[q[h]]:0;while(h<=t&&f[q[t]]<f[i-K+1])t--;q[++t]=i-K+1;}cout<<(f[N]?"YES\n":"NO\n");return 0;
}