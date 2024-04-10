//
//

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#define ll long long
#define ii pair<ll,ll>
#define iii pair<ii,ll>
#define fi first
#define se second
#define endl '\n'
#define debug(x) cout << #x << " is " << x << endl;

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

ll MAX(ll a){return a;}
ll MIN(ll a){return a;}
template<typename... Args>
ll MAX(ll a,Args... args){return max(a,MAX(args...));}
template<typename... Args>
ll MIN(ll a,Args... args){return min(a,MIN(args...));}

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

const int SS=400005;
const int BUF=800100;

int n,r,M,p;
vector<int> al[1600500];
int dfs_counter=0;
int scc_counter=0;
bool visited[1600500];
int dfs_time[1600500];
int low[1600500];
int id[1600500]; ///contains the SCC it is in
bool stack_member[1600500];
stack<int> s;

vector<int> sal[1600500];

void add_edge(int u,int v){
	al[-u+BUF].push_back(v+BUF);
	al[-v+BUF].push_back(u+BUF);
}

void SCC(int i){
    s.push(i);
    low[i]=dfs_time[i]=dfs_counter++;
    visited[i]=true;
    stack_member[i]=true;
    for (auto it=al[i].begin();it!=al[i].end();it++){
        if (!visited[*it]) {
            SCC(*it);
            low[i]=min(low[i],low[*it]);
        }
        else if (stack_member[*it])     
            low[i]=min(low[i],dfs_time[*it]);
    }
    if (dfs_time[i]==low[i]){
        while (s.top()!=i){
            id[s.top()]=scc_counter;
            stack_member[s.top()]=false;
            s.pop();
        }
        id[s.top()]=scc_counter++;
        stack_member[s.top()]=false;
        s.pop();
    }
}

vector<int> ts;
void dfs(int i){
    visited[i]=true;
    for (auto it=sal[i].begin();it!=sal[i].end();it++){
        if (!visited[*it]){
            dfs(*it);
        }
    }
    ts.push_back(i);
}

int order[1600500];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>r>>M>>p;
	
	int a,b;
	rep(x,0,n){ //complaints, its VC
		cin>>a>>b;
		add_edge(a,b);
	}
	rep(x,1,r+1){ //radio power
		cin>>a>>b;
		add_edge(a+SS,-x);
		add_edge(-(b+1+SS),-x);
	}
	rep(x,1,M+1){
		add_edge(x+SS,-(x+1+SS));
	}
	rep(x,0,p){
		cin>>a>>b;
		add_edge(-a,-b);
	}
	
	rep(x,0,1600500) if (!visited[x]) SCC(x);
	
	rep(x,0,1600500){
		for (auto &it:al[x]) if (id[x]!=id[it]){
			sal[id[x]].push_back(id[it]);
		}
	}
	
	memset(visited,false,sizeof(visited));
	rep(x,0,1600500) if (!visited[x]) dfs(x);
	reverse(all(ts));
	rep(x,0,sz(ts)) order[ts[x]]=x;
	
	int freq=-1;
	vector<int> ans;
	
	rep(x,1,r+1){
		if (id[x+BUF]==id[-x+BUF]){
			cout<<"-1"<<endl;
			return 0;
		}
		
		if (order[id[-x+BUF]]<order[id[x+BUF]]) ans.push_back(x);
	}
	rep(x,1,M+1){
		if (id[(x+SS)+BUF]==id[-(x+SS)+BUF]){
			cout<<"-1"<<endl;
			return 0;
		}
		
		if (order[id[-(x+SS)+BUF]]<order[id[(x+SS)+BUF]]) freq=x;
	}
	
	cout<<sz(ans)<<" "<<freq<<endl;
	for (auto &it:ans) cout<<it<<" ";
}