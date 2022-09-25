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
#define up upper_bound

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int n;
map<int,int> fib;
set<int> al[200005];

vector<int> trav;
int ss[200005];
int pp[200005];

void dfs(int i,int p){
	trav.pub(i);
	ss[i]=1;
	pp[i]=p;
	for (auto &it:al[i]){
		if (it==p) continue;
		dfs(it,i);
		ss[i]+=ss[it];
	}
}

bool rec(int i){
	trav.clear();
	dfs(i,-1);
	if (sz(trav)==1) return true;
	
	int a=fib[sz(trav)];
	
	for (auto it:trav){
		if (ss[it]==a || ss[it]==sz(trav)-a){
			al[it].erase(pp[it]);
			al[pp[it]].erase(it);
			return rec(pp[it]) && rec(it);
		}
	}
	
	return false;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int a=0,b=1;
	rep(x,0,30){
		a+=b;
		swap(a,b);
		fib[b]=a;
	}
	
	cin>>n;
	
	if (!fib.count(n)){
		cout<<"NO"<<endl;
		return 0;
	}
	
	rep(x,1,n){
		cin>>a>>b;
		al[a].insert(b);
		al[b].insert(a);
	}
	
	if (rec(1)) cout<<"YES"<<endl;
	else cout<<"NO"<<endl;
}