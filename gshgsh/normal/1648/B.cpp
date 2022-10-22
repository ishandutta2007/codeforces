#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 1000001
int T,N,K,a[MAXN],c[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int main()
{
	T=get();
	while(T--)
	{
		N=get(),K=get();For(i,1,K)c[i]=0;For(i,1,N)c[a[i]=get()]++;if(!c[1]){cout<<"No\n";continue;}For(i,1,K)c[i]+=c[i-1];
		bool flag=1;For(i,1,K)if(c[i]!=c[i-1])For(j,1,K/i)if(c[j]==c[j-1]){int l=i*j,r=min(K,i*j+i-1);if(c[r]!=c[l-1])flag=0;}
		cout<<(flag?"Yes\n":"No\n");
	}
	return 0;
}