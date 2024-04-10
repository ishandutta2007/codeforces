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

ll n,m,k;

vector<int> f[205],b[205];
ll inner[205];

vector<int> add(vector<int> i,vector<int> j){
	vector<int> res;
	for (auto &it:i) res.pub(it);
	for (auto &it:j) res.pub(it);
	return res;
}

ll test(vector<int> v){
	f[0]={1};
	b[0]={1};
	
	f[1]={2};
	b[1]={2};
	
	rep(x,2,n+1){
		inner[x]=inner[x-2]+inner[x-1];
		
		vector<int> comb=add(b[x-2],f[x-1]);
		rep(i,0,sz(b[x-2])) if (i+m<=sz(comb)){
			bool can=true;
			rep(y,0,m){
				if (comb[i+y]>v[y]){
					can=false;
					break;
				}
				if (comb[i+y]<v[y]){
					break;
				}
			}
			if (can) inner[x]++;
		}
		
		f[x]=add(f[x-2],f[x-1]);
		while (sz(f[x])>m-1) f[x].pob();
		
		b[x]=add(b[x-2],b[x-1]);
		reverse(all(b[x]));
		while (sz(b[x])>m-1) b[x].pob();
		reverse(all(b[x]));
		
		int ss=sz(b[x]);
		rep(i,0,m) b[x].pub(0);
		ll curr=0;
		rep(i,0,ss){
			bool can=true;
			rep(y,0,m){
				if (b[x][i+y]>v[y]){
					can=false;
					break;
				}
				if (b[x][i+y]<v[y]){
					break;
				}
			}
			if (can) curr++;
		}
		rep(i,0,m) b[x].pob();
		
		//cout<<"debug: "<<curr<<" "<<inner[x]<<endl;
		if (curr+inner[x]>=k) return false;
	}
	
	return true;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>k>>m;
	
	if (n==1){
		cout<<"1";
		return 0;
	}
	if (m==1){
		int arr[205];
		arr[0]=1;
		arr[1]=0;
		rep(x,2,n+1){
			arr[x]=arr[x-2]+arr[x-1];
			if (arr[x]>=k){
				cout<<"0";
				return 0;
			}
		}
		cout<<"1";
		return 0;
	}
	
	vector<int> v;
	rep(x,0,m) v.pub(0);
	
	rep(x,0,m){
		while (v[x]!=2){
			v[x]++;
			
			//for (auto &it:v) cout<<it<<" "; cout<<endl;
			
			if (!test(v)){
				v[x]--;
				break;
			}
		}
	}
	
	bool c=true;
	rep(x,sz(v),0){
		if (v[x]==2 && c){
			v[x]=0;
		}
		else if (c){
			v[x]++;
			c=false;
		}
	}
	
	
	for (auto &it:v){
		if (it==2) cout<<1;
		else if (it==1) cout<<0;
	}
}