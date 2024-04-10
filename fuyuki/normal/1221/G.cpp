#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
#define rnt re int
#define re// register
#define I inline int
#define V inline void
#define ll long long int
#define isnum(ch) ('0'<=ch&&ch<='9')
#define FOR(i,a,b) for(rnt i=a;i<=b;i++)
#define ROF(i,a,b) for(rnt i=a;i>=b;i--)
#define gc (_op==_ed&&(_ed=(_op=_buf)+fread(_buf,1,100000,stdin),_op==_ed)?EOF:*_op++)
char _buf[100000],*_op(_buf),*_ed(_buf);
I getint(){
	rnt _s=0;re char _ch=gc;
	while(!isnum(_ch))_ch=gc;
	while(isnum(_ch))_s=_s*10+_ch-48,_ch=gc;
	return _s;
}
const int N=51,mod=998244353;
//V check(int&x){x-=mod,x+=x>>31&mod;}
int n,m;
int d[N],dfn[N],dp[1<<21];
ll e[N],a[N][N],ans,S;
V input(){
	n=getint(),m=getint();rnt x,y;
	FOR(_,1,m)x=getint(),y=getint(),a[x][y]=a[y][x]=1,d[x]++,d[y]++;
}
I two(rnt u){
	rnt out=1;
	FOR(i,1,n)if(a[u][i]){
		if(!dfn[i])dfn[i]=3-dfn[u],out&=two(i);
		else if(dfn[i]==dfn[u])out=0;
	}
	return out;
}
V init(){
	rnt cnt=0;ll flag;
	FOR(i,1,n)cnt+=d[i]==0;
	ans+=2ll<<cnt;
	ans-=(ll)(m==0)<<n,cnt=0,flag=1;
	FOR(i,1,n)if(!dfn[i])cnt++,dfn[i]=1,flag&=two(i);
	ans-=1ll<<cnt;
	ans+=flag<<cnt;
	ans+=1ll<<n;
	FOR(i,1,n)FOR(j,1,n)e[i]|=a[i][j]<<j-1;
}
V dfs1(rnt p,ll now,ll out){
	if(now&out)return;
	if(p==m+1)return void(dp[now]++);
	dfs1(p+1,now,out);
	dfs1(p+1,1ll<<p-1|now,out|e[p]);
}
V dfs2(rnt p,ll now,ll out){
	if(now&out)
		return;
	if(p==n+1){
//		cout<<now<<' '<<out<<'\n';
		return void(ans-=dp[(~out)&S]<<1);
	}
	dfs2(p+1,now,out);
	dfs2(p+1,1ll<<p-1|now,out|e[p]);
}
V work(){
	m=n>>1,S=(1<<m)-1;
//	cout<<ans<<'\n';
	dfs1(1,0,0);
	FOR(i,0,m-1)FOR(j,0,S)if(j>>i&1)
		dp[j]+=dp[j^(1<<i)];
//	FOR(i,0,S)cout<<dp[i]<<'\n'; 
	dfs2(m+1,0,0);
	cout<<ans;
}
int main(){
//	freopen("koishi.in","r",stdin);
//	freopen("koishi.out","w",stdout);
	input();
	init();
	work();
	return 0;
}