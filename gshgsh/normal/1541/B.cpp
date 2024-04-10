#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 100001
int T,N,a[MAXN],pos[MAXN*2];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
int main()
{
	T=get();
	while(T--)
	{
		N=get();For(i,1,N*2)pos[i]=0;For(i,1,N)pos[a[i]=get()]=i;
		int ans=0;For(i,1,N*2)if(pos[i])for(int j=i;j<=N*2;j+=i)ans+=pos[j/i]>pos[i]&&pos[j/i]+pos[i]==j;
		cout<<ans<<endl;
	}
	return 0;
}