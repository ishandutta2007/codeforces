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

ll n,k;
ii arr[2005];
int perm[2005];
int pos[2005];

#define di pair<double,ii>
vector<di> v;

ll area(int i,int j,int k){
	return arr[i].fi*arr[j].se+arr[j].fi*arr[k].se+arr[k].fi*arr[i].se
			-arr[i].se*arr[j].fi-arr[j].se*arr[k].fi-arr[k].se*arr[i].fi;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>k;
	k*=2;
	rep(x,0,n) cin>>arr[x].fi>>arr[x].se;
	rep(x,0,n) perm[x]=x;
	
	sort(perm,perm+n,[](int i,int j){
		if (arr[i].fi!=arr[j].fi) return arr[i].fi<arr[j].fi;
		else return arr[i].se>arr[j].se;
	});
	
	//rep(x,0,n) cout<<perm[x]<<" "; cout<<endl;
	rep(x,0,n) pos[perm[x]]=x;
	
	rep(x,0,n){
		rep(y,x+1,n){
			double val;
			if (arr[x].fi==arr[y].fi) val=-1.0/0;
			else val=(double)(arr[x].se-arr[y].se)/(arr[x].fi-arr[y].fi);
			
			v.push_back({val,{x,y}});
		}
	}
	
	sort(all(v));
	//for (auto &it:v) cout<<it.fi<<" "; cout<<endl;
	
	for (auto &it:v){
		int a=it.se.fi,b=it.se.se;
		if (pos[a]>pos[b]) swap(a,b);
		//cout<<a<<" "<<b<<endl;
		
		ll lo,hi,mi;
		
		lo=-1,hi=pos[a]-1;
		while (hi-lo>1){
			mi=hi+lo>>1;
			if (area(a,b,perm[mi])>k) lo=mi;
			else hi=mi;
		}
		if (hi!=-1 && area(a,b,perm[hi])==k){
			cout<<"Yes"<<endl;
			cout<<arr[a].fi<<" "<<arr[a].se<<endl;
			cout<<arr[b].fi<<" "<<arr[b].se<<endl;
			cout<<arr[perm[hi]].fi<<" "<<arr[perm[hi]].se<<endl;
			return 0;
		}
		
		lo=pos[b]+1,hi=n;
		while (hi-lo>1){
			mi=hi+lo>>1;
			if (area(a,b,perm[mi])>k) hi=mi;
			else lo=mi;
		}
		if (lo!=n && area(a,b,perm[lo])==k){
			cout<<"Yes"<<endl;
			cout<<arr[a].fi<<" "<<arr[a].se<<endl;
			cout<<arr[b].fi<<" "<<arr[b].se<<endl;
			cout<<arr[perm[lo]].fi<<" "<<arr[perm[lo]].se<<endl;
			return 0;
		}
		
		swap(pos[a],pos[b]);
		swap(perm[pos[a]],perm[pos[b]]);
		
		//rep(x,0,n) cout<<perm[x]<<" "; cout<<endl;
	}
	cout<<"No"<<endl;
}