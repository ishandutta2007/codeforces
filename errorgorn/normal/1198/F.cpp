// Super Idol
//    
//  
//    
//  105C
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

int n;
int arr[100005];

int memo[270000]; //minimum position to get a certain value
int p[270000]; //backtrack answer

int s;
vector<int> fac;
vector<int> pos[18];

void factorize(int i){
	rep(x,2,100000) if (i%x==0){
		fac.pub(x);
		while (i%x==0) i/=x;
	}
	if (i!=1) fac.pub(i);
}

priority_queue<ii,vector<ii>,greater<ii> > pq;

int ans[100005];

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	cin>>n;
	rep(x,0,n) cin>>arr[x];
	
	factorize(arr[0]);
	
	int curr=1;
	for (auto &it:fac) curr*=it;
	
	vector<int> imp={0};
	rep(x,0,n-1){
		if (arr[x]%curr){
			curr=__gcd(curr,arr[x]);
			imp.pub(x);
		}
	}
	
	for (auto &it:imp){
		int g1=0,g2=0;
		rep(x,0,it+1) g1=__gcd(g1,arr[x]);
		g2=arr[it+1];
		
		fac.clear();
		factorize(g1);
		s=sz(fac);
		factorize(g2);
		
		rep(x,0,sz(fac)) pos[x].clear();
		rep(x,0,sz(fac)){
			rep(y,n,0) if (arr[y]%fac[x]) pos[x].pub(y);
		}
		
		rep(x,0,1<<sz(fac)) memo[x]=1e9;
		
		memo[(1<<sz(fac))-1]=it+1;
		pq.push({it+1,(1<<sz(fac))-1});
		
		//for (auto &it:fac) cout<<it<<" "; cout<<endl;
		
		int bm,weight;
		while (!pq.empty()){
			tie(weight,bm)=pq.top(),pq.pop();
			
			if (memo[bm]!=weight) continue;
			//cout<<bm<<" "<<weight<<endl;
			
			rep(x,0,sz(fac)) while (!pos[x].empty() && pos[x].back()<=weight) pos[x].pob();
			
			int b=1e9;
			rep(x,0,sz(fac)) if (bm&(1<<x)){
				if (!pos[x].empty()) b=min(b,pos[x].back());
			}
			
			if (b!=1e9){
				int temp1=bm,temp2=bm;
				rep(x,0,sz(fac)) if (!pos[x].empty() && pos[x].back()==b && bm&(1<<x)){
					if (x<s) temp1^=(1<<x);
					else temp2^=(1<<x);
				}
				
				if (memo[temp1]>b){
					memo[temp1]=b;
					p[temp1]=bm;
					pq.push({memo[temp1],temp1});
				}
				if (memo[temp2]>b){
					memo[temp2]=b;
					p[temp2]=bm;
					pq.push({memo[temp2],temp2});
				}
			}
		}
		
		//cout<<it<<" "<<memo[0]<<endl;
		//cout<<endl;
		
		if (memo[0]!=1e9){
			rep(x,0,n) ans[x]=1;
			ans[it+1]=2;
			
			int curr=0;
			while (curr!=(1<<sz(fac))-1){
				if (__builtin_ctz(curr^p[curr])>=s) ans[memo[curr]]=2;
				curr=p[curr];
			}
			
			cout<<"YES"<<endl;
			rep(x,0,n) cout<<ans[x]<<" "; cout<<endl;
			return 0;
		}
	}
	
	cout<<"NO"<<endl;
}