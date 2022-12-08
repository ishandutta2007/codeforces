#include<bits/stdc++.h>
using namespace std;
#define bh(x,y) ((x-1)*m+y)
const int N=510,dx[4]={1,0,-1,0},dy[4]={0,1,0,-1};
char s[N][N];
int col[N*N];
vector<int>S[N*N];
void dfs(int x,int f) {
	col[x]=f;
	for(int y:S[x])
		if(col[y]==-1)dfs(y,f^1);
}
int main() {
	memset(col,-1,sizeof(col));
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%s",s[i]+1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++) {
			if(s[i][j]=='.')continue;
			int cnt=0,lx=0,ly;
			for(int k=0;k<4;k++) {
				int x=i+dx[k],y=j+dy[k];
				if(s[x][y]=='.') {
					cnt++;
					if(cnt%2==0) {
						S[bh(lx,ly)].push_back(bh(x,y));
						S[bh(x,y)].push_back(bh(lx,ly));
					}
					lx=x,ly=y;
				}
			}
			if(cnt&1) {
				puts("NO");
				return 0;
			}
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(s[i][j]=='.'&&col[bh(i,j)]==-1)
				dfs(bh(i,j),0);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(s[i][j]=='.')col[bh(i,j)]=col[bh(i,j)]?1:4;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			if(s[i][j]=='X') {
				col[bh(i,j)]=0;
				for(int k=0;k<4;k++) {
					int x=i+dx[k],y=j+dy[k];
					if(s[x][y]=='.')col[bh(i,j)]+=col[bh(x,y)];
				}
			}
	puts("YES");
	for(int i=1;i<=n;i++) {
		for(int j=1;j<=m;j++)
			printf("%d ",col[bh(i,j)]);
		puts("");
	}
	return 0;
}