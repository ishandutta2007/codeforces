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
#define iii pair<ll,ii>
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

struct ufds{
    int p[200005];
    int r[200005];

    ufds(){
        for (int x=0;x<200005;x++){
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
}dsu=ufds();


int n,m;
int arr[100005];
int brr[100005];

vector<iii> edges;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>m;
	rep(x,0,n) cin>>arr[x];
	rep(x,0,m) cin>>brr[x];
	
	int q,k;
	rep(x,0,n){
		cin>>q;
		rep(y,0,q){
			cin>>k;
			k--;
			
			edges.push_back(iii(arr[x]+brr[k],ii(x+100000,k)));
		}
	}
	
	sort(all(edges));
	reverse(all(edges));
	
	ll ans=0;
	for (auto &it:edges){
		//cout<<it.fi<<" "<<it.se.fi<<" "<<it.se.se<<endl;
		if (!dsu.unions(it.se.fi,it.se.se)) ans+=it.fi;
	}
	cout<<ans<<endl;
}