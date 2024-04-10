#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 100001
int T,N,a[MAXN];bool vis[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int main()
{
	T=get();
	while(T--)
	{
		N=get();For(i,1,N)a[i]=get(),vis[i]=0;For(i,1,N)if(a[i]<=N)vis[a[i]]=1;sort(a+1,a+N+1);
		vector<int>b,c;For(i,1,N)if(!vis[i])b.push_back(i);For(i,1,N)if(a[i]>N||!vis[a[i]])c.push_back(a[i]-1>>1);else vis[a[i]]=0;
		int M=b.size();bool flag=1;For(i,0,M-1)if(b[i]>c[i]){flag=0;break;}cout<<(flag?M:-1)<<'\n';
	}
	return 0;
}