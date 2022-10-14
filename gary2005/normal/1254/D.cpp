/*
AuThOr Gwj
*/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define LL long long
#define IT iterator
#define PB push_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define KEEP while(1)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define debug_pair(A) cerr<<A.FIR<<" "<<A.SEC<<endl;
#define biggest(A,B) A=max(A,B)
#define smallest(A,B) A=min(A,B)
#define R(a) cin>>a
#define R2(a,b) cin>>a>>b
#define int LL
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
typedef pair<mp,mp> superpair;
const int MAXN=150000+20;
vector<int> g[MAXN];
LL val[MAXN];
int id[MAXN],maxi[MAXN],top[MAXN],siz[MAXN],fa[MAXN],heavy[MAXN],n;
const int MOD=998244353;
struct BIT{
	LL bit[MAXN+10]={0},n=MAXN;
	LL sum(LL i){
		LL s=0;
		while(i>0){
			s+=bit[i];
			s%=MOD;
			i-=i &(-i);
		}
		return s;
	}
	void add(int i,LL x=1){
		while(i<=n){
			bit[i]+=x;
			bit[i]%=MOD;
			i+= i&(-i);	
		}
	}
}bit;

void dfs(int now,int pre=0){
	fa[now]=pre;
	siz[now]=1;
	for(auto it:g[now]){
		if(it!=pre) dfs(it,now),siz[now]+=siz[it];
	}	
	for(auto it:g[now]){
		if(it!=pre&&siz[it]*2>=siz[now]){
			heavy[now]=it;
		} 
	}
}
int cnt=0;
LL inn;
void dfs2(int now,int pre=0){
	id[now]=++cnt;
	maxi[now]=id[now];
	if(heavy[now]){
		top[heavy[now]]=top[now];
		dfs2(heavy[now],now);
		maxi[now]=maxi[heavy[now]];
	}
	for(auto it:g[now]){
		if(it!=pre&&it!=heavy[now]){
			top[it]=it;
			dfs2(it,now);
			maxi[now]=maxi[it];
		}
	}
} 
LL quick(LL A,int B){
	if(!B) return 1;
	LL tmp=quick(A,B>>1);
	tmp*=tmp;
	tmp%=MOD;
	if(B&1)
	tmp*=A,tmp%=MOD;
	return tmp;
}
LL in(LL A){
	return quick(A,MOD-2);
}
void work(int y,LL d){
	if(heavy[y]){
		int v=heavy[y];
		int l,r;
		l=id[v];
		r=maxi[v];
		int z=n-siz[v];
		bit.add(l,d*z%MOD*inn%MOD);
		bit.add(r+1,MOD-d*z%MOD*inn%MOD);
	}
	val[y]+=d;
}
LL run(int x){
	LL res=bit.sum(id[x]);
	bool ok=0;
	int son=0;
	int now=x;
	while(now){
		if(ok){
			res+=val[now]*(n-siz[son])%MOD*inn%MOD;
			res%=MOD;
		}
		ok=1;
		son=top[now];
		now=fa[top[now]];
	}
	return res;
}
signed main(){
	fastio;
	int q;
	cin>>n;
	inn=in(n);
//	cout<<quick(2,2.)<<endl;
	cin>>q;
	rb(i,1,n-1) {
		int u,v;
		R2(u,v);
		g[u].PB(v);
		g[v].PB(u);
	}
	dfs(1);
	top[1]=1;
	dfs2(1);
	rep(K,q){
		int ty;
		R(ty);
		
		if(ty==1){
			int v;LL d;
		R2(v,d);
			bit.add(id[v],d%MOD);
			bit.add(id[v]+1,(MOD-d%MOD));
			if(v!=1){
				int l,r;
				l=id[v];
				r=maxi[v];
				if(l!=1){
					bit.add(1,d*siz[v]%MOD*inn%MOD);
					bit.add(l,(MOD-d*siz[v]%MOD*inn%MOD));
				}
				if(r!=n){
					bit.add(r+1,d*siz[v]%MOD*in(n)%MOD);
					bit.add(n+1,(MOD-d*siz[v]%MOD*inn%MOD));
				}
			}
			work(v,d);
		}
		else{
			int x;
			R(x);
			cout<<run(x)<<endl;
		}
	}
	return 0;
}


/*

5 12
1 2
1 3
2 4
2 5
1 1 1
2 1
2 2 
2 3
2 4


6 8
5 3
5 6
5 4
2 6
1 3
2 4
1 2 8
1 3 5
1 3 5
2 3
1 2 0
1 4 4
1 1 0
*/