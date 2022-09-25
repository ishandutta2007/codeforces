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

int n;
int arr[300005];
int l[300005];
int r[300005];
string ans;

int has[300005];
int fen[300005];
void add(int i,int j){
	while (i<n+5){
		fen[i]+=j;
		i+=i&-i;
	}
}

int query(int i){
	int res=0;
	while (i){
		res+=fen[i];
		i-=i&-i;
	}
	return res;
}

vector<ii> proc;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		proc.clear();
		ans.clear();
		
		cin>>n;
		rep(x,1,n+5){
			has[x]=0;
			fen[x]=0;
		}
		rep(x,0,n){
			cin>>arr[x];
			ans+='0';
		}
		
		vector<int> temp;
		rep(x,0,n){
			while (!temp.empty() && arr[temp.back()]>=arr[x]) temp.pop_back();
			if (temp.empty()) l[x]=-1;
			else l[x]=temp.back();
			
			temp.push_back(x);
		}
		
		temp.clear();
		rep(x,n,0){
			while (!temp.empty() && arr[temp.back()]>arr[x]) temp.pop_back();
			if (temp.empty()) r[x]=n;
			else r[x]=temp.back();
			
			temp.push_back(x);
		}
		
		//rep(x,0,n) cout<<l[x]<<" "; cout<<endl;
		//rep(x,0,n) cout<<r[x]<<" "; cout<<endl;
		
		int bad=0;
		rep(x,0,n){
			int t1=min(x-l[x],r[x]-x);
			int t2=r[x]-l[x];
			
			//cout<<t1<<" "<<t2<<endl;
			bad=max(bad,t1);
			proc.push_back(ii(1,arr[x]));
			proc.push_back(ii(t2,-arr[x]));
			
			//cout<<t2<<" "<<arr[x]<<endl;
		}
		
		sort(all(proc));
		reverse(all(proc));
		rep(x,1,n+1){
			while (!proc.empty() && proc.back().fi==x){
				int temp=proc.back().se;
				if (temp>0){
					has[temp]++;
					if (has[temp]==1) add(temp,1);
				}
				else{
					has[-temp]--;
					if (has[-temp]==0) add(-temp,-1);
				}
				proc.pop_back();
			}
			
			//cout<<query(n-x+1)<<endl;
			if (query(n-x+1)==n-x+1){
				ans[x-1]='1';
			}
		}
		
		//rep(x,1,n+1) if (2<=x && x<=bad) ans[x]='0';
		cout<<ans<<endl;
	}
}