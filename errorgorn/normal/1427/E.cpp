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

ll basis[62];

bool add_basis(ll i){
	rep(bit,62,0){
		if ((i&(1LL<<bit))==0) continue;
		
		if (basis[bit]==0){
			basis[bit]=i;
			return true;
		}
		
		i^=basis[bit];
	}
	
	return false;
}

bool check_basis(ll i){
	rep(bit,62,0){
		if ((i&(1LL<<bit))==0) continue;
		
		if (basis[bit]==0){
			return false;
		}
		
		i^=basis[bit];
	}
	
	return true;
}

vector<string> ans;
set<ll> nums;

void add(ll i,ll j){
	if (!nums.count(i) || !nums.count(j)) exit(1);
	nums.insert(i+j);
	ans.push_back(to_string(i)+" + "+to_string(j));
}

void xxor(ll i,ll j){
	if (!nums.count(i) || !nums.count(j)) exit(1);
	nums.insert(i^j);
	ans.push_back(to_string(i)+" ^ "+to_string(j));
}

int work(ll i){
	memset(basis,0,sizeof(basis));
	
	int bit=31-__builtin_clz(i);
	
	vector<ll> v;
	
	ll curr=0;
	while (true){
		curr+=i;
		if (add_basis(curr)) v.push_back(curr);
		
		rep(y,0,bit) if (basis[y]&1) goto done;
	}
	done:;
	
	//for (auto &it:v) cout<<it<<" "; cout<<endl;
	
	curr=i;
	while (curr<v.back()){
		add(curr,curr);
		curr<<=1;
	}
	
	for (auto it:v){
		it/=i;
		ll temp=0;
		rep(bit,0,20) if (it&(1<<bit)){
			if (temp) add(temp*i,(1<<bit)*i);
			temp+=(1<<bit);
		}
	}
	
	memset(basis,0,sizeof(basis));
	for (auto it:v){
		rep(bit,62,0){
			if ((it&(1LL<<bit))==0) continue;
			
			if (basis[bit]==0){
				basis[bit]=it;
				break;
			}
		
			if (basis[bit]) xxor(it,basis[bit]);	
			it^=basis[bit];
		}
	}
	
	rep(x,0,bit) if (basis[x]&1) return basis[x];
	
	return 0;
}

int n;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n;
	nums.insert(n);
	
	while (n!=1){
		n=work(n);
		//cerr<<n<<endl;
	}
	
	if (!nums.count(1)) exit(1);
	
	cout<<sz(ans)<<endl;
	for (auto &it:ans) cout<<it<<" "<<endl;
}