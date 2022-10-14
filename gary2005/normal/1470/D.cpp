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
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
int fa[300000+20];
int root(int x){
	if(fa[x]==x) return x;
	return fa[x]=root(fa[x]);
}
vector<int> g[300000+20];
void solve(){
	int n,m;
	scanf("%d%d",&n,&m);
	rb(i,1,n) fa[i]=i,g[i].clear();
	rb(i,1,m){
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].PB(v);
		g[v].PB(u); 
		fa[root(u)]=root(v);
	}
	rb(i,1,n){
		if(root(i)!=root(1)){
			printf("NO\n");
			return;
		}
	}
	printf("YES\n");
	set<int> unused;
	rb(i,1,n) if(i!=1) unused.insert(i);
	set<int> can;
	can.insert(1);
	vector<int> rest;
	while(!can.empty()){
		int now=*can.begin();
		can.erase(can.begin());
		rest.PB(now);
		vector<int> nn;
		for(auto it:g[now]){
			if(unused.find(it)!=unused.end()){
				unused.erase(it);
				nn.PB(it);
			}
			if(can.find(it)!=can.end()){
				can.erase(it);
				nn.PB(it);
			}
		}
		for(auto it:nn){
			for(auto itt:g[it]){
				if(unused.find(itt)!=unused.end()){
					can.insert(itt);
					unused.erase(itt);
				}
			}
		}
	}
	assert(unused.empty());
	printf("%d\n",rest.size());
	for(auto it:rest) printf("%d ",it);
	printf("\n");
}
int main(){
	int t;
	scanf("%d",&t);
	while(t--) solve();
	return 0;
}