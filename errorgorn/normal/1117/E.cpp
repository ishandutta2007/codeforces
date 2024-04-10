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
#define debug(x) cout << #x << " is " << x << endl;

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

ll MAX(ll a){return a;}
ll MIN(ll a){return a;}
template<typename... Args>
ll MAX(ll a,Args... args){return max(a,MAX(args...));}
template<typename... Args>
ll MIN(ll a,Args... args){return min(a,MIN(args...));}

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

string s;
string res[3];

int pos[10005];

char ans[10005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>s;
	
	int curr=1;
	rep(pp,0,3){
		string temp;
		
		rep(x,0,sz(s)){
			temp+=(char)('a'+(x/curr)%26);
		}
		
		cout<<"? "<<temp<<endl;
		cin>>res[pp];
		
		curr*=26;
	}
	
	rep(x,0,sz(s)){
		rep(y,0,3) res[y][x]-='a';
		pos[x]=res[0][x]+res[1][x]*26+res[2][x]*26*26;
		
		//cout<<pos[x]<<" ";
	}
	
	rep(x,0,sz(s)){
		ans[pos[x]]=s[x];
	}
	
	cout<<"! ";
	rep(x,0,sz(s)) cout<<ans[x];
}