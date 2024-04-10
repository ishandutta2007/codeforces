#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ii pair<int,int>
#define fi first
#define se second
#define endl '\n'

#define puf push_front
#define pof pop_front
#define pub push_back
#define pob pop_back
#define lb lower_bound
#define ub upper_bound

#define rep(x,s,e) for (int x=(s)-((s)>(e));x!=(e)-((s)>(e));((s)<(e))?x++:x--)
#define all(x) (x).begin(),(x).end()
#define sz(x) (int) (x).size()

mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

const int INF=1e18;
const int B=640;

int n,nB,w,q;
int arr[100005];
int qu[100005];
int fin[100005];

ii parr[100005];
vector<int> proc[100005];

ii val[100005];
int cost[100005];

int nxt[100005];
ii range[100005];

void process(int i,int k){
	int l=i*B,r=min((i+1)*B,n)-1;
	
	rep(x,r+1,l){
		while (nxt[x]<=r && range[x].se-range[x].fi<=k){
			nxt[x]++;
			if (nxt[x]==r+1) break;
			range[x].fi=min(range[x].fi,arr[nxt[x]]);
			range[x].se=max(range[x].se,arr[nxt[x]]);
		}
		
		if (nxt[x]==r+1){
			cost[x]=0;
			val[x]=range[x];
		}
		else{
			cost[x]=cost[nxt[x]]+1;
			val[x]=val[nxt[x]];
		}
	}
}

signed main(){
	cin.tie(0);
	cout.tie(0);
	cin.sync_with_stdio(false);
	
	cin>>n>>w>>q;
	rep(x,0,n) cin>>arr[x];
	rep(x,0,q) cin>>qu[x];
	nB=(n+B-1)/B;
	
	rep(x,0,n){
		parr[x]={arr[x],arr[x]};
		if (x%B){
			parr[x].fi=min(parr[x-1].fi,arr[x]);
			parr[x].se=max(parr[x-1].se,arr[x]);
		}
	}
	
	rep(x,0,nB){
		int l=x*B,r=min((x+1)*B,n)-1;
		
		rep(i,l,r+1){
			int mn=arr[i],mx=arr[i];
			rep(j,i,r+1){
				mn=min(mn,arr[j]);
				mx=max(mx,arr[j]);
				proc[x].pub(mx-mn);
			}
		}
		
		sort(all(proc[x])); reverse(all(proc[x]));
	}
	rep(x,0,n) nxt[x]=x,range[x]={arr[x],arr[x]};
	
	vector<int> idx;
	rep(x,0,q) idx.pub(x);
	
	sort(all(idx),[](int i,int j){
		return qu[i]>qu[j];
	});
	
	for (auto it:idx){
		int W=w-qu[it];
		
		int ans=-1;
		ii curr={-INF,INF};
		
		rep(x,0,nB){
			if (!proc[x].empty() && proc[x].back()<=W){
				int curr;
				while (!proc[x].empty() && proc[x].back()<=W){
					curr=proc[x].back();
					proc[x].pob();
				}
				process(x,curr);
			}
			
			int l=x*B,r=min((x+1)*B,n)-1;
			
			int lo=l-1,hi=r+1,mi;
			while (hi-lo>1){
				mi=hi+lo>>1;
				
				if (max(curr.se,parr[mi].se)-min(curr.fi,parr[mi].fi)<=W) lo=mi;
				else hi=mi;
			}
			
			if (hi==r+1){
				curr.fi=min(curr.fi,parr[r].fi);
				curr.se=max(curr.se,parr[r].se);
			}
			else{
				ans+=cost[hi]+1;
				curr=val[hi];
			}
		}
		
		fin[it]=ans;
	}
	
	rep(x,0,q) cout<<fin[x]<<endl;
}