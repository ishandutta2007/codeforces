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
#define debug(x) cout << #x << " is " << x << endl

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

void rage(){
	cout<<0<<endl;
	exit(0);
}

int n,k;
int arr[300005];
int nxt[300005];
bool head[300005];

int grp[300005];
int grp_id[300005];
vector<int> grps[300005];

vector<int> al[300005];

void dfs(int i,int num,int id){
	grp[i]=num;
	grp_id[i]=id;
	grps[num].push_back(i);
	if (nxt[i]!=-1) dfs(nxt[i],num,id+1);
}

int col[300005];
vector<int> topo;

bool dfs2(int i){
	col[i]=1;
	for (auto &it:al[i]){
		if (col[it]==1) return true;
		else if (col[it]==0){
			if (dfs2(it)) return true;
		}
	}
	
	topo.push_back(i);
	col[i]=2;
	return false;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>k;
	rep(x,0,n){
		cin>>arr[x];
		arr[x]--;
	}
	
	memset(nxt,-1,sizeof(nxt));
	memset(head,true,sizeof(head));
	int a,b;
	rep(x,0,k){
		cin>>a>>b;
		a--,b--;
		
		nxt[a]=b;
		head[b]=false;
	}
	
	memset(grp,-1,sizeof(grp));
	
	int IDX=0;
	rep(x,0,n) if (head[x]){
		dfs(x,IDX++,0);
	}
	
	rep(x,0,n) if (grp[x]==-1) rage();
	
	rep(x,0,n) if (arr[x]!=-1){
		if (grp[arr[x]]==grp[x]){
			if (grp_id[arr[x]]>grp_id[x]) rage();
		}
		else{
			al[grp[arr[x]]].push_back(grp[x]);
			//cout<<grp[arr[x]]<<" "<<grp[x]<<endl;
		}
	}
	
	rep(x,0,IDX) if (col[x]==0){
		if (dfs2(x)) rage();
	}
	
	reverse(all(topo));
	for (auto &it:topo){
		for (auto &it2:grps[it]) cout<<it2+1<<" ";
	}
}