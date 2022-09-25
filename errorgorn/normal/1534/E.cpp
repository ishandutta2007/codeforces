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

int n,k;
priority_queue<ii> pq;
int cnt[505];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	//cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>k;
	
	if (n%2==1 && k%2==0){
		cout<<"-1"<<endl;
		return 0;
	}
	
	int num=0;
	while (num<n || num%2!=n%2 || (num%(2*n)!=n && (2+(num+n)/(2*n)*2-1)>num/k)) num+=k;
	
	rep(x,0,n) if (num%(2*n)!=n) cnt[x]+=2,num-=2;
	rep(x,0,num) cnt[x%n]++;
	rep(x,0,n) pq.push(ii(cnt[x],x));
	
	int ans=0;
	while (!pq.empty()){
		vector<int> v;
		rep(x,0,k){
			v.pub(pq.top().se);
			pq.pop();
		}
		
		for (auto &it:v){
			cnt[it]--;
			if (cnt[it]) pq.push(ii(cnt[it],it));
		}
		
		cout<<"? "; for (auto &it:v) cout<<it+1<<" "; cout<<endl;
		
		int t;
		cin>>t;
		ans^=t;
	}
	
	cout<<"! "<<ans<<endl;
}