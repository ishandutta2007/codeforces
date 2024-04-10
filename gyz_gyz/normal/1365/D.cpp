#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int>pii;
const int N=1e6+10;
const int inf=1e9;
const int mo=1e9+7;
const int u0[]={0,1,0,-1};
const int u1[]={1,0,-1,0};
char s[99][99];bool v[99][99];
void dfs(int x,int y){
	if(s[x][y]=='#'||v[x][y])return;
	v[x][y]=1;
	rep(k,0,3)dfs(x+u0[k],y+u1[k]);
}
void sol(){int n,m;
	scanf("%d%d",&n,&m);
	rep(i,1,n)rep(j,1,m)v[i][j]=0;
	rep(i,1,n)scanf("%s",s[i]+1);
	rep(i,0,m+1)s[0][i]=s[n+1][i]='#';
	rep(i,0,n+1)s[i][0]=s[i][m+1]='#';	
	rep(i,1,n)rep(j,1,m)if(s[i][j]=='B')rep(k,0,3){
		int x=i+u0[k],y=j+u1[k];
		if(s[x][y]=='G'){
			printf("No\n");return;
		}
		if(s[x][y]!='B')s[x][y]='#';
	}
	dfs(n,m);
	rep(i,1,n)rep(j,1,m)if(s[i][j]=='G'&&!v[i][j]){
		printf("No\n");return;
	}
	printf("Yes\n");
}
int main(){int t;
	scanf("%d",&t);
	rep(i,1,t)sol();
}