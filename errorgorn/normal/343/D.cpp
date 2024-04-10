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
	int state=0;
	node *l,*r;
	
	node (int _s,int _e){
		s=_s,e=_e,m=s+e>>1;
		
		if (s!=e){
			l=new node(s,m);
			r=new node(m+1,e);
		}
	}
	
	void update(int i,int j,int k){
		if (s==i && e==j) state=k;
		else{
			if (state!=-1) l->state=r->state=state;
			state=-1;
			
			if (j<=m) l->update(i,j,k);
			else if (m<i) r->update(i,j,k);
			else l->update(i,m,k),r->update(m+1,j,k);
		}
	}
	
	int query(int i){
		if (state!=-1) return state;
		else if (i<=m) return l->query(i);
		else return r->query(i);
	}
}*root=new node(0,500005);

int n,q;
vector<int> al[500005];

int in[500005]; //preorder
int out[500005]; //postorder
int st[500005]; //subtree size
int parent[500005]; //first parent
int hparent[500005]; //parent on heavy path
int depth[500005];
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
        dfs_hld(it,i);
    }
    out[i]=dfs_time;
}



int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	
	int a,b;
	rep(x,1,n){
		cin>>a>>b;
		al[a].push_back(b);
		al[b].push_back(a);
	}
	
	parent[1]=0;
	hparent[1]=1;
	if (n>=2){
    	dfs_st(1,-1);
		dfs_hld(1,-1);
	}
	
	cin>>q;
	
	while (q--){
		cin>>a>>b;
		
		if (a==1){
			root->update(in[b],out[b],1);
		}
		else if (a==2){
			while (b){
				root->update(in[hparent[b]],in[b],0);
				b=parent[hparent[b]];
			}
		}
		else{
			cout<<root->query(in[b])<<endl;
		}
	}

}