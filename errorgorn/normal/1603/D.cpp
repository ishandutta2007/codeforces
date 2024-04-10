//
//

//#pragma GCC optimize("O3,unroll-loops")
//#pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>
using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;
#define ll long long
#define ii pair<int,int>
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

const int B=340;
const int SZ=100005;

vector<int> fac[100005];

ll g[100005];
int big[100005][B+5];
int bigr[100005][B+5];
int small[100005][B+5];

ll c(int l,int r){
	if (l<B) return g[r/l]+small[r][l];
	else return (bigr[r][r/l]-l+1)*g[r/l]+big[r][r/l];
}

ll memo[19][100005];

void dnc(int layer,int l,int r,int optl,int optr){
	if (l>r) return;
	int m=l+r>>1;
	
	int optm=-1;
	rep(x,optl,min(m,optr)+1){
		if (memo[layer+1][m]>memo[layer][x-1]+c(x,m)){
			memo[layer+1][m]=memo[layer][x-1]+c(x,m);
			optm=x;
		}
	}
	
	dnc(layer,l,m-1,optl,optm);
	dnc(layer,m+1,r,optm,optr);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	rep(x,2,100005){
		int curr=x;
		if (fac[x].empty()) for (int y=x;y<100005;y+=x) fac[y].pub(x);
		for (auto &it:fac[x]) curr=(curr/it)*(it-1);
		g[x]=g[x-1]+curr;
	}
	
	rep(x,1,SZ){
		int r=x;
		ll curr=0;
		
		rep (y,1,B){
			int l=max(B,(x+y+1)/(y+1));
			
			if (l<=r){
				big[x][y]=curr;
				bigr[x][y]=r;
				curr+=(r-l+1)*g[y];
				r=l-1;
			}
		}
		while (r){
			small[x][r]=curr;
			curr+=g[x/r];
			r--;
		}
	}
	
	memset(memo,63,sizeof(memo));
	memo[0][0]=0;
	
	rep(layer,0,18){
		dnc(layer,1+layer,100000,1,100000);
	}
	
	int TC;
	cin>>TC;
	while (TC--){
		int n,k;
		cin>>n>>k;
		
		if (k>=17) cout<<n<<endl;
		else cout<<memo[k][n]+n<<endl;
	}
}