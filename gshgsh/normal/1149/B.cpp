#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 200001
#define MAXL 280
int N,M,a[MAXN],nxt[MAXN][26],c[4],s[4][MAXL],f[MAXL][MAXL][MAXL];
int main()
{
	cin>>N>>M;For(i,1,N){char c;cin>>c;a[i]=c-'a';}For(i,0,25)nxt[N+1][i]=nxt[N+2][i]=N+1;FOR(i,N,1){For(j,0,25)nxt[i][j]=nxt[i+1][j];nxt[i][a[i]]=i;}
	For(t,1,M)
	{
		char opt;int x;cin>>opt;cin>>x;
		if(opt=='+')
		{
			char t;cin>>t;int v=t-'a';s[x][++c[x]]=v;
			if(x==1)For(i,0,c[2])For(j,0,c[3])
			{
				f[c[1]][i][j]=nxt[f[c[1]-1][i][j]+1][v];
				if(i)f[c[1]][i][j]=min(f[c[1]][i][j],nxt[f[c[1]][i-1][j]+1][s[2][i]]);
				if(j)f[c[1]][i][j]=min(f[c[1]][i][j],nxt[f[c[1]][i][j-1]+1][s[3][j]]);
			}
			else if(x==2)For(i,0,c[1])For(j,0,c[3])
			{
				f[i][c[2]][j]=nxt[f[i][c[2]-1][j]+1][v];
				if(i)f[i][c[2]][j]=min(f[i][c[2]][j],nxt[f[i-1][c[2]][j]+1][s[1][i]]);
				if(j)f[i][c[2]][j]=min(f[i][c[2]][j],nxt[f[i][c[2]][j-1]+1][s[3][j]]);
			}
			else For(i,0,c[1])For(j,0,c[2])
			{
				f[i][j][c[3]]=nxt[f[i][j][c[3]-1]+1][v];
				if(i)f[i][j][c[3]]=min(f[i][j][c[3]],nxt[f[i-1][j][c[3]]+1][s[1][i]]);
				if(j)f[i][j][c[3]]=min(f[i][j][c[3]],nxt[f[i][j-1][c[3]]+1][s[2][j]]);
			}
		}
		else c[x]--;
		if(f[c[1]][c[2]][c[3]]==N+1)cout<<"NO\n";else cout<<"YES\n";
	}
	return 0;
}