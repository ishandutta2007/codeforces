// Super Idol
//    
//  
//    
//  105C
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

const int MOD=1000000007;

ll fix(ll i){
	i%=MOD;
	if (i<0) i+=MOD;
	return i;
}

int n;
string s;
string t;

const int BUF=2005;
ii memo[2005][4010]; //(num,val)

void proc(int x,int i){
	if (i==0){
		rep(y,1,4009){
			memo[x+1][y]={
				fix(memo[x+1][y].fi+memo[x][y].fi),
				fix(memo[x+1][y].se+memo[x][y].se)
			};
		}
	}
	if (i==-1){
		rep(y,1,4009){
			if (y<=BUF) memo[x+1][y-1]={
				fix(memo[x+1][y-1].fi+memo[x][y].fi),
				fix(memo[x+1][y-1].se+memo[x][y].se-x*memo[x][y].fi)
			};
			else memo[x+1][y-1]={
				fix(memo[x+1][y-1].fi+memo[x][y].fi),
				fix(memo[x+1][y-1].se+memo[x][y].se+x*memo[x][y].fi)
			};
		}
	}
	if (i==1){
		rep(y,1,4009){
			if (y>=BUF) memo[x+1][y+1]={
				fix(memo[x+1][y+1].fi+memo[x][y].fi),
				fix(memo[x+1][y+1].se+memo[x][y].se-x*memo[x][y].fi)
			};
			else memo[x+1][y+1]={
				fix(memo[x+1][y+1].fi+memo[x][y].fi),
				fix(memo[x+1][y+1].se+memo[x][y].se+x*memo[x][y].fi)
			};
		}
	}
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n;
		cin>>s>>t;
		
		rep(x,0,n+1){
			rep(y,0,4010) memo[x][y]={0,0};
		}
		
		
		memo[0][BUF]={1,0};
		
		rep(x,0,n){
			if (s[x]!='1' && t[x]!='1'){ //00
				proc(x,0);
			}
			if (s[x]!='0' && t[x]!='0'){ //11
				proc(x,0);
			}
			if (s[x]!='0' && t[x]!='1'){ //10
				if (x%2==0) proc(x,1);
				else proc(x,-1);
			}
			if (s[x]!='1' && t[x]!='0'){
				if (x%2==0) proc(x,-1);
				else proc(x,1);
			}
		}
		
		cout<<memo[n][BUF].se<<endl;
	}
}