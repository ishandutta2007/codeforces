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

int n,q,s,d;
int arr[200005];
vector<ii> edges;

int dist(int i,int j){
	return abs(d-abs(arr[j]-arr[i]));
}

struct Q{
	int pos;
	int k;
	int idx;
};
vector<Q> qu;

int ans[200005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>q>>s>>d;
	s--;
	
	rep(x,0,n) cin>>arr[x];
	
	rep(x,0,n){
		int lo=(x?arr[x-1]:-1e9);
		int hi=(x!=n-1?arr[x+1]:1e9);
		lo+=d,hi+=d;
		int lit=lb(arr,arr+n,lo)-arr;
		int hit=ub(arr,arr+n,hi)-arr;
		
		rep(y,max(0,lit-2),min(n,hit+2)){
			edges.pub(ii(x,y));
		}
	}
	
	int a,b;
	rep(x,0,q){
		cin>>a>>b;
		a--;
		qu.pub(Q({a,b,x}));
	}
	
	sort(all(edges),[](ii i,ii j){
		return dist(i.fi,i.se)>dist(j.fi,j.se);
	});
	
	sort(all(qu),[](Q i,Q j){
		return i.k<j.k;
	});
	
	for (auto &it:qu){
		while (!edges.empty() && dist(edges.back().fi,edges.back().se)<=it.k){
			dsu.unions(edges.back().fi,edges.back().se);
			//cout<<edges.back().fi<<" "<<edges.back().se<<endl;
			edges.pob();
		}
		
		ans[it.idx]=(dsu.parent(s)==dsu.parent(it.pos));
	}
	
	rep(x,0,q){
		if (ans[x]) cout<<"Yes"<<endl;
		else cout<<"No"<<endl;
	}
}