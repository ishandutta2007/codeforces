#include<bits/stdc++.h>
using namespace std;

#define cout cerr
#define rep(i,a,b) for(ll i=(a);i<=(b);++i)
#define per(i,a,b) for(ll i=(a);i>=(b);--i)

typedef long long ll;
typedef pair<ll,ll> pii;
#define FR first
#define SE second

inline void rd(ll &x){
	x=0;char ch=getchar();ll f=1;
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	x*=f;
}

const ll inf=214748360000047ll;
ll n;
#define Maxn 1005
ll x[Maxn],y[Maxn],z[Maxn];
map
<pii,ll> mp;

ll d[Maxn<<1],head[Maxn<<1],cur[Maxn<<1],v[10005],nxt[10005],w[10005],tot=0;
	ll Q[Maxn<<1],hd,tl,S,T;
	bool Bfs(){
		for(ll i=0;i<tl;++i)d[Q[i]]=-1;
		hd=tl=0;
		Q[tl++]=S;d[S]=0;
		while(hd<tl){
			ll u=Q[hd];hd++;
			for(ll i=head[u];i;i=nxt[i])
				if(w[i]&&d[v[i]]<0){
					d[v[i]]=d[u]+1;
					Q[tl++]=v[i];
					if(v[i]==T)return true;
				}
		}
		return false;
	}
	ll find(ll u,ll flow){
		if(u==T||!flow)return flow;
		ll res=0,minv;
		for(ll &i=head[u];i;i=nxt[i])
			if(w[i]&&d[v[i]]==d[u]+1&&(minv=find(v[i],min(flow,w[i])))){
				w[i]-=minv;
				if(i&1)w[i+1]+=minv;
				else w[i-1]+=minv;
				res+=minv;
				flow-=minv;
				if(!flow)break;
			}
		return res;
	}
	void add_edge(ll s,ll e,ll t){
		tot++;v[tot]=e;w[tot]=t;nxt[tot]=head[s];head[s]=tot;
		tot++;v[tot]=s;w[tot]=0;nxt[tot]=head[e];head[e]=tot;
	}
	ll max_flow(){
		ll res=0;
		memcpy(cur,head,sizeof(ll)*(T+1));
		while(Bfs()){
			res+=find(S,inf);
			memcpy(head,cur,sizeof(ll)*(T+1));
		}
		return res;
	}

int main(){
	memset(d,-1,sizeof(d));
	rd(n);ll sum=0;
	rep(i,1,n){
		rd(x[i]);rd(y[i]);rd(z[i]);
		mp[make_pair(x[i],y[i])]=i;
		add_edge(i,i+n,z[i]);
		sum+=z[i];
	}
	S=2*n+1;T=2*n+2;
//	(1,0)(0,0) (0,1) (1,1)
	rep(i,1,n){
		ll _x=x[i]%2,_y=y[i]%2;
		if(_x&&(!_y)){
			add_edge(S,i,inf);
			rep(t,-1,1)
				if(t&&mp[pii(x[i]+t,y[i])])add_edge(i+n,mp[pii(x[i]+t,y[i])],inf);
		}
		if((!_x)&&(!_y)){
			rep(t,-1,1)
				if(t&&mp[pii(x[i],y[i]+t)])add_edge(i+n,mp[pii(x[i],y[i]+t)],inf);
		}
		if((!_x)&&_y){
			rep(t,-1,1)
				if(t&&mp[pii(x[i]+t,y[i])])add_edge(i+n,mp[pii(x[i]+t,y[i])],inf);
		}
		if(_x&&_y){
			add_edge(i+n,T,inf);
		}
	}
	printf("%lld\n",sum-max_flow());
	return 0;
}