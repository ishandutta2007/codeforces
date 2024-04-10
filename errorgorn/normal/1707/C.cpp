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
#define ub upper_bound

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int n,m;
vector<ii> edges;
vector<int> al[100005];
int parent[100005][20];
int level[100005];

int _TIME=0;
int in[100005];
int out[100005];
void dfs(int i,int p){
	in[i]=++_TIME;
	
    int curr;
    for (auto it=al[i].begin();it!=al[i].end();it++){
        if (*it==p) continue;
        level[*it]=level[i]+1;
        parent[*it][0]=i;
        curr=i;
        for (int x=0;parent[curr][x]!=-1;x++){
            curr=parent[*it][x+1]=parent[curr][x];
        }
        dfs(*it,i);
    }
    
    out[i]=_TIME;
}

int mov(int i,int j){
    for (int x=0;x<20;x++){
        if (j&1){
            i=parent[i][x];
        }
        j>>=1;
    }
    return i;
}

int lca(int i,int j){
    if (level[i]<level[j]) swap(i,j);
    i=mov(i,level[i]-level[j]);
    if (i==j) return i;
    for (int x=19;x>=0;x--){
        if (parent[i][x]!=parent[j][x]){
            i=parent[i][x];
            j=parent[j][x];
        }
    }
    return parent[i][0];
}

struct ufds{
    int p[100005];
    int r[100005];

    ufds(){
        for (int x=0;x<100005;x++){
            p[x]=x;
            r[x]=0;
        }
    }
    int parent(int i){return (p[i]==i)?i:p[i]=parent(p[i]);}
    bool unions(int i,int j){
        i=parent(i),j=parent(j);
        if (i==j) return false;
        if (r[i]<r[j]){
            p[i]=j;
        }
        else{
            p[j]=i;
            if (r[i]==r[j]) r[i]++;
        }
        
        return true;
    }
} dsu=ufds();

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
	
	void update(int i,int j,int k){
		if (s==i && e==j) val+=k;
		else if (j<=m) l->update(i,j,k);
		else if (m<i) r->update(i,j,k);
		else l->update(i,m,k),r->update(m+1,j,k);
	}
	
	int query(int i){
		if (s==e) return val;
		else if (i<=m) return l->query(i)+val;
		else return r->query(i)+val;
	}
} *root=new node(0,100005);

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	//take the minimum spanning tree
	//when you root the tree, there should not be any cross edges
	
	cin>>n>>m;
	
	int a,b;
	rep(x,0,m){
		cin>>a>>b;
		
		if (dsu.unions(a,b)){
			al[a].pub(b);
			al[b].pub(a);
		}
		else{
			edges.pub(ii(a,b));
		}
	}
	
	memset(parent,-1,sizeof(parent));
	dfs(1,-1);
	
	//rep(x,1,n+1) cout<<in[x]<<" "; cout<<endl;
	
	for (auto &it:edges){
		tie(a,b)=it;
		if (in[a]>in[b]) swap(a,b);
		
		//cout<<a<<" "<<b<<endl;
		
		if (out[b]<=out[a]){ //ancestor
			a=mov(b,level[b]-level[a]-1);
			root->update(in[a],out[a],1);
			root->update(in[b],out[b],-1);
		}
		else{
			root->update(in[1],out[1],1);
			root->update(in[a],out[a],-1);
			root->update(in[b],out[b],-1);
		}
	}
	
	rep(x,1,n+1){
		if (root->query(in[x])) cout<<"0";
		else cout<<"1";
	}
}