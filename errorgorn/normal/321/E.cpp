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

int n,k;
int pref[4005][4005];
int val[4005][4005]; 

int memo[2][4005];
int a=0,b=1;

void dnc(int l,int r,int optl,int optr){
	if (r<l) return;
	
	int m=l+r>>1;
	int optm=-1;

	rep(x,optl,optr+1){
		if (memo[a][x]+val[x+1][m]<memo[b][m]){
			memo[b][m]=memo[a][x]+val[x+1][m];
			optm=x;
		}
	}
	
	dnc(l,m-1,optl,optm);
	dnc(m+1,r,optm,optr);
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n>>k;
	
	string buf;
	getline(cin,buf);
	rep(x,1,n+1){
		getline(cin,buf);
		rep(y,1,n+1) pref[x][y]=buf[y*2-2]-'0';
	}
	
	rep(x,1,n+1){
		rep(y,1,n+1){
			if (x>y) pref[x][y]=0;
			pref[x][y]+=pref[x-1][y]+pref[x][y-1]-pref[x-1][y-1];
		}
	}
	
	rep(x,1,n+1){
		rep(y,x,n+1){
			val[x][y]=pref[y][y]-pref[x-1][y]-pref[y][x-1]+pref[x-1][x-1];
		}
	}
	
	memset(memo[a],63,sizeof(memo[a]));
	memo[a][0]=0;
	
	rep(x,0,k){
		memset(memo[b],63,sizeof(memo[b]));
		dnc(x+1,n,x,n);
		swap(a,b);
	}
	
	cout<<memo[a][n];
}