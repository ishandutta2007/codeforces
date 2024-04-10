#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 100001
int T,N,M,x[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int main()
{
	T=get();
	while(T--)
	{
		N=get(),M=get();int k=0;For(i,1,N)For(j,1,M)x[++k]=max(i-1,N-i)+max(j-1,M-j);
		sort(x+1,x+k+1);For(i,1,k)cout<<x[i]<<" \n"[i==k];
	}
	return 0;
}