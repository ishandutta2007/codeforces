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

int n,q;
vector<int> fac[1000005];
int arr[150005];

vector<int> p[1000005];

struct ufds{
    int p[150005];
    int r[150005];

    ufds(){
        for (int x=0;x<150005;x++){
            p[x]=x;
            r[x]=0;
        }
    }
    int parent(int i){return (p[i]==i)?i:p[i]=parent(p[i]);}
    void unions(int i,int j){
        i=parent(i),j=parent(j);
        if (i==j) return;
        if (r[i]<r[j]){
            p[i]=j;
        }
        else{
            p[j]=i;
            if (r[i]==r[j]) r[i]++;
        }
    }
} dsu=ufds();

set<ii> reach;
int id[1000005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	memset(id,-1,sizeof(id));
	
	rep(x,2,1000005) if (fac[x].empty()){
		for (int y=x;y<1000005;y+=x) fac[y].pub(x);
	}
	
	cin>>n>>q;
	rep(x,0,n){
		cin>>arr[x];
		id[arr[x]]=x;
	}
	
	rep(x,0,n){
		for (auto &it:fac[arr[x]]) p[it].pub(x);
	}
	
	rep(x,0,1000005) if (sz(p[x])){
		rep(y,1,sz(p[x])) dsu.unions(p[x][0],p[x][y]);
	}
	
	rep(x,0,1000005) if (sz(p[x])){
		for (int y=x;y<1000005;y+=x){
			if (id[y-1]!=-1){
				reach.insert(ii(dsu.parent(p[x][0]),dsu.parent(id[y-1])));
			}
		}
	}
	
	rep(x,0,1000005) if (sz(fac[x])==2){
		bool can=false;
		for (int y=x;y<1000005;y+=x){
			if (id[y-1]!=-1) can=true;
		}
		
		if (can){
			int a=fac[x][0],b=fac[x][1];
			if (!p[a].empty() && !p[b].empty()){
				reach.insert(ii(dsu.parent(p[a][0]),dsu.parent(p[b][0])));
			}
		}
	}
	
	int a,b;
	while (q--){
		cin>>a>>b;
		
		a--,b--;
		int pa=dsu.parent(a),pb=dsu.parent(b);
		
		if (pa==pb){
			cout<<0<<endl;
		}
		else if (reach.count(ii(pb,pa)) || reach.count(ii(pa,pb))){
			cout<<1<<endl;
		}
		else{
			cout<<2<<endl;
		}
	}
}