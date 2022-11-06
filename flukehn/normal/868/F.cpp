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
const int inf=~0u>>1,MOD=1e9+7;//*
char *TT,*mo,but[(1<<15)+2];
#define getchar() ((TT==mo&&(mo=((TT=but)+fread(but,1,1<<15,stdin)),TT==mo))?-1:*TT++)//*/
inline int rd() {
	int x,c,f=1;while(!isdigit(c=getchar()))f=c!='-';x=c-'0';
	while(isdigit(c=getchar()))x=x*10+c-'0';return f?x:-x;
}
const int N=1e5+11;
ll f[22][N],ans;
int n,K,a[N],cnt[N];
#define pp pair<pii,pii>
inline void add(int x){ans+=cnt[a[x]]++;}
inline void del(int x){ans-=--cnt[a[x]];}
void solve(int d){
	static pp q[N];
	int h=0,t=0,cl=1,cr=0;ans=0;
	q[t++]=mp(mp(1,n),mp(0,n));
	f[d][0]=0;
	memset(cnt+1,0,sizeof(int)*n);
	while(h<t){
		pp g=q[h++];
//		cerr << g.x.x << " " << g.x.y << endl;
		int m=g.x.x+g.x.y>>1;
		int R=min(g.y.y,m);
		while(cr<m)add(++cr);
		while(cl>R+1)add(--cl);
		while(cr>m)del(cr--);
		while(cl<R+1)del(cl++);
		int rr=0; ll FF=1e18;
		per(i,R,g.y.x){
			ll F=f[d-1][i]+ans;
			if(F<FF)FF=F,rr=i;
			if(i!=g.y.x)add(--cl);
		}
		f[d][m]=FF;
		if(g.x.x<m)q[t++]=mp(mp(g.x.x,m-1),mp(g.y.x,rr));
		if(g.x.y>m)q[t++]=mp(mp(m+1,g.x.y),mp(rr,g.y.y));
		/*if(g.fi.fi<m)
			qs[t++]=make_pair(pii(g.fi.fi,m-1),pii(g.se.fi,rr));
		if(m<g.fi.se)
			qs[t++]=make_pair(pii(m+1,g.fi.se),pii(rr,g.se.se));*/
	}
}
int main(){
#ifdef flukehn
	freopen("test.txt","r",stdin);
#endif
//	int n=rd();
	memset(f,127/3,sizeof f);
	n=rd(),K=rd();
	f[0][0]=0;
	rep(i,1,n)a[i]=rd();
	rep(i,1,K)solve(i);
	printf("%lld\n",f[K][n]);
}