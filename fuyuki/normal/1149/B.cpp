#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
#define I inline int
#define V inline void
#define B inline bool
#define re register
#define FOR(i,a,b) for(re int i=a;i<=b;i++)
#define ROF(i,a,b) for(re int i=a;i>=b;i--)
char _buf[100000],*_op(_buf),*_ed(_buf);
B isnum(char ch){return '0'<=ch&&ch<='9';}
B isaplph(char ch){return 'a'<=ch;}
I getint(){
	int s=0;char ch=gc;
	while(!isnum(ch))ch=gc;
	while(isnum(ch))s=s*10+ch-48,ch=gc;
	return s;
}
const int N=251,INF=0x7fffffff;
char st[N*400],a[N],b[N],c[N];
int n,q,dp[N][N][N],la,lb,lc;
int nxt[N*400][26];
V input(){
	n=getint(),q=getint();
	char ch=gc;
	while(!isalpha(ch))ch=gc;
	FOR(i,1,n)st[i]=ch,ch=gc;
	FOR(i,0,250)FOR(j,0,250)FOR(k,0,250)dp[i][j][k]=INF;
	FOR(i,0,25)nxt[n+1][i]=INF;
}
V init(){ROF(i,n,0)FOR(j,0,25)nxt[i][j]=(j==st[i+1]-'a')?i+1:nxt[i+1][j];}
V dfs(int x,int y,int z){
	if(x&&dp[x-1][y][z]<n)dp[x][y][z]=min(nxt[dp[x-1][y][z]][a[x]-'a'],dp[x][y][z]);
	if(y&&dp[x][y-1][z]<n)dp[x][y][z]=min(nxt[dp[x][y-1][z]][b[y]-'a'],dp[x][y][z]);
	if(z&&dp[x][y][z-1]<n)dp[x][y][z]=min(nxt[dp[x][y][z-1]][c[z]-'a'],dp[x][y][z]);
}
V work(){
	char opt,ch;int X;
	dp[0][0][0]=0;
	FOR(_,1,q){
		opt=gc;
		while(opt!='+'&&opt!='-')opt=gc;
		X=getint();
		switch(opt){
			case '+':{
				char ch=gc;while(!isalpha(ch))ch=gc;
				switch(X){
					case 1:a[++la]=ch;FOR(i,0,lb)FOR(j,0,lc)dfs(la,i,j);break;
					case 2:b[++lb]=ch;FOR(i,0,la)FOR(j,0,lc)dfs(i,lb,j);break;
					case 3:c[++lc]=ch;FOR(i,0,la)FOR(j,0,lb)dfs(i,j,lc);break;
				}
				break;
			}
			case '-':{
				switch(X){
					case 1:FOR(i,0,lb)FOR(j,0,lc)dp[la][i][j]=INF;la--;break;
					case 2:FOR(i,0,la)FOR(j,0,lc)dp[i][lb][j]=INF;lb--;break;
					case 3:FOR(i,0,la)FOR(j,0,lb)dp[i][j][lc]=INF;lc--;break;
				}
				break;
			}
		}
		if(dp[la][lb][lc]<INF)cout<<"YES\n";
		else cout<<"NO\n";
	}
}
int main(){
	input();
	init();
	work();
	return 0;
}