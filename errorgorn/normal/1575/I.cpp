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

const int MOD=998244353;

ll qexp(ll b,ll p,int m){
    ll res=1;
    while (p){
        if (p&1) res=(res*b)%m;
        b=(b*b)%m;
        p>>=1;
    }
    return res;
}

ll inv(ll i){
	return qexp(i,MOD-2,MOD);
}

ll fix(ll i){
	i%=MOD;
	if (i<0) i+=MOD;
	return i;
}

ll fac[1000005];
ll ifac[1000005];

ll nCk(int i,int j){
	if (i<j) return 0;
	return fac[i]*ifac[j]%MOD*ifac[i-j]%MOD;
}

struct node{
    int s,e,m;
    ll val;
    node *l,*r;
    
    node (int _s,int _e){
    	s=_s,e=_e,m=s+e>>1;
    	
    	if (s!=e){
    		l=new node(s,m);
    		r=new node(m+1,e);
    	}
    }
    
    void update(int i,int j){
    	if (s==e) val=j;
    	else{
    		if (i<=m) l->update(i,j);
    		else r->update(i,j);
    		
    		val=l->val+r->val;
    	}
    }
    
    ll query(int i,int j){
    	if (s==i && e==j) return val;
    	else if (j<=m) return l->query(i,j);
    	else if (m<i) return r->query(i,j);
    	else return l->query(i,m)+r->query(m+1,j);
    }
}*root=new node(0,100005);

int n,q; //size of tree
int arr[100005];

vector<int> al[100005]; //adj list
int in[100005]; //preorder
int out[100005]; //postorder
int st[100005]; //subtree size
int parent[100005]; //first parent
int hparent[100005]; //parent on heavy path
int fchild[100005];
int depth[100005];
void dfs_st(int i,int p){
    parent[i]=p;
    st[i]=1;
    if (al[i][0]==p && al[i].size()>1) swap(al[i][0],al[i][1]);
    for (auto &it:al[i]){ ///& is important here
        if (it==p) continue;
        depth[it]=depth[i]+1;
        dfs_st(it,i);
        st[i]+=st[it];
        if (st[it]>st[al[i][0]]){
            swap(it,al[i][0]);
            //we ensure heavy child is al[i][0]
        }
    }
}

int dfs_time=0;
void dfs_hld(int i,int p){
    in[i]=++dfs_time;
    for (auto it:al[i]){
        if (it==p) continue;
        hparent[it]=(it==al[i][0])?hparent[i]:it;
        if (it==al[i][0]) fchild[i]=it;
        dfs_hld(it,i);
    }
    out[i]=dfs_time;
}

void upd(int i){
	if (i==1) return;
	//cout<<i<<" "<<max(arr[parent[i]]+arr[i],arr[parent[i]]-arr[i])<<endl;
	root->update(in[i],max(abs(arr[parent[i]]+arr[i]),abs(arr[parent[i]]-arr[i])));
}

ll hld_query(int i,int j){
    ll ans=0;
    while (hparent[i]!=hparent[j]){
        if (depth[hparent[i]]<depth[hparent[j]]) swap(i,j);
        upd(hparent[i]);
        ans+=root->query(in[hparent[i]],in[i]);
        i=parent[hparent[i]];
    }
    if (in[i]>in[j]) swap(i,j);
    if (in[i]!=in[j]) ans+=root->query(in[i]+1,in[j]);
    return ans;
}


int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	fac[0]=1;
	rep(x,1,1000005) fac[x]=fac[x-1]*x%MOD;
	ifac[1000004]=inv(fac[1000004]);
	rep(x,1000005,1) ifac[x-1]=ifac[x]*x%MOD;
	
	cin>>n>>q;
	rep(x,1,n+1) cin>>arr[x];
	
	int a,b;
	rep(x,0,n-1){
		cin>>a>>b;
		
		al[a].pub(b);
		al[b].pub(a);
	}
	
	parent[1]=0;
	hparent[1]=1;
	if (n>=2){
	    dfs_st(1,-1);
	    dfs_hld(1,-1);
	}
	
	rep(x,1,n+1){
		upd(x);
	}
	
	while (q--){
		cin>>a;
		
		if (a==1){
			cin>>a>>b;
			arr[a]=b;
			
			upd(a);
			if (fchild[a]) upd(fchild[a]);
		}
		else{
			cin>>a>>b;
			cout<<hld_query(a,b)<<endl;
		}
	}
}