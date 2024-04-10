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

#define rep(x,start,end) for(int x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int n,k;
vector<int> al[100005];
vector<int> v[100005]; //all
vector<int> v1[100005]; //not leaf
vector<int> v2[100005]; //is leaf

int D=0;

void dfs(int i,int d){
	D=max(D,d);
	
	v[d].pub(i);
	
	if (al[i].empty()) v2[d].pub(i);
	else v1[d].pub(i);
	
	for (auto it:al[i]){
		dfs(it,d+1);
	}
}

vector<vector<int> > ss[100005];
vector<vector<int> > uni;
bitset<100005> bs[1005];

string ans;

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>k;
	
	ans=string(n,'b');
	
	int a;
	rep(x,1,n){
		cin>>a;
		al[a-1].pub(x);
	}
	
	dfs(0,1);
	
	rep(x,0,100005) if (sz(v[x])){
		ss[sz(v[x])].pub(v[x]);
	}
	rep(x,0,100005){
		while (sz(ss[x])>=3){
			vector<int> temp;
			rep(y,0,2){
				for (auto it:ss[x].back()) temp.pub(it);
				ss[x].pob();
			}
			ss[x*2].pub(temp);
		}
		
		for (auto it:ss[x]) uni.pub(it);
	}
	
	// for (auto it:uni){
		// for (auto it2:it) cout<<it2<<" "; cout<<endl;
	// }
	
	bs[0][0]=1;
	rep(x,0,sz(uni)){
		bs[x+1]=bs[x];
		bs[x+1]|=bs[x]<<sz(uni[x]);
	}
	
	if (bs[sz(uni)][k]){
		int curr=k;
		rep(x,sz(uni),0){
			if (curr-sz(uni[x])>=0 && bs[x][curr-sz(uni[x])]){
				for (auto it:uni[x]) ans[it]='a';
				curr-=sz(uni[x]);
			}
		}
		
		cout<<D<<endl;
		cout<<ans<<endl;
	}
	else{
		int curr=n;
		rep(x,1,D+1){
			curr-=sz(v1[x])+sz(v2[x]);
			
			if (sz(v1[x])+sz(v2[x])<=k){
				for (auto it:v1[x]) ans[it]='a';
				for (auto it:v2[x]) ans[it]='a';
				k-=sz(v1[x])+sz(v2[x]);
			}
			else if (curr<=k){
				rep(y,0,k-curr) ans[v2[x][y]]='a';
				rep(y,x+1,D+1){
					for (auto it:v1[y]) ans[it]='a';
					for (auto it:v2[y]) ans[it]='a';
				}
				break;
			}
		}
		
		cout<<D+1<<endl;
		cout<<ans<<endl;
	}
}