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

const int dx[]={1,-1,0,0};
const int dy[]={0,0,1,-1};

int n,m,k;
string grid[1005];
int w[1005][1005];

int x1,y1,x2,y2;

queue<ii> q;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	memset(w,63,sizeof(w));
	
	cin>>n>>m>>k;
	rep(x,0,n) cin>>grid[x];
	cin>>x1>>y1>>x2>>y2;
	x1--,y1--,x2--,y2--;
	
	w[x1][y1]=0;
	q.push(ii(x1,y1));
	
	while (!q.empty()){
		int i=q.front().fi,j=q.front().se;
		q.pop();
		
		//cout<<i<<" "<<j<<" "<<w[i][j]<<endl;
		
		rep(z,0,4){
			int i2=i,j2=j;
			
			rep(kk,0,k){
				i2+=dx[z],j2+=dy[z];
				
				if (i2<0 || n<=i2 || j2<0 || m<=j2) break;
				if (grid[i2][j2]=='#') break;
				if (w[i2][j2]<=w[i][j]) break;
				
				if (w[i2][j2]>w[i][j]+1){
					w[i2][j2]=w[i][j]+1;
					q.push(ii(i2,j2));
				}
			}	
		}
	}
	
	if (w[x2][y2]==1061109567) cout<<"-1"<<endl;
	else cout<<w[x2][y2]<<endl;
}