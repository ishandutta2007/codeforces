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

int n;

vector<int> calc(int i){
	if (i==2) return {2,1};
	else if (i%4==2){
		vector<int> res={i};
		for (auto &it:calc((i-2)/2)){
			res.pub(it<<1|1);
			res.pub(it<<1);
		}
		res.pub(1);
		return res;
	}
	else{
		vector<int> res;
		for (auto &it:calc(i/2)){
			if (it==i/2) res.pub(1);
			else res.pub(it<<1|1);
			res.pub(it<<1);
		}
		res.insert(res.begin(),res.back());
		res.pob();
		return res;
	}
}

vector<int> v[20];
int ans[100005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n;
	
	if (n%2==1){
		cout<<"NO"<<endl;
	}
	else{
		cout<<"YES"<<endl;
		auto temp=calc(n);
		
		//rep(x,0,n) cout<<(temp[x]&(x+1))<<" "; cout<<endl;
		for (auto &it:temp) cout<<it<<" "; cout<<endl;
	}
	
	if (__builtin_popcount(n)==1 || n==3 || n==5){
		cout<<"NO"<<endl;
	}
	else{
		cout<<"YES"<<endl;
		
		rep(x,1,n+1){
			v[31-__builtin_clz(x)].pub(x);
		}
		
		rep(x,0,20){
			if (sz(v[x])>2){
				v[0].pub(v[x][1]);
				v[x].erase(v[x].begin()+1);
				break;
			}
		}
		
		rep(x,0,20){
			rep(y,0,sz(v[x])) ans[v[x][y]]=v[x][(y+1)%sz(v[x])];
		}
		
		rep(x,1,n+1) cout<<ans[x]<<" "; cout<<endl;
	}
}