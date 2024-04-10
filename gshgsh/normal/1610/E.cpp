#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 200001
int T,N,a[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int main()
{
	T=get();
	while(T--)
	{
		N=get();For(i,1,N)a[i]=get();int ans=0;
		For(i,1,N)if(a[i]!=a[i-1]){int p=i,cnt=0;while(p<=N)cnt++,p=lower_bound(a+p+1,a+N+1,a[p]*2-a[i])-a;ans=max(ans,cnt);}
		cout<<N-ans<<'\n';
	}
	return 0;
}