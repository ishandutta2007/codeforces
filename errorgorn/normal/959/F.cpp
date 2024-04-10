/*













*/

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

const int MOD=1000000007;

long long qexp(long long b,long long p,int m){
    long long res=1;
    while (p){
        if (p&1) res=(res*b)%m;
        b=(b*b)%m;
        p>>=1;
    }
    return res;
}


ll basis[62];
int sz;

void add_basis(ll i){
	rep(bit,0,62){
		if ((i&(1LL<<bit))==0) continue;
		
		if (basis[bit]==0){
			basis[bit]=i;
			sz++;
			return;
		}
		
		i^=basis[bit];
	}
}

bool check_basis(ll i){
	rep(bit,0,62){
		if ((i&(1LL<<bit))==0) continue;
		
		if (basis[bit]==0){
			return false;
		}
		
		i^=basis[bit];
	}
	
	return true;
}



struct Q{
	int idx;
	int l,x;
	
	Q(int a,int b,int c){
		l=a,x=b,idx=c;
	}
};

int n,q;
int arr[100005];
int ans[100005];
vector<Q> queries;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>q;
	rep(x,0,n) cin>>arr[x];
	
	int a,b;
	rep(x,0,q){
		cin>>a>>b;
		a--;
		queries.push_back(Q(a,b,x));
	}
	
	sort(all(queries),[](Q &i,Q &j){
		return i.l<j.l;
	});
	
	int curr=-1;
	for (auto &it:queries){
		while (curr<it.l){
			curr++;
			add_basis(arr[curr]);
		}
		
		if (check_basis(it.x)){
			ans[it.idx]=qexp(2,it.l-sz+1,MOD);
		}
	}
	
	rep(x,0,q) cout<<ans[x]<<endl;
}