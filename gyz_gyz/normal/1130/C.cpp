#include<bits/stdc++.h>
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define pb push_back
#define N 300010
#define mo 998244353
using namespace std;
typedef long long ll;
const int u1[]={0,1,0,-1};
const int u2[]={1,0,-1,0};
int v[61][61];char s[61][61];
int dis(int a,int b,int c,int d){
	return (a-c)*(a-c)+(b-d)*(b-d);
}
void dfs(int x,int y,int z){v[x][y]=z;
	rep(i,0,3){
		int p=x+u1[i],q=y+u2[i];
		if(s[p][q]=='0'&&!v[p][q])dfs(p,q,z);
	}
}
int main(){int n,sx,sy,tx,ty;
	scanf("%d%d%d%d%d",&n,&sx,&sy,&tx,&ty);
	rep(i,1,n)scanf("%s",s[i]+1);
	dfs(sx,sy,1);
	if(v[tx][ty])return printf("0\n"),0;
	dfs(tx,ty,2);int ans=dis(sx,sy,tx,ty);
	rep(i,1,n)rep(j,1,n)if(v[i][j]==1)
		rep(k,1,n)rep(l,1,n)if(v[k][l]==2)
			ans=min(ans,dis(i,j,k,l));
	printf("%d\n",ans);
}