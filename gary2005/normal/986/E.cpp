/*
{
######################
#       Author       #
#        Gary        #
#        2020        #
######################
*/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define LL long long
#define PB push_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define rep(a,b) for(int a=0;a<b;++a)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
vector<mp> split(int num){
	vector<mp> ret;
	for(int i=2;i*i<=num;++i){
		if(num%i==0){
			int cnt=0;
			while(num%i==0){
				++cnt;
				num/=i;
			}
			ret.PB({i,cnt});
		}
	}
	if(num!=1) ret.PB({num,1});
	return ret;
}
const int MAXN=1e5+20;
vector<mp> a[MAXN];
int n,q;
vector<int> g[MAXN];
int fa[MAXN][17];
map<mp,int> cnt2;
const int MOD=1000000007;
LL quick(LL A,LL B){
	if(B==0) return 1;
	LL  tmp=quick(A,B>>1);
	tmp*=tmp;
	tmp%=MOD;
	if(B&1)
		tmp*=A,tmp%=MOD;
 	return tmp;
}
LL inv(LL A) {return quick(A,MOD-2);}
int rest[MAXN],depth[MAXN],cnt[10000000+1],X[MAXN];
vector<int> query[MAXN];
void dfs(int now,int pre){
	fa[now][0]=pre;
	rb(i,1,16) fa[now][i]=fa[fa[now][i-1]][i-1];
	for(auto it:g[now]) if(it!=pre){depth[it]=depth[now]+1;dfs(it,now);}
}
int lca(int u,int v){
	if(depth[u]<depth[v]) swap(u,v);
	int need=depth[u]-depth[v];
	rep(i,17) if((need>>i)&1) u=fa[u][i];	
	if(u==v) return u;
	rl(i,16,0) if(fa[u][i]!=fa[v][i]){u=fa[u][i],v=fa[v][i];}
	return fa[u][0];
}
int get(int x){
	int rest=1;
	vector<mp> v=split(x);
	for(auto it:v){
		int have=cnt[it.FIR];
		int tot=0;
		rep(i,it.SEC) tot+=i*cnt2[II(it.FIR,i)],have-=cnt2[II(it.FIR,i)];
		tot+=have*it.SEC;
		rest=1ll*rest*quick(it.FIR,tot)%MOD;
	}
	return rest;
}
void run(int now,int pre){
	for(auto it:a[now]){
		cnt[it.FIR]++;cnt2[it]++;
	}
	for(auto it:query[now]){
		int tmp=get(X[abs(it)]);
		if(it<0) rest[-it]=inv(tmp)*rest[-it]%MOD;
		else rest[it]=1ll*tmp*rest[it]%MOD;
	}
	for(auto it:g[now]) if(it!=pre) run(it,now);
	for(auto it:a[now]){
		cnt[it.FIR]--;cnt2[it]--;
	}
}
int main(){
	scanf("%d",&n);
	rb(i,1,n-1){
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].PB(v);
		g[v].PB(u);
	}
	dfs(1,0);
	rb(i,1,n){
		int ai;
		scanf("%d",&ai);
		a[i]=split(ai);	
	} 
	scanf("%d",&q);
	rb(i,1,q){
		int u,v;rest[i]=1;
		scanf("%d%d%d",&u,&v,&X[i]);
		int lca_=lca(u,v);
		query[u].PB(i),query[v].PB(i),query[lca_].PB(-i),query[fa[lca_][0]].PB(-i);
	}
	run(1,0);
	rb(i,1,q) printf("%d\n",rest[i]);
	return 0;
}