#include<bits/stdc++.h>
#define rep(i,a,b) for(int i=(a);i<=(b);i++)
#define per(i,a,b) for(int i=(a);i>=(b);i--)
#define REP(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
using namespace std;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef long long ll;
 
inline char gc(){
	static char buf[100000],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,100000,stdin),p1==p2)?EOF:*p1++;
}
template<class T> inline void read(T &x){
	int f=0;x=0;char ch=gc();
	for(;!isdigit(ch);ch=gc())f|=(ch=='-');
	for(;isdigit(ch);ch=gc())x=x*10+ch-'0';
	if(f)x=-x;
}
 
const int N=200005,L=10,M=750;
namespace OwO{
	int e[N][L];vi rev[N][L];
	int bel[N],mark[N],cnt[N];
	int n,m,sz,owo,del[N];
	vi s[N];int q[N],inq[N],r;
	void init(int _n,int _m,int _sz){ n=_n,owo=m=_m,sz=_sz,r=0; }
	void add(int u,int v,int c){ e[u][c]=v,rev[v][c].pb(u); }
	void set(int u,int p){ s[p].pb(u),bel[u]=p; }
	void push(int k){ q[++r]=k,inq[k]=1; }
	void split(int k){
		m+=2,++owo,del[k]=1;
        int flag=(cnt[k]<=s[k].size()/2?1:0);
		for(auto u:s[k])
			if(mark[u]==flag) s[m].pb(u),bel[u]=m;
            else s[m-1].pb(u),bel[u]=m-1;
		if(inq[k])push(m-1); else push(m);
	}
	#define For(k,t,x) for(auto OwQ:s[k]) for(auto x:rev[OwQ][t])
	int stk[N],top;
	void solve(){
		rep(i,2,m) push(i);
		while(r){
			int k=q[r--];inq[k]=0;
			REP(t,sz){
				For(k,t,x) cnt[bel[x]]++,mark[x]=1;
				For(k,t,x) if(cnt[bel[x]]<s[bel[x]].size())
					stk[++top]=bel[x];
				for(;top;top--) if(!del[stk[top]])
					split(stk[top]);
				For(k,t,x) mark[x]=cnt[bel[x]]=0;
			}
		}
	}
}
 
typedef bitset<73> bits;
unordered_map<bits,int> id;
int trans[M][L],w[M];
int val[N],cnt,S,tot;
int dfs(bits st){
	int k=id[st];
	if(k) return k;
	if(!k) id[st]=k=++cnt;
	OwO::set(k,val[k]=st._Find_first());
	assert(val[k]<=9);
	REP(c,10){
		bits aim=(st<<c)|(st>>c);
		for(int i=0;i<c;i++)
			if(st[i]) aim.set(abs(i-c));
		OwO::add(k,dfs(aim),c);
	}
	return k;
}
void init(){
	bits st; st[0]=1,dfs(st);
	OwO::init(cnt,10,10);
	OwO::solve();
	unordered_map<int,int> cur;
	rep(i,1,cnt){
		int x=OwO::bel[i];
		if(!cur[x]) cur[x]=++tot;
	}
	S=cur[OwO::bel[1]];
	rep(i,1,cnt){
		int u=cur[OwO::bel[i]]; w[u]=val[i];
		REP(c,10) trans[u][c]=cur[OwO::bel[OwO::e[i][c]]];
	}
}
 
ll f[20][10][M][10];
void prepare(){
	rep(i,1,tot) f[0][9][i][w[i]]=1;
	rep(i,1,19)rep(j,0,9)rep(s,1,tot)rep(t,0,9)
		f[i][j][s][t]=(j?f[i][j-1][s][t]:0)+f[i-1][9][trans[s][j]][t];
	rep(i,1,19)rep(j,0,9)rep(s,1,tot)rep(t,1,9)
		f[i][j][s][t]+=f[i][j][s][t-1];
}
 
int num[20],len;
ll solve(ll x,int k){
	for(len=0;x;x/=10) num[++len]=x%10;
	ll ans=0; int s=S;
	per(i,len,1){
		if(num[i]) ans+=f[i][num[i]-1][s][k];
		s=trans[s][num[i]];
	}
	return ans;
}
 
int main(){
	init(),prepare();
	int Q; read(Q);
	while(Q--){
		ll l,r; int k;
		read(l),read(r),read(k);
		printf("%lld\n",solve(r+1,k)-solve(l,k));
	}	
	return 0;
}