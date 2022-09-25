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

vector<int> places={1,2,3,5,9,17};
vector<ll> ph;

int n,A,h;
int N;

map<int,int> m[2];

int arr[32];
void solve(int bm,int *arr){
	vector<int> v;
	rep(x,0,N/2) v.pub(x);
	
	int IDX=0;
	int pos=n;
	while (sz(v)!=1){
		vector<int> temp;
		rep(x,0,sz(v)/2){
			if (bm&(1<<IDX)){
				arr[v[x*2+1]]=places[pos];
				temp.pub(v[x*2]);
			}
			else{
				arr[v[x*2]]=places[pos];
				temp.pub(v[x*2+1]);
			}
			IDX++;
		}
		
		v=temp;
		pos--;
	}
	
	arr[v[0]]=places[pos];
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
	
	cin>>n>>A>>h;
	N=1<<n;
	
	for (auto &it:places) ph.pub(qexp(A,it,MOD));
	
	rep(bm,0,1<<((1<<(n-1))-1)){
		ll h1=0,h2=0;
		
		vector<int> v;
		rep(x,1,N/2+1) v.pub(x);
		
		int IDX=0;
		int pos=n;
		while (sz(v)!=1){
			vector<int> temp;
			rep(x,0,sz(v)/2){
				if (bm&(1<<IDX)){
					h1=fix(h1+ph[pos]*v[x*2+1]);
					h2=fix(h2+ph[pos]*(N/2+v[x*2+1]));
					temp.pub(v[x*2]);
				}
				else{
					h1=fix(h1+ph[pos]*v[x*2]);
					h2=fix(h2+ph[pos]*(N/2+v[x*2]));
					temp.pub(v[x*2+1]);
				}
				IDX++;
			}
			
			v=temp;
			pos--;
		}
		
		h1=fix(h1+ph[pos]*v[0]);
		h2=fix(h2+ph[pos]*(N/2+v[0]));
		
		m[0][h1]=bm;
		m[1][h2]=bm;
	}
	
	rep(bm,0,1<<((1<<(n-1))-1)){
		ll h1=0,h2=0;
		
		vector<int> v;
		rep(x,1,N/2+1) v.pub(x);
		
		int IDX=0;
		int pos=n;
		while (sz(v)!=1){
			vector<int> temp;
			rep(x,0,sz(v)/2){
				if (bm&(1<<IDX)){
					h1=fix(h1+ph[pos]*v[x*2+1]);
					h2=fix(h2+ph[pos]*(N/2+v[x*2+1]));
					temp.pub(v[x*2]);
				}
				else{
					h1=fix(h1+ph[pos]*v[x*2]);
					h2=fix(h2+ph[pos]*(N/2+v[x*2]));
					temp.pub(v[x*2+1]);
				}
				IDX++;
			}
			
			v=temp;
			pos--;
		}
		
		h1=fix(h1+ph[pos]*v[0]);
		h2=fix(h2+ph[pos]*(N/2+v[0]));
		
		if (m[1].count(fix(h-h1-v[0]*ph[0]+v[0]*ph[1]))){
			solve(bm,arr);
			solve(m[1][fix(h-h1-v[0]*ph[0]+v[0]*ph[1])],arr+(N/2));
			
			arr[v[0]-1]=1;
			rep(x,0,N) cout<<arr[x]<<" "; cout<<endl;
			return 0;
		}
		if (m[0].count(fix(h-h2-(N/2+v[0])*ph[0]+(N/2+v[0])*ph[1]))){
			solve(m[0][fix(h-h2-(N/2+v[0])*ph[0]+(N/2+v[0])*ph[1])],arr);
			solve(bm,arr+(N/2));
			
			arr[v[0]-1+N/2]=1;
			rep(x,0,N) cout<<arr[x]<<" "; cout<<endl;
			return 0;
		}
	}
	
	cout<<"-1"<<endl;
}