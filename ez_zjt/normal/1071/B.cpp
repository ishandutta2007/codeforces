#include <bits/stdc++.h>
#define MAXN 2010
using namespace std;

int n,m;
char s[MAXN][MAXN];
int g[MAXN][MAXN];

void gao(int ans){
	static int h[MAXN*MAXN][2],nh;
	if(!ans){
		h[nh=1][0]=1;
		h[nh=1][1]=1;
		putchar(s[1][1]);
	}
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			int cost=i+j-1-g[i][j];
			if(cost<=m && i+j-1==ans){
				h[++nh][0]=i;
				h[nh][1]=j;
			}
		}
	while(ans--) putchar('a');
	int last=0;
	while(1){
		int cur=nh;
		char minc='z'+1;
		for(int i=last+1;i<=cur;i++){
			int x=h[i][0],y=h[i][1];
			if(x+1<=n) minc=min(minc,s[x+1][y]);
			if(y+1<=n) minc=min(minc,s[x][y+1]);
		}
		if(minc=='z'+1) break;
		putchar(minc);
		for(int i=last+1;i<=cur;i++){
			int x=h[i][0],y=h[i][1];
			if(y+1<=n && s[x][y+1]==minc && (h[nh][0]!=x || h[nh][1]!=y+1)) h[++nh][0]=x,h[nh][1]=y+1;
			if(x+1<=n && s[x+1][y]==minc && (h[nh][0]!=x+1 || h[nh][1]!=y)) h[++nh][0]=x+1,h[nh][1]=y;
		}
		last=cur;
	}
	return;
}

int main(){
#ifdef DEBUG
	freopen("B.in","r",stdin);
#endif
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++) scanf("%s",s[i]+1);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			g[i][j]=max(g[i-1][j],g[i][j-1])+(s[i][j]=='a');
	int ans1=0;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++){
			int cost=i+j-1-g[i][j];
			if(cost<=m)
				ans1=max(ans1,i+j-1);
		}
	gao(ans1);
}