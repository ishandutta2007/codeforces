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

const int INF=1e9;

struct node{
	int s,e,m;
	ii val=ii(INF,INF);
	node *l,*r;
	
	node(int _s,int _e){
		s=_s,e=_e,m=s+e>>1;
		if (s!=e){
			l=new node(s,m);
			r=new node(m+1,e);
		}
	}
	
	void update(int i,ii j){
		if (s==e) val=j;
		else{
			if (i<=m) l->update(i,j);
			else r->update(i,j);
			
			val=min(l->val,r->val);
		}
	}
	
	ii query(int i,int j){
		if (s==i && e==j) return val;
		else if (j<=m) return l->query(i,j);
		else if (m<i) return r->query(i,j);
		else return min(l->query(i,m),r->query(m+1,j));
	}
}*root=new node(0,200005);

int n;
ii arr[200005];
vector<iii> v;
int pos[200005];
int ans[200005];
int ans2[200005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	
	rep(x,0,n){
		cin>>arr[x].fi>>arr[x].se;
		v.push_back(iii(arr[x],x));
	}
	
	sort(all(v),[](iii i,iii j){
		return i.fi.fi>j.fi.fi;
	});
	
	priority_queue<ii,vector<ii>,greater<ii> > pq;
	rep(x,1,n+1){
		while (!v.empty() && v.back().fi.fi==x){
			pq.push(ii(v.back().fi.se,v.back().se));
			v.pop_back();
		}
		
		pos[x]=pq.top().se;
		ans[pq.top().se]=x;
		pq.pop();
		
		root->update(x,ii(arr[pos[x]].fi,x));
	}
	
	bool bad=false;
	rep(x,1,n){
		if (x==arr[pos[x]].se) continue;
		ii temp=root->query(x+1,arr[pos[x]].se);
		//cout<<temp.first<<" "<<temp.second<<endl;
		if (temp.fi<=x){
			bad=true;
			swap(pos[x],pos[temp.se]);
			rep(x,1,n+1) ans2[pos[x]]=x;
			break;
		}
	}
	
	if (bad) cout<<"NO"<<endl;
	else cout<<"YES"<<endl;
	
	rep(x,0,n) cout<<ans[x]<<" ";
	cout<<endl;
	
	if (bad) rep(x,0,n) cout<<ans2[x]<<" ";
	
}