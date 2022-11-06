#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a),i##_end=(b);i<=i##_end;i++)
#define per(i,b,a) for(int i=(b),i##_st=(a);i>=i##_st;i--)
#define x first
#define y second
#define pb push_back
#define mp make_pair
#define debug(x) cerr<<#x" = "<<x<<endl
#define Debug(...) fprintf(stderr, __VA_ARGS__)
#define Es(x,i) for(Edge *i=G[x];i;i=i->nxt)
typedef pair<int,int> pii;
typedef long long ll;
const int inf=~0u>>1,MOD=998244353;/*
char *TT,*mo,but[(1<<15)+2];
#define getchar() ((TT==mo&&(mo=((TT=but)+fread(but,1,1<<15,stdin)),TT==mo))?-1:*TT++)//*/
inline int rd() {
	int x,c,f=1;while(!isdigit(c=getchar()))f=c!='-';x=c-'0';
	while(isdigit(c=getchar()))x=x*10+c-'0';return f?x:-x;
}
ll pw(ll n,ll m){
	ll ret=1;
	while(m){
		if(m&1)ret=ret*n%MOD;
		n=n*n%MOD,m>>=1;
	}
	return ret;
}
const int N=5004;
ll f[N][N];
ll solve(int a,int b){
	memset(f,0,sizeof f);
	f[0][b]=1;
	rep(i,1,a){
		f[i][b]=f[i-1][b];
		rep(j,b-i,b-1){
			f[i][j]=(f[i-1][j]+f[i-1][j+1]*(j+1))%MOD;
		}
	}
	ll ret=0;
	rep(i,b-a,b)ret+=f[a][i];
	return ret%MOD;
}
int main(){
	ll a=rd(),b=rd(),c=rd();
	if(a>b)swap(a,b);
	if(a>c)swap(a,c);
	if(b>c)swap(b,c);
	printf("%lld\n",solve(a,b)*solve(a,c)%MOD*solve(b,c)%MOD);
	return 0;
}