#include<bits/stdc++.h>
#define rep(i,x,y) for(auto i=(x);i<=(y);++i)
#define dep(i,x,y) for(auto i=(x);i>=(y);--i)
#define fr first
#define sc second
using namespace std;
typedef long long ll;
const int N=1e3+10;
const int inf=1e9;
const char u0[]="RLUD";
const int u1[]={0,0,1,-1};
const int u2[]={-1,1,0,0};
int n,xi[N][N],yi[N][N];char c[N][N];
void dfs(int x,int y){
	rep(i,0,3){
		int X=x+u1[i],Y=y+u2[i];
		if(X&&Y&&X<=n&&Y<=n&&!c[X][Y]&&
		xi[x][y]==xi[X][Y]&&yi[x][y]==yi[X][Y]){
			c[X][Y]=u0[i];dfs(X,Y);
		}
	}
}
int main(){
	scanf("%d",&n);
	rep(i,1,n)rep(j,1,n)scanf("%d%d",&xi[i][j],&yi[i][j]);
	rep(i,1,n)rep(j,1,n)if(xi[i][j]==i&&yi[i][j]==j){
		c[i][j]='X';dfs(i,j);
	}
	rep(i,1,n)rep(j,1,n)if(!c[i][j]&&~xi[i][j]){
		printf("INVALID\n");return 0;
	}
	rep(x,1,n)rep(y,1,n)if(!c[x][y]){bool fl=0;
		rep(i,0,3){
			int X=x+u1[i],Y=y+u2[i];
			if(X&&Y&&X<=n&&Y<=n&&!c[X][Y]){
				fl=1;c[X][Y]=u0[i];c[x][y]=u0[i^1];
				dfs(X,Y);dfs(x,y);break;
			}
		}
		if(!fl){
			printf("INVALID\n");return 0;
		}
	}
	printf("VALID\n");
	rep(i,1,n){
		rep(j,1,n)printf("%c",c[i][j]);printf("\n");
	}
}