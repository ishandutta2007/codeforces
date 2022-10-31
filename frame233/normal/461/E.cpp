#include<bits/stdc++.h>
const int N=100005;typedef long long ll;ll m;
template <typename _Tp>inline void chmin(_Tp &a,const _Tp &b){a=a<b?a:b;}
struct mat{
	ll a[4][4];
	mat(){memset(a,63,sizeof(a));}
	inline mat operator * (const mat &o){
		mat c;for(int i=0;i<4;++i)for(int k=0;k<4;++k)for(int j=0;j<4;++j)chmin(c.a[i][j],a[i][k]+o.a[k][j]);
		return c;
	}
}M,pw[63];
char s[N];int ch[N*20][4],A,nc;
void ins(char *s,int len){for(int u=0,i=0,v;i<len;++i){v=s[i]-'A';if(!ch[u][v])ch[u][v]=++nc;u=ch[u][v];}}
void dfs(int x,int d){for(int i=0;i<4;++i)if(ch[x][i])dfs(ch[x][i],d+1);else chmin(M.a[A][i],(ll)d);}
int main(){
	scanf("%lld%s",&m,s+1);int n=strlen(s+1);
	for(int i=1;i<=n;++i)ins(s+i,std::min(n-i+1,20));
	for(int a=0;a<4;++a){
		for(int b=0;b<4;++b)M.a[a][b]=1e18;
		A=a,dfs(ch[0][a],1);
	}
	pw[0]=M;for(int i=1;i<60;++i)pw[i]=pw[i-1]*pw[i-1];
	mat cur;for(int i=0;i<4;++i)cur.a[0][i]=0;
	ll ans=0;
	for(int i=59;i>=0;--i){
		mat tmp=cur*pw[i];
		if(std::min({tmp.a[0][0],tmp.a[0][1],tmp.a[0][2],tmp.a[0][3]})<m)cur=tmp,ans+=1LL<<i;
	}
	printf("%lld\n",ans+1);
	return 0;
}