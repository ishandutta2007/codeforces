#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 100001
int T,N,K,a[MAXN],b[MAXN],pos[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int main()
{
	T=get();
	while(T--)
	{
		N=get(),K=get();For(i,1,N)a[i]=b[i]=get();sort(b+1,b+N+1);For(i,1,N)a[i]=lower_bound(b+1,b+N+1,a[i])-b,pos[a[i]]=i;
		int cnt=0;For(i,1,N){cnt++;while(i<N&&a[i+1]==a[i]+1)i++;}
		cout<<(cnt<=K?"YES\n":"NO\n");
	}
	return 0;
}