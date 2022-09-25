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

#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
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

struct node{
	int s,e,m;
	vector<ii> val;
	node *l=nullptr,*r=nullptr;
	
	node (int _s,int _e){
		s=_s,e=_e,m=s+e>>1;
	}
	
	int count(int l,int r){
		return ub(all(val),ii(r,2e9))-lb(all(val),ii(l,0));
	}
	
	void ins(int i,int k){
		val.pub({k,i});
		
		if (s==e) return;
		
		if (i<=m){
			if (l==nullptr) l=new node(s,m);
			l->ins(i,k);
		}
		else{
			if (r==nullptr) r=new node(m+1,e);
			r->ins(i,k);
		}
	}
} *root;

int n,q;
int arr[100005];

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		root=new node(0,(1<<30)-1);
		
		cin>>n;
		rep(x,1,n+1) cin>>arr[x];
		rep(x,1,n+1) root->ins(arr[x],x);
		
		cin>>q;
		
		int a,b;
		rep(x,0,q){
			cin>>a>>b;
			
			int ans=0;
			
			vector<int> v;
			node* curr=root;
			rep(x,30,0){
				int tl=0,r=0;
				
				
				if (curr!=nullptr){
					tl=curr->l==nullptr?0:curr->l->count(a,b);
					r=curr->r==nullptr?0:curr->r->count(a,b);
				}
				
				int l=tl;
				
				for (auto it:v){
					if (it&(1<<x)) r++;
					else l++;
				}
				
				vector<int> temp;
				
				// cout<<x<<" "<<l<<" "<<r<<endl;
				// if (curr!=nullptr) cout<<curr->s<<" "<<curr->e<<endl;
				// for (auto it:v) cout<<it<<" "; cout<<endl;
				// cout<<endl;
				
				if (l>=2){ //everything go to l
					if (curr!=nullptr) curr=curr->l;
					for (auto it:v){
						if ((it&(1<<x))==0) temp.pub(it);
					}
				}
				else if (l==0){ //everything go to r
					ans|=(1<<x);
				
					if (curr!=nullptr) curr=curr->r;
					for (auto it:v){
						if (it&(1<<x)) temp.pub(it);
					}
				}
				else{
					ans|=(1<<x);
					
					if (tl==1){
						v.pub((*lb(all(curr->l->val),ii(a,0))).se);
					}
					swap(temp,v);
					
					if (curr!=nullptr) curr=curr->r;
				}
				
				swap(temp,v);
			}
			
			cout<<ans<<endl;
		}
	}
}