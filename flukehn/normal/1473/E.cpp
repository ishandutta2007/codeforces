#include<bits/stdc++.h>
using namespace std;
#define For(i,a,b) for(int i=a,i##_end=b;i<i##_end;++i)
using ll=long long;
using pii=pair<int,int>;
#define fi first
#define se second
#define mp make_pair
#define pb push_back
const int mo=998244353;
int Pow(int a,int b,int p=mo){int r=1;for(;b;b>>=1,a=1ll*a*a%p)if(b&1)r=1ll*r*a%p;return r;}
//template<typename T>
void inc(int &x,int y){x=(x+y>=mo?x+y-mo:x+y);}
template<typename T>T gcd(T a,T b){while(b)a%=b,swap(a,b);return a;}
template<typename T>int upmn(T &x,T y){return x>y?x=y,1:0;}
mt19937 rnd(time(0));
ll sqr(int x){return 1ll*x*x;}
const int N=2e5+11,M=(N<<2)+11;

vector<pii> e[N];
int n,m;
using pli=pair<ll,int>;
priority_queue<pli,vector<pli>,greater<pli> >q;
ll f[M];
int vis[M];
#define U(x,y) if(upmn(f[x],y))q.push(mp(y,x))
int main(){
#ifdef SGR
	freopen("a.txt","r",stdin);
#endif
	ios::sync_with_stdio(0);
	cin>>n>>m;
	For(i,0,m){
		int u,v,w;
		cin>>u>>v>>w;
		e[u].pb(mp(v,w));
		e[v].pb(mp(u,w));
	}
	memset(f,0x3f,sizeof f);
	f[4]=0;
	q.push(mp(0LL,4));
	while(!q.empty()){
		auto w=q.top();q.pop();
		int x=w.se;
		if(vis[x])continue;
		vis[x]=1;
		int o=x%4;
		for(auto z:e[x>>2]){
			int y=z.fi<<2;
			ll wi=f[x]+z.se;
			U(y|o,wi);
			if(~o&1)U(y|o|1,wi-z.se);
			if(~o>>1&1)U(y|o|2,wi+z.se);
			if(!o)U(y|3,wi);
		}
	}
	For(i,2,n+1)cout<<f[i<<2|3]<<" \n"[i==n];
}