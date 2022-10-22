#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 51
int N,M,E[MAXN][MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
bool check(int a,int b,int c,int d,int e){int cnt=E[a][b]+E[a][c]+E[a][d]+E[a][e]+E[b][c]+E[b][d]+E[b][e]+E[c][d]+E[c][e]+E[d][e];return cnt==0||cnt==10;}
int main()
{
	N=min(get(),50),M=get();For(i,1,M){int u=get(),v=get();if(u<=N&&v<=N)E[u][v]=E[v][u]=1;}
	For(a,1,N)For(b,a+1,N)For(c,b+1,N)For(d,c+1,N)For(e,d+1,N)if(check(a,b,c,d,e)){cout<<a<<' '<<b<<' '<<c<<' '<<d<<' '<<e<<'\n';return 0;}cout<<"-1\n";return 0;
}