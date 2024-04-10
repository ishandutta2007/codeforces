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

int q;
int arr[300005];
int cost[300005];
int tkd[300005][20];

ll mov(int i,int j){
	rep(x,0,20) if (j&(1<<x)) i=tkd[i][x];
	return i;
}

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>q>>arr[0]>>cost[0];
	
	memset(tkd,-1,sizeof(tkd));
	
	int a,b,c;
	rep(idx,1,q+1){
		cin>>a;
		
		if (a==1){
			cin>>a>>b>>c;
			
			int curr=tkd[idx][0]=a;
			rep(x,0,20){
				if (curr==-1) break;
				curr=tkd[idx][x+1]=tkd[curr][x];
			}
			
			arr[idx]=b;
			cost[idx]=c;
		}
		else{
			cin>>a>>b;
			int ob=b;
			
			if (arr[a]==0){
				cout<<"0 0"<<endl;
				continue;
			}
			
			ll ans=0;
			
			int h=0;
			int curr=a;
			rep(x,20,0) if (tkd[curr][x]!=-1 && arr[tkd[curr][x]]) curr=tkd[curr][x],h|=(1<<x);
			while (h>=0){
				int temp=mov(a,h);
				ll temp2=min(b,arr[temp]);
				ans+=temp2*cost[temp];
				b-=temp2;
				arr[temp]-=temp2;
				
				if (arr[temp]==0) h--;
				if (b==0) break;
			}
			
			
			cout<<ob-b<<" "<<ans<<endl;
		}
	}
}