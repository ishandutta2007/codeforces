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
#define debug(x) cout << #x << " is " << x << endl

#define rep(x,start,end) for(auto x=(start)-((start)>(end));x!=(end)-((start)>(end));((start)<(end)?x++:x--))
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x).size()

#define indexed_set tree<ll,null_type,less<ll>,rb_tree_tag,tree_order_statistics_node_update>
//change less to less_equal for non distinct pbds, but erase will bug

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

int n;
vector<int> al[1000005];

int arr[1000005];
int pos[500005];
bool vis[1000005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n;
	
	if (n%2==1){
		cout<<"Second"<<endl;
		rep(x,1,2*n+1) cin>>arr[x];
		
		rep(x,1,2*n+1){
			if (pos[arr[x]]){
				al[x].push_back(pos[arr[x]]);
				al[pos[arr[x]]].push_back(x);
			}
			else pos[arr[x]]=x;
		}
		
		rep(x,1,n+1){
			al[x].push_back(x+n);
			al[x+n].push_back(x);
		}
		
		vector<int> a,b;
		
		rep(x,1,2*n+1) if (!vis[x]){
			int curr=x;
			int p=-1;
			bool flag=false;
			
			do{
				vis[curr]=true;
				for (auto &it:al[curr]){
					if (it==p){
						p=-1;
						continue;
					}
					
					p=curr;
					curr=it;
					
					if (flag) a.push_back(curr);
					else b.push_back(curr);
					flag^=true;
					break;
				}
			} while (curr!=x);
		}
		
		ll tot=0;
		for (auto &it:a) tot+=it;
		
		if (tot%(2*n)==0){ for (auto &it:a) cout<<it<<" "; cout<<endl;}
		else{ for (auto &it:b) cout<<it<<" "; cout<<endl;}
	}
	else{
		cout<<"First"<<endl;
		rep(x,1,n+1) cout<<x<<" ";
		rep(x,1,n+1) cout<<x<<" ";
		cout<<endl;
	}
}