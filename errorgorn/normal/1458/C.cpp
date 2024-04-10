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

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int n,q;
string s;
int arr[1005][1005];
int brr[1005][1005];
int origin[3];
int basis[3][3];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n>>q;
		rep(x,0,n){
			rep(y,0,n){
				cin>>arr[x][y];
				arr[x][y]--;
			}
		}
		cin>>s;
		
		memset(basis,0,sizeof(basis));
		basis[0][0]=basis[1][1]=basis[2][2]=1;
		memset(origin,0,sizeof(origin));
		
		for (auto &it:s){
			if (it=='R') origin[1]++;
			else if (it=='L') origin[1]--;
			else if (it=='D') origin[0]++;
			else if (it=='U') origin[0]--;
			else if (it=='I'){
				swap(origin[1],origin[2]);
				swap(basis[1],basis[2]);
			}
			else{
				swap(origin[0],origin[2]);
				swap(basis[0],basis[2]);
			}
		}
		
		rep(x,0,n) rep(y,0,n){
			int temp[3];
			int mul[3]={x,y,arr[x][y]};
			
			rep(a,0,3){
				temp[a]=origin[a];
				rep(b,0,3) temp[a]+=mul[b]*basis[a][b];
				temp[a]=(temp[a]%n+n)%n;
			}
			
			brr[temp[0]][temp[1]]=temp[2];
		}
		
		rep(x,0,n){
			rep(y,0,n) cout<<brr[x][y]+1<<" ";
			cout<<endl;
		}
		cout<<endl;
	}
}