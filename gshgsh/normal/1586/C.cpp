#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 1000001
int N,M,Q,sum[MAXN];vector<int>a[MAXN];
int getc(){char c=getchar();while(c!='.'&&c!='X')c=getchar();return c=='.';}
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int main()
{
	N=get(),M=get();For(i,1,N){a[i].resize(M+1);For(j,1,M)a[i][j]=getc();}
	For(i,1,N-1)For(j,2,M)sum[j]+=!a[i][j]&&!a[i+1][j-1];For(i,1,M)sum[i]+=sum[i-1];
	Q=get();while(Q--){int l=get(),r=get();cout<<(sum[r]==sum[l]?"YES\n":"NO\n");}return 0;
}