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

#define int long long
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

int n;
int arr[205];
int brr[205];

vector<int> al[205];
bool vis[205];

void dfs(int i){
	vis[i]=true;
	for (auto it:al[i]) if (!vis[it]) dfs(it);
	if (!vis[brr[i]]) dfs(brr[i]);
}

bool connected(){
	rep(x,1,n+1) vis[x]=false;
	dfs(1);
	return accumulate(vis+1,vis+n+1,0)==n;
}

vector<int> cyc[205];
int id[205];
int cnt[205];
vector<int> stk;

int used[205];

bool check(vector<int> v1,vector<int> v2){
	// cout<<"check: "<<endl;
	// for (auto it:v1) cout<<it<<" "; cout<<endl;
	// for (auto it:v2) cout<<it<<" "; cout<<endl;
	
	rep(x,1,n+1) used[x]=0;
	
	rep(x,0,sz(v1)-1){
		used[v1[x]]++;
		used[arr[v1[x+1]]]++;
	}
	
	rep(x,1,n+1) al[x].clear();
	
	v1.insert(v1.end(),all(v2));
	rep(x,0,sz(v1)-1) al[v1[x]].pub(v1[x+1]);
	
	rep(x,1,n+1){
		if (x!=1){
			int a=x,b=brr[x-1];
			if (used[a]!=2 && used[b]!=2) al[a].pub(b);
		}
		if (x!=n){
			int a=x,b=brr[x+1];
			if (used[a]!=2 && used[b]!=2) al[a].pub(b);
		}
	}
	
	//cout<<connected()<<endl;
	return connected();
}

signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin.exceptions(ios::badbit | ios::failbit);
	
	int TC;
	cin>>TC;
	while (TC--){
		cin>>n;
		rep(x,1,n+1) cin>>arr[x];
		rep(x,1,n+1) brr[arr[x]]=x;
		
		rep(x,1,n+1) cyc[x].clear();
		
		rep(x,1,n+1){
			int curr=x;
			
			do{
				cyc[x].pub(curr);
				curr=brr[curr];
			} while (curr!=x);
			
			id[x]=*min_element(all(cyc[x]));
			reverse(all(cyc[x]));
		}
		
		vector<int> ans={1};
		stk={1};
		stk.insert(stk.end(),all(cyc[1]));
		stk.pob();
		
		rep(x,1,n+1) cnt[x]=0;
		cnt[1]=1;
		
		//rep(x,1,n+1){ for (auto it:cyc[x]) cout<<it<<" "; cout<<endl;}
		
		rep(x,1,n){
			vector<int> ansf={(int)1e9},stkf;
			
			int mn=min(ans.back(),arr[stk.back()]);
			int mx=max(ans.back(),arr[stk.back()]);
			
			//cout<<"min max: "<<mn<<" "<<mx<<endl;
			
			vector<int> ans2=ans,stk2=stk;
			ans2.pub(stk2.back());
			stk2.pob();
			
			if (!stk2.empty() && check(ans2,stk2)){
				ansf=ans2;
				stkf=stk2;
			}
			
			rep(y,1,n+1) if (cnt[id[y]]==0){
				//cout<<"test: "<<y<<endl;
				
				vector<int> ans2=ans,stk2=stk;
				bool bad=false;
				
				if (y<mn){
					rep(z,y,mn){
						cnt[id[z]]++;
						if (cnt[id[z]]==2) bad=true;
					}
					rep(z,y,mn) cnt[id[z]]--;
					
					if (!bad){
						rep(z,mn,y){
							stk2.insert(stk2.end(),all(cyc[brr[z]]));
						}
					}
					
					ans2.pub(stk2.back());
					stk2.pob();
					
					if (check(ans2,stk2) && ansf.back()>ans2.back()){
						ansf=ans2;
						stkf=stk2;
					}
				}
				else if (mx<y){
					rep(z,y+1,mx+1){
						cnt[id[z]]++;
						if (cnt[id[z]]==2) bad=true;
					}
					rep(z,y+1,mx+1) cnt[id[z]]--;
					
					if (!bad){
						rep(z,mx+1,y+1){
							stk2.insert(stk2.end(),all(cyc[brr[z]]));
						}
					}
					
					ans2.pub(stk2.back());
					stk2.pob();
					
					if (check(ans2,stk2) && ansf.back()>ans2.back()){
						ansf=ans2;
						stkf=stk2;
					}
				}
				else{
					while(1);
				}
			}
			
			if (ansf.back()==stk.back()) ;// do nothing
			else if (arr[ansf.back()]<mn) rep(z,arr[ansf.back()],mn) cnt[id[z]]++;
			else rep(z,arr[ansf.back()]+1,mx+1) cnt[id[z]]++;
			
			ans=ansf;
			stk=stkf;
			
			//cout<<"curr: "; for (auto it:ans) cout<<it<<" "; cout<<endl;
		}
		
		for (auto it:ans) cout<<it<<" "; cout<<endl;
	}
}