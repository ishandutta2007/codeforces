#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 100001
int T,N,a[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int main()
{
	T=get();
	while(T--)
	{
		N=get();For(i,1,N)a[i]=get();sort(a+1,a+N+1);
		if(a[1]>=2){cout<<"YES\n";continue;}
		if(a[N]==0||*lower_bound(a+1,a+N+1,1)!=1){cout<<"YES\n";continue;}
		if(a[1]==0){cout<<"NO\n";continue;}
		bool flag=1;For(i,2,N)if(a[i]-a[i-1]==1){flag=0;break;}cout<<(flag?"YES\n":"NO\n");
	}
}