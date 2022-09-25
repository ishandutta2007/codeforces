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

#define si pair<char,int>

int n,m;
vector<si> arr,brr;

vector<int> prefix_function(vector<si> s) {
    int n = sz(s);
    vector<int> pi(n);
    for (int i = 1; i < n; i++) {
        int j = pi[i-1];
        while (j > 0 && s[i] != s[j])
            j = pi[j-1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>m;
	rep(x,0,n){
		string s;
		cin>>s;
		
		int occ=stoi(s.substr(0,sz(s)-2));
		char c=s.back();
		
		if (arr.empty() || arr.back().fi!=c) arr.pub({c,occ});
		else arr.back().se+=occ;
	}
	
	rep(x,0,m){
		string s;
		cin>>s;
		
		int occ=stoi(s.substr(0,sz(s)-2));
		char c=s.back();
		
		if (brr.empty() || brr.back().fi!=c) brr.pub({c,occ});
		else brr.back().se+=occ;
	}
	
	int ans=0;
	if (sz(brr)==1){
		rep(x,0,sz(arr)){
			if (arr[x].fi==brr[0].fi){
				ans+=max(0LL,arr[x].se-brr[0].se+1);
			}
		}
	}
	else{
		vector<si> v;
		rep(x,1,sz(brr)-1) v.pub(brr[x]);
		v.pub({'$',-1});
		int l=sz(v);
		rep(x,0,sz(arr)) v.pub(arr[x]);
		
		vector<int> kmp=prefix_function(v);
		
		// for (auto it:v) cout<<it.fi<<" "<<it.se<<endl;
		// for (auto it:kmp) cout<<it<<" "; cout<<endl;
		
		rep(x,0,sz(v)) if (kmp[x]==sz(brr)-2){
			int pos=x-l-sz(brr)+2;
			
			if (pos<0) continue;
			bool ok=true;
			if (arr[pos].fi!=brr.front().fi || arr[pos].se<brr.front().se) ok=false;
			pos+=sz(brr)-1;
			if (sz(arr)<=pos) continue;
			if (arr[pos].fi!=brr.back().fi || arr[pos].se<brr.back().se) ok=false;
			
			if (ok) ans++;
		}
	}
	
	cout<<ans<<endl;
}