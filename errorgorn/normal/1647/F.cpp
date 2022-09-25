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

int n;
int arr[500005];
ii l[500005];
ii r[500005];

bool inside(int a,int b,int c){
	return a<=c && c<=b;
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n;
	rep(x,1,n+1) cin>>arr[x];
	
	l[0]={-1,-1};
	r[n+1]={-1,-1};
	
	rep(x,1,n+1){
		l[x]=l[x-1];
		
		if (arr[x]>l[x].fi) l[x].fi=arr[x];
		else if (arr[x]>l[x].se) l[x].se=arr[x];
		else l[x]={2e9,2e9};
	}
	
	rep(x,n+1,1){
		r[x]=r[x+1];
		
		if (arr[x]>r[x].fi) r[x].fi=arr[x];
		else if (arr[x]>r[x].se) r[x].se=arr[x];
		else r[x]={2e9,2e9};
	}
	
	int idx=-1;
	int mx=-1;
	rep(x,1,n+1){
		if (mx<arr[x]){
			mx=arr[x];
			idx=x;
		}
	}
	
	int ans=0;
	
	int hi=1e9+100,lo=r[idx].se,pp=1e9+99;
	rep(x,idx,1){
		if (arr[x+1]<pp){
			if (hi>pp) hi=pp;
			else if (lo<pp) lo=pp;
			else break;
		}
		else{
			if (lo<pp) lo=pp;
			else if (hi>pp) hi=pp;
			else break;
		}
		
		pp=arr[x+1];
		
		if (arr[x]==l[x].fi){
			if (lo<=l[x].fi && l[x].se<=hi && 
				(inside(l[x].se,hi,pp) || inside(lo,l[x].fi,pp))) ans++;
		}
		else if (arr[x]==l[x].se){
			if (lo<=l[x].se && l[x].fi<=hi
				&& (inside(lo,l[x].se,pp) || inside(l[x].fi,hi,pp))) ans++;
		}
	}
	
	hi=1e9+100,lo=l[idx].se,pp=1e9+99;
	rep(x,idx+1,n+1){
		if (arr[x-1]<pp){
			if (hi>pp) hi=pp;
			else if (lo<pp) lo=pp;
			else break;
		}
		else{
			if (lo<pp) lo=pp;
			else if (hi>pp) hi=pp;
			else break;
		}
		
		pp=arr[x-1];
		
		if (arr[x]==r[x].fi){
			if (lo<=r[x].fi && r[x].se<=hi && 
				(inside(r[x].se,hi,pp) || inside(lo,r[x].fi,pp))) ans++;
		}
		else if (arr[x]==r[x].se){
			if (lo<=r[x].se && r[x].fi<=hi
				&& (inside(lo,r[x].se,pp) || inside(r[x].fi,hi,pp))) ans++;
		}
	}
	
	cout<<ans<<endl;
}