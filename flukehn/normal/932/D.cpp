#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=(a),i##_end=(b);i<=i##_end;++i)
#define For(i,a,b) for(int i=(a),i##_end=(b);i<i##_end;++i)
#define per(i,a,b) for(int i=(b),i##_st=(a);i>=i##_st;--i)
#define foe(i,a) for(__typeof(a.begin()) i=a.begin();i!=a.end();++i)
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define dbg(x) cerr<<#x" = "<<x<<endl
#define debug(...) fprintf(stderr, __VA_ARGS__)
#define Es(x,i) for(Edge *i=G[x];i;i=i->nxt)
typedef long long ll;
typedef pair<int,int> pii;
const int inf=~0u>>1,mod=1e9+7;
inline ll rd() {
    ll x;char c,f=1;while(!isdigit(c=getchar()))f=c!='-';x=c-'0';
    while(isdigit(c=getchar()))x=x*10+c-'0';return f?x:-x;
}
const int N=400011,M=21;
struct __Orz__{
	int ap[N][M];
	ll mv[N][M],sv[N][M];
	__Orz__(){}
	inline void ins(int fa,int u,ll y){
		ap[u][0]=fa;
		mv[u][0]=sv[u][0]=y;
		for(int k=0;ap[u][k];++k){
			int v=ap[u][k];
			ap[u][k+1]=ap[v][k];
			mv[u][k+1]=max(mv[u][k],mv[v][k]);
			sv[u][k+1]=sv[u][k]+sv[v][k];
		}
	}
	inline int q(int u,ll y){
		u=ap[u][0];
		per(k,0,M-1){
			if(!ap[u][k])continue;
			if(mv[u][k]<y)u=ap[u][k];
		}
		return sv[u][0]>=y?u:0;
	}
	inline int Q(int u,ll y){
		int ans = 0;
		per(k,0,M-1)if(ap[u][k]){
			if(sv[u][k]<=y) {
				y-=sv[u][k];
				u=ap[u][k];
				ans+=1<<k;
			}
		}
		return ans+=(sv[u][0]<=y);
	}
}a,b;
int cnt=1;
ll lst;
inline void add(int x,ll y){
	++cnt;
	a.ins(x,cnt,y);
	int o=a.q(cnt,y);
	b.ins(o,cnt,y);
}
int main(){
	int Q=rd();
	while(Q--){
		int op=rd();
		ll R=lst^rd(),W=lst^rd();
		if(op==1)
			add(R,W);
		else{
			printf("%lld\n",lst=b.Q(R,W));
		}
	}
}