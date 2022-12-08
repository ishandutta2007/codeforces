#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MAXL=1<<22,dx[4]={1,-1,0,0},dy[4]={0,0,1,-1};
char i_str[MAXL],*i_s,*i_t;
char gc() {
	if(i_s==i_t) {
		i_s=i_str;
		i_t=i_s+fread(i_str,1,MAXL,stdin);
		return i_s==i_t?EOF:*i_s++;
	} else return *i_s++;
}
int read() {
	int x=0,f=0;
	char ch=gc();
	for(;ch<'0'||ch>'9';ch=gc())
		if(ch=='-')f=1;
	for(;ch>='0'&&ch<='9';ch=gc())
		x=x*10+(ch^48);
	return f?-x:x;
}
int add[110][110],a[110][110],n,m;
void dfs(int x,int y,int d) {
	add[x][y]=d;
	for(int i=0;i<4;i++) {
		int xx=x+dx[i],yy=y+dy[i];
		if(xx<1||xx>n||yy<1||yy>m||~add[xx][yy])continue;
		if(a[xx][yy]==a[x][y])dfs(xx,yy,d^1);
		else if(d==1&&a[xx][yy]==a[x][y]+1)dfs(xx,yy,d);
		else if(d==0&&a[xx][yy]==a[x][y]-1)dfs(xx,yy,d);
	}
}
signed main() {
	int T=read();
	while(T--) {
		memset(add,-1,sizeof(add));
		n=read(),m=read();
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				a[i][j]=read();
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
				if(!~add[i][j])dfs(i,j,0);
		for(int i=1;i<=n;i++) {
			for(int j=1;j<=m;j++)
				printf("%d ",a[i][j]+add[i][j]);
			puts("");
		}
	}
	return 0;
}