#include<algorithm>
#include<iostream>
#include<random>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 101
int T,N,M,a[MAXN][MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int getc(){char c=getchar();while(c!='.'&&c!='*'&&c!='o')c=getchar();return c=='.'?0:c=='*'?1:2;}
int main()
{
	T=get();
	while(T--)
	{
		N=get(),M=get();For(i,1,N)For(j,1,M)a[i][j]=getc();
		For(j,1,M){int pos=-1;FOR(i,N,1)if(a[i][j]==0)pos=max(pos,i);else if(a[i][j]==1){if(pos!=-1)a[pos][j]=1,a[i][j]=0,pos--;}else pos=-1;}
		For(i,1,N){For(j,1,M)cout<<(a[i][j]==0?'.':a[i][j]==1?'*':'o');cout<<'\n';}
	}
}