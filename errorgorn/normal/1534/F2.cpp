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
#define debug(x) cout << #x << ": " << x << endl

#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define lb lower_bound
#define ub upper_bound

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int n,m;
string grid[400005];
int arr[400005];

vector<int> col[400005];

vector<int> al[400005];

int code(int x,int y){
	return x*m+y;
}

int _TIME=1;
int IDX=1;

int in[400005];
int low[400005];
bool onstk[400005];
vector<int> stk;

int comp[400005];
vector<int> pos[400005];

void dfs(int i){
	in[i]=low[i]=_TIME++;
	onstk[i]=true;
	stk.pub(i);
	
	for (auto &it:al[i]){
		if (in[it]==0){
			dfs(it);
			low[i]=min(low[i],low[it]);
		}
		else if (onstk[it]){
			low[i]=min(low[i],in[it]);
		}
	}
	
	if (in[i]==low[i]){
		int curr;
		do{
			curr=stk.back(),stk.pob();
			comp[curr]=IDX;
			onstk[curr]=false;
			pos[IDX].pub(curr%m); //y-coord
		} while (curr!=i);
		IDX++;
	}
}

vector<int> al2[400005];
int mn[400005],mx[400005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>m;
	rep(x,0,n) cin>>grid[x];
	rep(x,0,m) cin>>arr[x],arr[x]=-arr[x];
	
	rep(x,0,n) rep(y,0,m) if (grid[x][y]=='#'){
		col[y].pub(x);
		arr[y]++;
	}
	
	rep(x,1,n) rep(y,0,m){ //shld be sufficient to connect to par
		if (grid[x-1][y]=='#' && grid[x][y]=='#'){
			al[code(x,y)].pub(code(x-1,y));
		}
	}
	
	rep(y,0,m){
		rep(x,0,sz(col[y])){
			if (x!=sz(col[y])-1) al[code(col[y][x],y)].pub(code(col[y][x+1],y));
			
			if (y){
				auto it=lb(all(col[y-1]),col[y][x]);
				if (it!=col[y-1].end())
					al[code(col[y][x],y)].pub(code(*it,y-1));
			}
			if (y!=m-1){
				auto it=lb(all(col[y+1]),col[y][x]);
				if (it!=col[y+1].end())
					al[code(col[y][x],y)].pub(code(*it,y+1));
			}
		}
	}
	
	//ok so stuff is canonically labeled left to right
	rep(y,0,m) rep(x,0,n) if (grid[x][y]=='#' && in[code(x,y)]==0){
		dfs(code(x,y));
	}
	
	rep(x,0,n) rep(y,0,m){
		int c=code(x,y);
		for (auto &it:al[c]) al2[comp[c]].pub(comp[it]);
	}
	
	rep(x,0,400005) mn[x]=1e9,mx[x]=-1e9;
	
	int CANON=1;
	
	//rep(y,0,m) cout<<arr[y]<<" "; cout<<endl<<endl;
	
	rep(x,IDX,1){
		if (mn[x]==1e9){
			mn[x]=mx[x]=CANON++;
		}
		for (auto &it:al2[x]){
			mn[it]=min(mn[it],mn[x]);
			mx[it]=max(mx[it],mx[x]);
		}
		
		//cout<<x<<" "<<mn[x]<<" "<<mx[x]<<endl;
		//for (auto &it:pos[x]) cout<<it<<" "; cout<<endl;
	}
	
	vector<int> proc;
	rep(x,1,IDX) proc.pub(x);
	sort(all(proc),[](int i,int j){
		return mn[i]>mn[j];
	});
	priority_queue<ii,vector<ii>,greater<ii> > pq;
	
	vector<int> changes;
	int ans=0;
	
	rep(x,1,CANON){
		//cout<<"processing: "<<x<<endl;
		
		while (!proc.empty() && mn[proc.back()]==x){
			//cout<<"add: "<<mx[proc.back()]<<" "<<proc.back()<<endl;
			pq.push(ii(mx[proc.back()],proc.back()));
			proc.pob();
		}
		
		bool bad=false;
		while (!pq.empty() && pq.top().fi==x){
			int c=pq.top().se; pq.pop();
			//cout<<"removing: "<<c<<endl;
			
			for (auto &it:pos[c]){
				arr[it]--;
				changes.pub(it);
				if (arr[it]<0) bad=true;
			}
		}
		
		//cout<<bad<<endl;
		if (bad){
			//rollback all change
			for (auto &it:changes) arr[it]++;
			while (!pq.empty()) pq.pop();
			changes.clear();
			
			ans++;
		}
	}
	
	cout<<ans<<endl;
}