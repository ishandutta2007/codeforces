#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 501
int N,M,ans[MAXN][MAXN];
int New(int x,int y){For(i,1,26)if(ans[x-1][y]!=i&&ans[x][y-1]!=i&&ans[x+1][y]!=i&&ans[x][y+1]!=i)return i;return 0;}
bool check(int x,int y,int l)
{
	if(x+l-1>N)return 0;if(y>1&&ans[x+l-1][y-1]==ans[x][y])return 0;if(x>1&&ans[x-1][y+l-1]==ans[x][y])return 0;
	For(i,y,y+l-1)if(ans[x+l-1][i])return 0;For(i,x,x+l-1)if(ans[i][y+l-1])return 0;
	if(x+l-1<N)For(i,y,y+l-1)if(ans[x+l][i]==ans[x][y])return 0;if(y+l-1<M)For(i,x,x+l-1)if(ans[i][y+l]==ans[x][y])return 0;return 1;
}
void solve(int x,int y,int l,int c){For(i,x,x+l-1)For(j,y,y+l-1)ans[i][j]=c;}
int main()
{
	cin>>N>>M;int pre=0;
	For(i,1,N)
	{
		For(j,1,M)
		if(!ans[i][j])
		{
			int tmp=New(i,j);if(tmp<ans[i][pre])ans[i][j]=tmp,pre=j;
			else if(pre&&check(i,pre,j-pre+1))solve(i,pre,j-pre+1,ans[i][pre]);
			else ans[i][j]=New(i,j),pre=j;
		}
		else pre=0;
		pre=0;
	}
	For(i,1,N){For(j,1,M)cout<<char(ans[i][j]-1+'A');cout<<'\n';}return 0;	
}