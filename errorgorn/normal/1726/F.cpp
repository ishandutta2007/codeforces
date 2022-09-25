//
//
//
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

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

const int INF=1e18;

int n,k;
ii arr[200005];
int d[200005];

vector<ii> compress(vector<ii> v){
	sort(all(v));
	
	vector<ii> temp;
	for (auto it:v){
		if (!temp.empty() && it.fi<=temp.back().se) temp.back().se=max(temp.back().se,it.se);
		else temp.pub(it);
	}
	
	return temp;
}

vector<ii> invert(vector<ii> v){
	sort(all(v));
	
	if (v.empty()) return {{0,k-1}};
	
	vector<ii> temp;
	if (v.front().fi!=0) temp.pub({0,v.front().fi-1});
	rep(x,0,sz(v)-1) if (v[x].se+1<=v[x+1].fi-1) temp.pub({v[x].se+1,v[x+1].fi-1});
	if (v.back().se!=k-1) temp.pub({v.back().se+1,k-1});
	
	return temp;
}

struct node{
	int s,e,m;
	vector<ii> v;
	node *l,*r;
	
	node (int _s,int _e){
		s=_s,e=_e,m=s+e>>1;
		
		if (s!=e){
			l=new node(s,m);
			r=new node(m+1,e);
			
			for (auto it:invert(l->v)) v.pub(it);
			for (auto it:invert(r->v)) v.pub(it);
			v=invert(compress(v));
		}
		else{
			if (s==n+1) ; //nothing
			else if (arr[s].fi<=arr[s].se) v.pub({arr[s].fi,arr[s].se});
			else v.pub({0,arr[s].se}),v.pub({arr[s].fi,k-1});
		}
		
		// cout<<s<<" "<<e<<endl;
		// for (auto [a,b]:v) cout<<a<<"_"<<b<<" "; cout<<endl;
	}
	
	bool has(int t){
		auto it=ub(all(v),ii(t,INF));
		return (it!=v.begin() && t<=(*prev(it)).se);
	}
	
	int get(int i,int k){
		if (has(k)) return -1;
		if (s==e) return s;
		if (m<i) return r->get(i,k);
		else{
			int temp=l->get(i,k);
			if (temp==-1) return r->get(i,k);
			else return temp;
		}
	}
} *root;

int dist(int i,int j){
	return (j-i+k)%k;
}

int cost[200005];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>k;
	rep(x,1,n+1) cin>>arr[x].fi>>arr[x].se;
	rep(x,2,n+1) cin>>d[x];
	rep(x,2,n+1) d[x]+=d[x-1];
	rep(x,1,n+1) arr[x].se=(arr[x].se+d[x])%k;
	
	
	rep(x,1,n+1){
		//cout<<arr[x].fi<<" "<<arr[x].se<<endl;
		int l=(k-arr[x].se)%k,r=(k+arr[x].fi-1-arr[x].se)%k;
		arr[x]={l,r};
		
		//cout<<x<<" "<<l<<" "<<r<<endl;
	}
	
	root=new node(1,n+1);
	
	rep(x,n+1,1){
		int r=root->get(x,arr[x].fi);
		if (r!=n+1) cost[x]=cost[r]+dist(arr[x].fi,arr[r].fi);
	}
	
	//rep(x,1,n+1) cout<<cost[x]<<" "; cout<<endl;
	
	//it is only optimal go at a right endpoint (or else shift to nearest right endpoint)
	int ans=1e18;
	rep(x,1,n+1){
		int r=root->get(1,arr[x].se);
		
		if (r==n+1) ans=0;
		else{
			ans=min(ans,cost[r]+dist(arr[x].se,arr[r].fi));
		}
	}
	
	cout<<ans+d[n]<<endl;
	
}