/*
{
######################
#       Author       #
#        Gary        #
#        2020        #
######################
*/
//#pragma GCC target ("avx2")
//#pragma GCC optimization ("O3")
//#pragma GCC optimization ("unroll-loops")
#pragma GCC optimize(2)
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
#define R(a) cin>>a
#define R2(a,b) cin>>a>>b
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
vector<pair<mp,int> > tubes;
int vis[303];
vector<int> g[303];
int v;
int a[303],b[303];
LL A,B;
int n,e; 
void dfs(int now){
	vis[now]=1;
	A+=a[now];
	B+=b[now];
	for(auto it:g[now]){
		if(!vis[it])
			dfs(it);
	}
}
int fa[303];
vector<int> order;
vector<int> tree_edges[303];
void build(int now,int pre=0){
	fa[now]=pre;
	vis[now]=2;
	order.PB(now);
	for(auto it:g[now]){
		if(vis[it]!=2){
			tree_edges[now].PB(it);
			tree_edges[it].PB(now);
			build(it,now);
		}
	}
}
bool updated[303];
void pull_up(int index){
	for(auto it:tree_edges[index]){
		if(it!=fa[index]){
			int can=min(v-a[index],a[it]);
//			assert(can>=0);
			if(updated[it])
				check_min(can,a[it]-b[it]);
			if(can)
				tubes.PB(II(II(it,index),can));
			a[it]-=can;
			a[index]+=can;
			pull_up(it);
		}
	}
}
void work(int root){
	order.clear();
	build(root);
	for(auto it:order){
		int to=fa[it];
		int from=it;
		while(to){
			int can=v-a[to];
			if(min(a[from],can)){
//				cout<<"____"<<from<<' '<<to<<' '<<min(a[from],can)<<endl;
				tubes.PB(II(II(from,to),min(a[from],can)));
				a[to]+=min(a[from],can);
				a[from]-=min(a[from],can);
			}
			from=to;
			to=fa[to];
		}
	}
	for(auto it:order)
		assert(a[it]<=v);
	reverse(ALL(order));
	rb(i,1,n){
		bool ok=0;
		for(auto it:order){
			if(updated[it]) continue;
			if(a[it]>=b[it]);
			else{
				ok=1;
				int needs=b[it]-a[it];
				vector<int> way;
				int to=fa[it];
				while(to){
					way.PB(to);
					if(a[to]>=needs){
						break;
					}
					to=fa[to];
				}
				reverse(ALL(way));
				way.PB(it);
				rep(i,way.size()-1){
					int move=min(a[way[i]],v-a[way[i+1]]);
					check_min(move,needs);
					a[way[i]]-=move;
					a[way[i+1]]+=move;
					tubes.PB(II(II(way[i],way[i+1]),move));
				}
				updated[it]=1;
				pull_up(root);
				break;
			}
		}
//		cout<<ok<<endl;
	}
}
int main(){
	fastio;
	cin>>n>>v>>e;
	rb(i,1,n) R(a[i]);
	rb(i,1,n) R(b[i]);
	rb(i,1,e){
		int u,v;
		R2(u,v);
		g[u].PB(v);
		g[v].PB(u);
	}
	rb(i,1,n){
		if(!vis[i]){
			A=B=0;
			dfs(i);
			if(A!=B){
				cout<<"NO\n";
				return 0;
			}
			work(i);
		}
	}	
	cout<<tubes.size()<<endl;
	for(auto it:tubes){
		cout<<it.FIR.FIR<<' '<<it.FIR.SEC<<' '<<it.SEC<<endl;
//		assert(it.SEC>0);
	}
	return 0;
}
/** 
  *
  *
  *
  *
  **/