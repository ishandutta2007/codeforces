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

struct node{
	int s,e,m;
	ll val,lazy=0,cnt,qtime=0,ans=0;
	node *l,*r;
	
	node (int _s,int _e){
		s=_s,e=_e,m=s+e>>1;
		
		if (s!=e){
			l=new node(s,m);
			r=new node(m+1,e);
			
			val=min(l->val,r->val);
			cnt=(val==l->val?l->cnt:0)+(val==r->val?r->cnt:0);
		}
		else{
			val=s;
			cnt=1;
		}
	}
	
	ll get(){
		return val+lazy;
	}
	
	void propo(){
		if (lazy){
			val+=lazy;
			
			if (s!=e){
				l->lazy+=lazy;
				r->lazy+=lazy;
			}
			
			lazy=0;
		}
		if (time){
			if (s!=e){
				if (l->get()<=r->get()) l->qtime+=qtime;
				if (r->get()<=l->get()) r->qtime+=qtime;
			}
			
			ans+=qtime*cnt;
			qtime=0;
		}
	}
	
	void update(int i,int j,ll k){
		propo();
		
		if (s==i && e==j) lazy+=k;
		else{
			if (j<=m) l->update(i,j,k);
			else if (m<i) r->update(i,j,k);
			else l->update(i,m,k),r->update(m+1,j,k);
			
			l->propo(),r->propo();
			
			val=min(l->val,r->val);
			cnt=(val==l->val?l->cnt:0)+(val==r->val?r->cnt:0);
		}
	}
	
	ll query(int i,int j){
		propo();
		
		if (s==i && e==j) return ans;
		else if (j<=m) return l->query(i,j);
		else if (m<i) return r->query(i,j);
		else return l->query(i,m)+r->query(m+1,j);
	}
} *root=new node(0,120005);

int n,q;
int arr[120005];
ll ans[120005];

struct range{
	int l,r;
	int id;
	
	range(int a,int b,int c){
		l=a,r=b;
		id=c;
	}
};
 
vector<range> Q;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	rep(x,0,n) cin>>arr[x];
	
	cin>>q;
	int a,b;
	rep(x,0,q){
		cin>>a>>b;
		a--,b--;
		
		Q.push_back(range(a,b,x));
	}
	
	sort(all(Q),[](range &i,range &j){
		return i.r<j.r;
	});
	
	int curr=-1;
	vector<int> mx={-1},mn={-1};
	for (auto &it:Q){
		while (curr<it.r){
			curr++;
			
			while (mx.back()!=-1 && arr[mx.back()]<arr[curr]){
				int temp=mx.back();
				mx.pop_back();
				root->update(mx.back()+1,temp,arr[curr]-arr[temp]);
			}
			mx.push_back(curr);
			
			while (mn.back()!=-1 && arr[mn.back()]>arr[curr]){
				int temp=mn.back();
				mn.pop_back();
				root->update(mn.back()+1,temp,arr[temp]-arr[curr]);
			}
			mn.push_back(curr);
			
			root->update(0,120005,-1);
			root->qtime++;
		}
		
		ans[it.id]=root->query(it.l,it.r);
	}
	
	rep(x,0,q) cout<<ans[x]<<endl;
}