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

int n;
string s,t;
string ss,tt;

vector<int> ans;

string op(string s,int i){
	ans.push_back(i);
	reverse(all(s));
	reverse(i+all(s));
	
	return s;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	cin>>s>>t;
	
	ss=s,tt=t;
	sort(all(ss)),sort(all(tt));
	
	if (ss!=tt){
		cout<<"-1"<<endl;
		return 0;
	}
	
	rep(x,0,n){
		rep(y,0,n) if (s[y]==t[x]){
			s=op(s,n-y-1);
			break;
		}
		
		//cout<<s<<endl;
		s=op(s,1);
		//cout<<s<<endl;
		s=op(s,n);
		//cout<<s<<endl<<endl;
	}
	
	cout<<sz(ans)<<endl;
	for (auto &it:ans) cout<<it<<" ";
}