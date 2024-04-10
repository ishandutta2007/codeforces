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

int n;
int arr[55];
vector<int> v;

int memo[50][2500005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n;
	rep(x,0,2*n) cin>>arr[x];
	sort(arr,arr+2*n);
	
	rep(x,2,2*n) v.push_back(arr[x]);
	
	memo[0][0]=1;
	
	rep(x,0,sz(v)){
		rep(y,0,2500005){
			memo[x+1][y]|=memo[x][y];
			if (y+v[x]<2500005) memo[x+1][y+v[x]]|=(memo[x][y]<<1);
		}
	}
	
	ll tot=0;
	for (auto &it:v) tot+=it;
	
	int px=sz(v),py=sz(v)/2,pz;
	rep(x,(tot+1)/2,2500005) if (memo[sz(v)][x]&(1<<py)){
		pz=x;
		break;
	}
	
	vector<int> a;
	vector<int> b;
	
	while (px){
		if (memo[px-1][pz]&(1<<py)){
			px--;
			b.push_back(v[px]);
		}
		else{
			px--,py--,pz-=v[px];
			a.push_back(v[px]);
		}
	}
	
	//for (auto &it:a) cout<<it<<" "; cout<<endl;
	//for (auto &it:b) cout<<it<<" "; cout<<endl;
	
	vector<ii> c;
	rep(x,0,sz(a)) c.push_back(ii(a[x],b[x]));
	
	sort(all(c),[](ii i,ii j){
		return i.fi-i.se>j.fi-j.se;
	});
	
	cout<<arr[0]<<" ";
	for (auto &it:c) cout<<it.se<<" ";
	cout<<endl;
	for (auto &it:c) cout<<it.fi<<" ";
	cout<<arr[1]<<" ";
	cout<<endl;
}