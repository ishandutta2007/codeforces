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

//need to find a way to dynamically store the mex
//actually n^2 works lmao

int n;
int arr[1005];
int cnt[1005];

vector<int> ans;
set<int> bad;

int mex(){
	rep(x,0,1005) if (cnt[x]==0) return x;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int TC;
	cin>>TC;
	while (TC--){
		memset(cnt,0,sizeof(cnt));
		ans.clear();
		
		cin>>n;
		rep(x,0,n){
			cin>>arr[x];
			cnt[arr[x]]++;
			
			if (arr[x]!=x) bad.insert(x);
		}
		
		while (!bad.empty()){
			int temp=mex();
			
			if (bad.count(temp)){
				cnt[arr[temp]]--;
				arr[temp]=temp;
				cnt[arr[temp]]++;
				bad.erase(temp);
				ans.push_back(temp);
			}
			else{
				int pos=*bad.begin();
				
				cnt[arr[pos]]--;
				arr[pos]=temp;
				cnt[arr[pos]]++;
				ans.push_back(pos);
			}
			
			//rep(x,0,n) cout<<arr[x]<<" ";cout<<endl;
		}
		
		cout<<sz(ans)<<endl;
		for (auto &it:ans) cout<<it+1<<" ";cout<<endl;
	}
}