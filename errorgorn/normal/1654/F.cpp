// Super Idol
//    
//  
//    
//  105C
// 

#include <bits/stdc++.h>
using namespace std;

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
string s;
int ra[270000];
ii temp[270000];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n;
	cin>>s;
	
	rep(x,0,1<<n) ra[x]=s[x]-'a';
	
	rep(z,0,n){
		rep(x,0,1<<n) temp[x]={ra[x],ra[x^(1<<z)]};
		vector<int> idx;
		rep(x,0,1<<n) idx.pub(x);
		sort(all(idx),[](int i,int j){
			return temp[i]<temp[j];
		});
		
		int IDX=0;
		rep(x,0,1<<n){
			if (x==0 || temp[idx[x-1]]!=temp[idx[x]]) IDX++;
			ra[idx[x]]=IDX;
		}
	}
	
	rep(y,0,1<<n) if (ra[y]==1){
		rep(x,0,1<<n) cout<<s[x^y]; cout<<endl;
		break;
	}
}