/*
{
######################
#       Author       #
#        Gary        #
#        2021        #
######################
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
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
//inline int read(){
//    int x=0;
//    char ch=getchar();
//    while(ch<'0'||ch>'9'){
//        ch=getchar();
//    }
//    while(ch>='0'&&ch<='9'){
//        x=(x<<1)+(x<<3)+(ch^48);
//        ch=getchar();
//    }
//    return x;
//}
const int INF=2e9;
typedef pair<int,int> mp;
/*}
*/
const int MAXN=2e5+233;
int n,m;
map<int,int> g[MAXN];
int u[MAXN],v[MAXN],w[MAXN],s,val[MAXN];
bool app[1001][1001];
int fa[MAXN],id[MAXN];
int root(int u){
	return fa[u]=(fa[u]==u? u:root(fa[u]));
}
void merge(int u,int v){
	fa[root(u)]=root(v);
}
bool cmp(int A,int B){
	return w[A]<w[B];
}
vector<mp> treeedge;
vector<mp> zeroedge;
vector<int> otheredge;
bool fk=0;
LL MST1(){
	rb(i,1,n) fa[i]=i;
	memset(app,0,sizeof(app));
	rb(i,1,m) app[u[i]][v[i]]=app[v[i]][u[i]]=1;
	rb(i,1,n) rb(j,1,i-1) if(!app[i][j]) {
		if(root(i)==root(j)) return 1e18;
		merge(i,j);
		treeedge.PB(II(i,j));
		zeroedge.PB(II(i,j));
	}
	fk=1;
	LL tmp=0;
	rb(i,1,m) id[i]=i;
	sort(id+1,id+1+m,cmp);
	rb(i_,1,m){
		int i=id[i_];
		if(root(u[i])==root(v[i])){
			otheredge.PB(i);
			continue;	
		}
		merge(u[i],v[i]);
		treeedge.PB(II(u[i],v[i]));
		tmp+=w[i];
	}
	return tmp;
}
vector<int> G[MAXN];
int depth[MAXN];
int jmp[MAXN][18];
int num[MAXN];
LL wtf;
void dfs(int now,int pre){
	jmp[now][0]=pre;
	rb(i,1,17) jmp[now][i]=jmp[jmp[now][i-1]][i-1];
	for(auto it:G[now]) if(it!=pre){
		depth[it]=depth[now]+1;
		dfs(it,now);
	}
}
void dfs2(int now,int pre){
	for(auto it:G[now]) if(it!=pre){
		num[it]+=num[now];
		dfs2(it,now);
	}
}
int lca(int u,int v){
	if(depth[u]<depth[v]) swap(u,v);
	int dis=depth[u]-depth[v];
	rep(i,18) if((dis>>i)&1){
		u=jmp[u][i];
	}
	if(u==v) return u;
	rl(i,17,0) if(jmp[u][i]!=jmp[v][i]){
		u=jmp[u][i];
		v=jmp[v][i];
	}
	return jmp[u][0];
}
LL solve_special(){
	for(auto it:treeedge){
		G[it.FIR].PB(it.SEC);
		G[it.SEC].PB(it.FIR);
	}
	dfs(1,0);
	for(auto &it:zeroedge){
		if(depth[it.FIR]<depth[it.SEC]) swap(it.FIR,it.SEC);
		num[it.FIR]++;
	}
	dfs2(1,0);
	for(auto it:otheredge){
		int l=lca(u[it],v[it]);
		int _=num[u[it]]+num[v[it]]-2*num[l];
		if(_){
			return wtf+w[it];
		}
	}
	return 1e18;
}
LL MST2(){
	if(fk) return solve_special();
	set<mp> se;
	rb(i,2,n) se.insert(II(INF,i)),val[i]=INF;
	val[1]=0;
	se.insert(II(0,1));
	LL tmp=0;
	while(!se.empty()){
		mp now=*se.begin();
		tmp+=now.FIR;
		se.erase(se.begin());
		val[now.SEC]=0;
		for(auto ite=g[now.SEC].begin();ite!=g[now.SEC].end();ite++){
			if(ite->SEC<val[ite->FIR]){
				se.erase(II(val[ite->FIR],ite->FIR));
				val[ite->FIR]=ite->SEC;
				se.insert(II(val[ite->FIR],ite->FIR));
			}
		}
		for(auto ite=se.lower_bound(II(0,1e9));ite!=se.end();){
			if(g[now.SEC].find(ite->SEC)==g[now.SEC].end()){
				val[ite->SEC]=0;
				se.insert(II(0,ite->SEC));
				ite=se.erase(ite);
			}
			else{
				ite++;
			}
		}
	}
	return tmp;
}
int main(){
	scanf("%d%d",&n,&m);
	LL rest=1e18;
	rb(i,1,m){
		scanf("%d%d%d",&u[i],&v[i],&w[i]);
		g[u[i]][v[i]]=w[i];
		g[v[i]][u[i]]=w[i];
		s=s xor w[i];
	}
	if(n<=1e3) check_min(rest,(wtf=MST1())+s);
	check_min(rest,MST2());
	cout<<rest<<endl;
	return 0;
}