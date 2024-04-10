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

#define pub push_back
#define pob pop_back
#define puf push_front
#define pof pop_front
#define lb lower_bound
#define up upper_bound

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int n,m,q;
int w[100005];
vector<int> al[100005];
vector<int> cjk[200005];

int cnt;
int TIME=1;
int in1[100005];
int low[100005];
vector<int> stk;

void dfs(int i,int p){
    in1[i]=low[i]=TIME++;
    stk.pub(i);
    
    for (auto &it:al[i]){
        if (it==p) continue; //assume no multiedge
        
        if (in1[it]==0){ //not visited
            dfs(it,i);
            low[i]=min(low[i],low[it]);
            
            //check if there is a BCC on (i,it)
            if (low[it]>=in1[i]){ //there is BCC
                //cnt is the index of new square vertice
                while (true){
                    int temp=stk.back();
                    cjk[cnt].pub(temp);
                    stk.pob();
                    if (temp==it) break; 
                    //we popped everything in BCC
                }
                cjk[i].pub(cnt);
                cnt++;
            }
        }
        else{ //visited
            low[i]=min(low[i],in1[it]);
        }
    }
}

int in[200005]; //preorder
int out[200005]; //postorder
int st[200005]; //subtree size
int parent[200005]; //first parent
int hparent[200005]; //parent on heavy path
int depth[200005];
void dfs_st(int i,int p){
    parent[i]=p;
    st[i]=1;
    for (auto &it:cjk[i]){ ///& is important here
        if (it==p) continue;
        depth[it]=depth[i]+1;
        dfs_st(it,i);
        st[i]+=st[it];
        if (st[it]>st[cjk[i][0]]){
            swap(it,cjk[i][0]);
            //we ensure heavy child is cjk[i][0]
        }
    }
}

int dfs_time=0;
void dfs_hld(int i){
    in[i]=++dfs_time;
    for (auto it:cjk[i]){
        hparent[it]=(it==cjk[i][0])?hparent[i]:it;
        dfs_hld(it);
    }
    out[i]=dfs_time;
}

struct node{
    int s,e,m;
    int val=2e9;
    node *l,*r;
    
    node (int _s,int _e){
    	s=_s,e=_e,m=s+e>>1;
    	
    	if (s!=e){
    		l=new node(s,m);
    		r=new node(m+1,e);
    	}
    }
    
    void update(int i,int k){
    	if (s==e) val=k;
    	else{
    		if (i<=m) l->update(i,k);
    		else r->update(i,k);
    		
    		val=min(l->val,r->val);
    	}
    }
    
    int query(int i,int j){
    	if (s==i && e==j) return val;
    	else if (j<=m) return l->query(i,j);
    	else if (m<i) return r->query(i,j);
    	else return min(l->query(i,m),r->query(m+1,j));
    }
}*root=new node(0,200005);

multiset<int> se[200005];

int hld_query(int i,int j){
    int ans=2e9;
    while (hparent[i]!=hparent[j]){
        if (depth[hparent[i]]<depth[hparent[j]]) swap(i,j);
        ans=min(ans,root->query(in[hparent[i]],in[i]));
        i=parent[hparent[i]];
    }
    if (in[i]>in[j]) swap(i,j);
    ans=min(ans,root->query(in[i],in[j]));
    
    if (i>n) ans=min(ans,*se[parent[i]].begin());
    
    return ans;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>m>>q;
	rep(x,1,n+1) cin>>w[x];
	
	int a,b;
	rep(x,0,m){
		cin>>a>>b;
		al[a].pub(b);
		al[b].pub(a);
	}
	
	cnt=n+1;
	dfs(1,-1);
	
	parent[1]=0;
	hparent[1]=1;
	dfs_st(1,0);
	dfs_hld(1);
	
	root->update(in[1],0);
	
	rep(x,1,n+1){
		se[x].insert(w[x]);
		se[parent[x]].insert(w[x]);
	}
	
	rep(x,1,cnt) root->update(in[x],*se[x].begin());
	
	char c;
	while (q--){
		cin>>c;
		cin>>a>>b;
		
		if (c=='A'){
			cout<<hld_query(a,b)<<endl;
		}
		else{
			se[a].erase(se[a].find(w[a]));
			se[parent[a]].erase(se[parent[a]].find(w[a]));
			
			w[a]=b;
			
			se[a].insert(w[a]);
			se[parent[a]].insert(w[a]);
			
			root->update(in[a],*se[a].begin());
			root->update(in[parent[a]],*se[parent[a]].begin());
		}
	}
}