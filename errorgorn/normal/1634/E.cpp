// Super Idol
//    
//  
//    
//  105C
// 

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#define int long long
#define ll long long
#define ii pair<ll,ll>
#define iii pair<ii,ll>
#define fi first
#define se second
#define endl '\n'
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

int n;
vector<int> v[100005];
int val[200005];
ii pos[200005];

set<int> alive[200005];

string ans[100005];


signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n;
	
	int a,b;
	int IDX=0;
	
	rep(x,0,n){
		cin>>a;
		rep(y,0,a){
			cin>>b;
			v[x].pub(b);
			ans[x]+='L';
			pos[IDX]={x,y};
			IDX++;
		}
	}
	
	vector<int> uni;
	rep(x,0,n) for (auto &it:v[x]) uni.pub(it);
	
	sort(all(uni));
	
	rep(x,0,n) for (auto &it:v[x]) it=lb(all(uni),it)-uni.begin();
	
	IDX=0;
	rep(x,0,n) rep(y,0,sz(v[x])){
		alive[v[x][y]].insert(IDX);
		val[IDX]=v[x][y];
		IDX++;
	}
	
	rep(x,0,200005) if (sz(alive[x])%2==1){
		cout<<"NO"<<endl;
		return 0;
	}
	
	rep(x,0,200005) while (!alive[x].empty()){
		int curr=*alive[x].begin();
		
		do{
			ans[pos[curr].fi][pos[curr].se]='R';
			
			
			alive[val[curr]].erase(curr);
			alive[val[curr^1]].erase(curr^1);
			
			if (alive[val[curr^1]].empty()) break;
			else curr=*alive[val[curr^1]].begin();
		} while (val[curr]!=x);
	}
	
	cout<<"YES"<<endl;
	rep(x,0,n) cout<<ans[x]<<endl;
}