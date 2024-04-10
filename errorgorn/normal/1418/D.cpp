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

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int n,q;
int arr[100005];
set<int> s;

multiset<int,greater<int> > diff;


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>q;
	rep(x,0,n) cin>>arr[x];
		
	sort(arr,arr+n);
	rep(x,0,n){
		s.insert(arr[x]);
		if (x) diff.insert(arr[x]-arr[x-1]);
	}
	
	cout<<*s.rbegin()-*s.begin()-*diff.begin()<<endl;
	
	int a,b;
	while (q--){
		cin>>a>>b;
		
		if (a==1){
			auto it=s.insert(b).fi;
			
			int l=-1,r=-1;
			if (it!=s.begin()) l=*prev(it);
			if (it!=--s.end()) r=*next(it);
			
			if (l!=-1) diff.insert(b-l);
			if (r!=-1) diff.insert(r-b);
			if (l!=-1 && r!=-1) diff.erase(diff.find(r-l));
		}
		else{
			auto it=s.find(b);
			
			int l=-1,r=-1;
			if (it!=s.begin()) l=*prev(it);
			if (it!=--s.end()) r=*next(it);
			
			if (l!=-1) diff.erase(diff.find(b-l));
			if (r!=-1) diff.erase(diff.find(r-b));
			if (l!=-1 && r!=-1) diff.insert(r-l);
			s.erase(it);
		}
		
		if (sz(s)<=2) cout<<0<<endl;
		else cout<<*s.rbegin()-*s.begin()-*diff.begin()<<endl;
	}
	
}