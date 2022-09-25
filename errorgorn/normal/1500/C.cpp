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

int n,m;
int arr[1505][1505];
int brr[1505][1505];
int temp[1505][1505];

int nxt[1505][1505];
int cnt[1505];

int grp[1505];

vector<int> ans;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n>>m;
	rep(x,0,n) rep(y,0,m) cin>>arr[x][y];
	rep(x,0,n) rep(y,0,m) cin>>brr[x][y];
	
	rep(y,0,m){
		rep(x,n,0){
			if (x!=n-1 && brr[x][y]<=brr[x+1][y]) nxt[x][y]=nxt[x+1][y];
			else nxt[x][y]=x;
		}
	}
	
	// rep(x,0,n){
		// rep(y,0,m) cout<<nxt[x][y]<<" "; cout<<endl;
	// }
	
	rep(y,0,m) if (nxt[0][y]!=n-1) cnt[y]++;
	
	memset(grp,-1,sizeof(grp));
	grp[0]=n-1;
	
	while (true){
		int idx=-1;
		rep(y,0,m) if (cnt[y]==0) idx=y;
		if (idx==-1) break;
		
		cnt[idx]=-1;
		ans.pub(idx);
		int l=0;
		while (l<n){
			int r=grp[l];
			
			vector<int> v={l};
			rep(x,l,r) if (brr[x][idx]!=brr[x+1][idx]) v.pub(x+1);
			
			if (sz(v)!=1){
				//cout<<"debug: "<<sz(v)<<endl;
				rep(y,0,m) if (cnt[y]!=-1 && nxt[l][y]<r) cnt[y]--;
				
				v.pub(r+1);
				rep(x,0,sz(v)-1){
					grp[v[x]]=v[x+1]-1;
					rep(y,0,m) if (cnt[y]!=-1 && nxt[v[x]][y]<v[x+1]-1) cnt[y]++;
				}
			}
			
			l=r+1;
		}
	}
	
	reverse(all(ans));
	
	vector<int> id;
	rep(x,0,n) id.pub(x);
	
	for (auto &it:ans){
		stable_sort(all(id),[it](int i,int j){
			return arr[i][it]<arr[j][it];
		});
	}
	
	bool can=true;
	rep(x,0,n) rep(y,0,m) if (arr[id[x]][y]!=brr[x][y]) can=false;
	
	if (can){
		cout<<sz(ans)<<endl;
		for (auto &it:ans) cout<<it+1<<" "; cout<<endl;
	}
	else{
		cout<<"-1"<<endl;
	}
}