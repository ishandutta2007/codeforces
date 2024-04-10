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

struct ufds{
    int p[100005];

    ufds(){
        for (int x=0;x<100005;x++){
            p[x]=x;
        }
    }
    int parent(int i){return (p[i]==i)?i:p[i]=parent(p[i]);}
    void unions(int i,int j){
        i=parent(i),j=parent(j);
        if (i==j) return;
        p[j]=i;
    }
} dsu=ufds(),dsu2=ufds();

int n,m1,m2;

set<int> roots;
map<int,int> m[100005]; //the distinct guys of dsu2

void redo(int i){
	map<int,int> temp;
	for (auto it:m[i]){
		temp[dsu2.parent(it.fi)]=it.se;
	}
	m[i]=temp;
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
	
	cin>>n>>m1>>m2;
	
	int a,b;
	rep(x,0,m1){
		cin>>a>>b;	
		dsu.unions(a,b);
	}
	rep(x,0,m2){
		cin>>a>>b;	
		dsu2.unions(a,b);
	}
	
	rep(x,1,n+1){
		if (dsu.parent(x)==x) roots.insert(x);
		m[dsu.parent(x)][dsu2.parent(x)]=x;
	}
	
	// for (auto &it:roots){
		// cout<<it<<endl;
		// for (auto &it2:m[it]) cout<<it2.fi<<" "<<it2.se<<endl;
	// }
	
	vector<ii> ans;
	rep(x,1,n+1) if (roots.count(x)){
		redo(x);
		
		vector<int> rem;
		for (auto it:roots) if (it!=x){
			if (sz(m[x])==1) break;
			
			int a=(*m[x].begin()).fi;
			int b=(*++m[x].begin()).fi;
			
			redo(it);
			
			int c=(*m[it].begin()).fi;
			
			if (a==c) swap(a,b);
			
			ans.pub(ii(m[x][a],m[it][c]));
			
			dsu2.unions(a,c);
			
			rem.pub(it);
			m[x].erase(c);
			m[it].erase(c);
			
			if (sz(m[x])<sz(m[it])) swap(m[x],m[it]);
			for (auto it2:m[it]){
				assert(dsu2.parent(it2.fi)==it2.fi);
				m[x][it2.fi]=it2.se;
			}
		}
		
		for (auto it:rem) roots.erase(it);
	}
	
	// cout<<endl;
	// for (auto &it:roots){
		// cout<<it<<endl;
		// for (auto &it2:m[it]) cout<<it2.fi<<" "<<it2.se<<endl;
	// }
		
	if (sz(roots)!=1){
		map<int,int> temp;
		for (auto &it:roots){
			int a=(*m[it].begin()).fi,b=(*m[it].begin()).se;
			temp[dsu2.parent(a)]=b;
		}
		
		vector<int> v;
		for (auto &it:temp) v.pub(it.se);
		
		rep(x,1,sz(v)) ans.pub(ii(v[0],v[x]));
	}
	
	cout<<sz(ans)<<endl;
	for (auto &it:ans) cout<<it.fi<<" "<<it.se<<endl;
}