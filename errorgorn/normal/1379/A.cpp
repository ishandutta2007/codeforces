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

string zzz="abacaba";

int cnt(string i){
	int res=0;
	
	rep(x,0,sz(i)-7+1){
		bool ok=true;
		rep(y,0,7){
			if (i[x+y]!=zzz[y]) ok=false;
		}
		
		if (ok) res++;
	}
	
	return res;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int TC;
	cin>>TC;
	while (TC--){
		int n;
		string s,t;
		
		cin>>n;
		cin>>s;
		
		rep(x,0,n-7+1){
			t=s;
			
			rep(y,0,7){
				if (t[x+y]==zzz[y] || t[x+y]=='?') t[x+y]=zzz[y];
			}
			
			rep(x,0,n) if (t[x]=='?') t[x]='z';
			
			if (cnt(t)==1){
				cout<<"Yes"<<endl;
				cout<<t<<endl;
				goto ok;
			}
		}
		
		cout<<"No"<<endl;
		ok:;
	}
}