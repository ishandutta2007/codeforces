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

int n,m;
indexed_set s;

ll toInt(string s){
	reverse(all(s));
	
	ll res=0;
	rep(x,0,m){
		if (s[x]=='1') res|=(1LL<<x);
	}
	
	return res;
}

string toString(ll i){
	string res;
	
	rep(x,0,m){
		if (i&(1LL<<x)) res+='1';
		else res+='0';
	}
	
	reverse(all(res));
	return res;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int TC;
	cin>>TC;
	while (TC--){
		s.clear();
		
		cin>>n>>m;
		
		rep(x,0,n){
			string st;
			cin>>st;
			s.insert(toInt(st));
		}
		
		ll lower=((1LL<<m)-n-1)/2;
		//cout<<lower<<endl;
		
		//rep(x,0,1LL<<m){
		//	cout<<x<<" "<<x-(int)s.order_of_key(x)<<endl;
		//}
		
		ll lo=0,hi=1LL<<m,mi;
		while (hi-lo>1){
			mi=hi+lo>>1;
			
			if (mi-s.order_of_key(mi)<=lower) lo=mi;
			else hi=mi;
		} 
		
		cout<<toString(lo)<<endl;
	}
}