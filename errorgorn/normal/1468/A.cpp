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

int n;
int arr[500005];

struct node{
	int s,e,m;
	int val=0;
	node *l,*r;
	
	node (int _s,int _e){
		s=_s,e=_e,m=s+e>>1;
		
		if (s!=e){
			l=new node(s,m);
			r=new node(m+1,e);
		}
	}
	
	void update(int i,int j){
		val=max(val,j);
		
		if (s==e) return;
		if (i<=m) l->update(i,j);
		else r->update(i,j);
	}
	
	int query(int i,int j){
		if (s==i && e==j) return val;
		else if (j<=m) return l->query(i,j);
		else if (m<i) return r->query(i,j);
		else return max(l->query(i,m),r->query(m+1,j));
	}
} *root;

priority_queue<ii,vector<ii>,greater<ii> > pq;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n;
		n++;
		
		while (!pq.empty()) pq.pop();
		root=new node(0,n+5);
		
		arr[0]=0;
		rep(x,1,n) cin>>arr[x];
		
		rep(x,0,n){
			int temp=root->query(0,arr[x]);
			//cout<<"debug: "<<temp<<endl;
			root->update(arr[x],temp+1);
			
			while (!pq.empty() && pq.top().fi<=arr[x]){
				root->update(pq.top().fi,pq.top().se+1);
				pq.pop();
			}
			
			pq.push(ii(arr[x],temp+1));
		}
		
		cout<<root->query(0,n+5)-1<<endl;
	}
	
}