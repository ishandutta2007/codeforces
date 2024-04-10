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

mt19937 rng(177013);

int query(int a,int b,int c){
	cout<<"? "<<a<<" "<<b<<" "<<c<<endl;
	int temp;
	cin>>temp;
	
	return temp;
}

void sort(int &a,int &b,int &c){
	 if (a>b) swap(a,b);
	 if (b>c) swap(b,c);
	 if (a>b) swap(a,b);
}

void solve(){
	int n;
	cin>>n;
	
	vector<int> ans(n+5,0);
	
	set<tuple<int,int,int> > s;
	
	int a,b,c;
	while (true){
		a=rng()%n+1,b=rng()%n+1,c=rng()%n+1;
		
		if (a==b || b==c || a==c) continue;
		
		sort(a,b,c);
		if (s.count({a,b,c})) continue;
		s.insert({a,b,c});
		
		if (query(a,b,c)<=(n-4)/6){
			break;
		}
	}
	
	map<int,vector<int>,greater<int> > m;
	rep(x,1,n+1) if (x!=a && x!=b){
		m[query(a,b,x)].push_back(x);
	}
	
	int hv=(*m.begin()).fi;
	if (sz(m[hv-1])>=2){ //there must be exactly 2
		if (query(m[hv][0],m[hv-1][0],a)>
			query(m[hv][0],m[hv-1][1],a))
				swap(m[hv-1][0],m[hv-1][1]);
	}
	
	int hi=m[hv][0],hi2=m[hv-1][0];
	
	//cout<<hi2<<" "<<hi<<endl;
	
	ans[hi]=1,ans[hi2]=2;
	rep(x,1,n+1) if (x!=hi2 && x!=hi){
		ans[x]=query(hi,hi2,x)+2;
	}
	
	if (ans[1]>ans[2]) rep(x,1,n+1) ans[x]=n-ans[x]+1;
	
	cout<<"! "; rep(x,1,n+1) cout<<ans[x]<<" "; cout<<endl;
	
	cin>>n; //read stupid value
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		solve();
	}
}