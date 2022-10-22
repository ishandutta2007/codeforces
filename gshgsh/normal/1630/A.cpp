#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 1<<16
int T,N,K,mat[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int main()
{
	T=get();
	while(T--)
	{
		N=get(),K=get();if(N==4&&K==3){cout<<"-1\n";continue;}For(i,0,N-1)mat[i]=N-1-i;
		if(K)
		{
			if(K<N-1)mat[N-1-K]=0,mat[K]=N-1,mat[N-1]=K,mat[0]=N-1-K;
			else mat[0]=N>>1,mat[N>>1]=0,mat[1]=N-1>>1,mat[N-1>>1]=1,mat[N-2]=N-1,mat[N-1]=N-2;
		}
		For(i,0,N-1)if(i<mat[i])cout<<i<<' '<<mat[i]<<'\n';
	}
	return 0;
}