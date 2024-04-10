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
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define R(a) cin>>a
#define R2(a,b) cin>>a>>b
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
const int MAXN=1e4+20;
vector<int> g[MAXN];
int n,depth[MAXN],flag[MAXN];
int cnt=0;
bool vis[MAXN];
int res[MAXN];
map<mp,int> M;
void dfs(int now,int pre,int deep=1){
//	cout<<now<<" "<<pre<<endl;
	depth[now]=deep;
	vis[now]=1;
	for(auto it:g[now]){
		if(!vis[it])
		{
			dfs(it,now,deep+1);
		}
	}
}
void dfs2(int now,int pre){
	vis[now]=1;
	for(auto it:g[now]){
		if(depth[it]==depth[now]+1){
			dfs2(it,now);
			flag[now]+=flag[it];
		} 
	}
	res[M[II(now,pre)]]=flag[now];
}
int main(){
	fastio;
	R(n);
	int m;
	R(m);
	vector<mp> edges;
	rb(i,1,m){
		int u,v;
		R2(u,v);
		g[u].PB(v);
		g[v].PB(u);
		M[II(u,v)]=M[II(v,u)]=i;
		edges.PB(II(u,v)); 
	}
	rb(i,1,n){
		if(!vis[i]){
			dfs(i,0);
		}
	}
	rep(i,m){
		if(abs((depth[edges[i].FIR]-depth[edges[i].SEC]))>1){
			if(abs((depth[edges[i].FIR]-depth[edges[i].SEC]))&1){
				int low,high;
				if(depth[edges[i].FIR]<depth[edges[i].SEC]){
					swap(edges[i].FIR,edges[i].SEC);
				}
				low=edges[i].SEC;
				high=edges[i].FIR;/*
				high=min(depth[edges[i].FIR],depth[edges[i].SEC]);
				low= max(depth[edges[i].FIR],depth[edges[i].SEC]);*/
				flag[low]++;
				flag[high]--;
			}
			else{
				int low,high;
				if(depth[edges[i].FIR]<depth[edges[i].SEC]){
					swap(edges[i].FIR,edges[i].SEC);
				}
				low=edges[i].SEC;
				high=edges[i].FIR;/*
				high=min(depth[edges[i].FIR],depth[edges[i].SEC]);
				low= max(depth[edges[i].FIR],depth[edges[i].SEC]);*/
				cnt++;
				flag[low]--;
				flag[high]++;
			}
		}
	}
	if(!cnt){
		cout<<m<<endl;
		rb(i,1,m){
			cout<<i<<" ";
		}
		return 0;
	}
	memset(vis,0,sizeof(vis));
	rb(i,1,n){
		if(!vis[i]){
			dfs2(i,0);
		}
	}
	if(cnt==1){
		rep(i,m){
		if(abs((depth[edges[i].FIR]-depth[edges[i].SEC]))>1){
			if(abs((depth[edges[i].FIR]-depth[edges[i].SEC]))&1);
			else{
				res[M[II(edges[i].FIR,edges[i].SEC)]]=1;
			}
		}
		}
	}
	vector<int> ans;
	rb(i,1,m){
		if(res[i]==cnt){
			ans.PB(i);
		}
	}
	cout<<ans.size()<<endl;
	for(auto it:ans){
		cout<<it<<" ";
	}
	return 0;
}
/*
5 6
1 2
2 3
3 4
4 5
5 2
4 2

5
7
1 2
2 3
2 4
3 1
4 1
1 5
5 3
*/