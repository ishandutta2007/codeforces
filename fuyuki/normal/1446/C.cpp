#include<bits/stdc++.h>
using namespace std;
#define I inline int
#define V inline void
#define ll long long int
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define ROF(i,a,b) for(int i=a;i>=b;i--)
#define REP(u) for(int i=h[u],v;v=e[i].t,i;i=e[i].n)
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
I getint(){
	int _s=0,_f=1;char _ch=gc;
	while(!isnum(_ch))(_ch=='-')&&(_f=-1),_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s*_f;
}
const int N=2e5+1,mod=998244353;
V check(int&x){x-=mod,x+=x>>31&mod;}
V cmax(int&x,int y){if(x-y>>31)x=y;}
V cmin(int&x,int y){if(y-x>>31)x=y;}
int n,rt,tot,now,a[N],ch[N<<5][2],siz[N<<5],dp[N<<5];
vector<int>e[N];
V add_edge(int x,int y){
	e[x].push_back(y),e[y].push_back(x);
}
V input(){
	n=getint();
	FOR(i,1,n)a[i]=getint();
}
V ins(int&p,int x,int l){
	if(!p)p=++tot;
	siz[p]++;
	if(!~l)return;
	ins(ch[p][x>>l&1],x,l-1);
}
V init(){
	tot=rt=1;
	FOR(i,1,n)ins(rt,a[i],30);
}
#define lc ch[p][0]
#define rc ch[p][1]
V dfs(int p,int l){
	if(!~l)return void(dp[p]=0);
	dp[p]=n;
	if(lc)dfs(lc,l-1),cmin(dp[p],dp[lc]+max(0,siz[rc]-1));
	if(rc)dfs(rc,l-1),cmin(dp[p],dp[rc]+max(0,siz[lc]-1));
}
V work(){
	dfs(rt,30);
	cout<<dp[rt];
}
int main(){
//	freopen("test.in","r",stdin);
//	freopen(".out","w",stdout);
//	for(scanf("%d",&T);T--;){
		input();
		init();
		work();
//	}
	return 0;
}