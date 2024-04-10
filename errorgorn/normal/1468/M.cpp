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
#define ii pair<int,int>
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

const int BLOCK=320;

int n;
vector<int> v[100005];
vector<ii> pp[200005];
int grp[200005];
bool has[200005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	memset(grp,-1,sizeof(grp));
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n;
		
		vector<int> uni;
		
		rep(x,0,n){
			v[x].clear();
			int a,b;
			cin>>a;
			rep(y,0,a){
				cin>>b;
				v[x].push_back(b);
				uni.push_back(b);
			}
		}
		
		sort(all(uni));
		map<int,int> id;
		rep(x,0,sz(uni)){
			pp[x].clear();
			id[uni[x]]=x;
		}
		
		rep(x,0,n){
			for (auto &it:v[x]) it=id[it];
			sort(all(v[x]));
			//for (auto &it:v[x]) cout<<it<<" "; cout<<endl;
		}
		
		rep(x,0,n) if (sz(v[x])<BLOCK){
			rep(i,0,sz(v[x])){
				rep(j,i+1,sz(v[x])){
					pp[v[x][i]].push_back(ii(v[x][j],x));
				}
			}
		}
		
		
		rep(x,0,sz(uni)){
			for (auto &it:pp[x]){
				if (grp[it.fi]==-1) grp[it.fi]=it.se;
				else{
					cout<<grp[it.fi]+1<<" "<<it.se+1<<endl;
					for (auto &it2:pp[x]) grp[it2.fi]=-1;
					goto done;
				}
			}
			
			for (auto &it2:pp[x]) grp[it2.fi]=-1;
		}
		
		rep(x,0,n) if (sz(v[x])>=BLOCK){
			memset(has,false,sizeof(has));
			for (auto &it:v[x]) has[it]=true;
			rep(y,0,n) if (x!=y){
				int cnt=0;
				for (auto &it:v[y]) if (has[it]) cnt++;
				
				if (cnt>=2){
					cout<<x+1<<" "<<y+1<<endl;
					goto done;
				}
			}
		}
		
		cout<<"-1"<<endl;
		done:;
	}
}