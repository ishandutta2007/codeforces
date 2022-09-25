#include <bits/stdc++.h>
using namespace std;

#define int long long
#define ii pair<int,int>
#define iii pair<ii,int>
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

const int B=400;

int n,q;
int arr[100005];

vector<iii> qu[100005/B];
int ans[300005];

ii buc[B+5];
int id[100005];

int cost[100005];

signed main(){
	cin.tie(0);
	cout.tie(0);
	cin.sync_with_stdio(false);
	
	cin>>n;
	rep(x,0,n) cin>>arr[x];
	
	vector<int> idx;
	rep(x,0,n) idx.pub(x);
	sort(all(idx),[](int i,int j){
		return arr[i]<arr[j];
	});
	
	//rep(x,0,n) cout<<idx[x]<<" "; cout<<endl;
	
	cin>>q;
	int a,b;
	rep(x,0,q){
		cin>>a>>b;
		a--,b--;
		qu[a/B].pub({{a,b},x});
	}
	
	rep(i,0,100005/B) if (!qu[i].empty()){
		sort(all(qu[i]),[](iii i,iii j){
			return i.fi.se<j.fi.se;
		});
		
		vector<int> bidx;
		rep(x,0,n){
			if (idx[x]<i*B) continue;
			
			if (idx[x]<(i+1)*B){
				bidx.pub(idx[x]);
			}
			else{
				id[idx[x]]=sz(bidx);
			}
		}
		
		memset(buc,-1,sizeof(buc));
		rep(x,0,100005) cost[x]=1e9+100;
		
		vector<int> stk;
		rep(x,0,n) if ((i+1)*B<=idx[x]){
			while (!stk.empty() && idx[stk.back()]>idx[x]){
				stk.pob();
			}
			if (!stk.empty()){
				cost[idx[x]]=min(cost[idx[x]],arr[idx[x]]-arr[idx[stk.back()]]);
			}
			stk.pub(x);
		}
		stk.clear();
		rep(x,n,0) if ((i+1)*B<=idx[x]){
			while (!stk.empty() && idx[stk.back()]>idx[x]){
				stk.pob();
			}
			if (!stk.empty()){
				cost[idx[x]]=min(cost[idx[x]],arr[idx[stk.back()]]-arr[idx[x]]);
			}
			stk.pub(x);
		}
		
		rep(x,(i+1)*B,n) cost[x]=min(cost[x],cost[x-1]);
		
		int curr=(i+1)*B-1;
		
		//for (auto it:bidx) cout<<it<<" "; cout<<endl;
		for (auto it:qu[i]){
			while (curr<it.fi.se){
				curr++;
				int temp=id[curr];
				if (buc[temp]==ii(-1,-1)) buc[temp]=ii(1e9+100,-1e9-100);
				buc[temp].fi=min(buc[temp].fi,arr[curr]);
				buc[temp].se=max(buc[temp].se,arr[curr]);
			}
			ans[it.se]=cost[curr];
			
			int curr=-2e9-100;
			if (buc[0]!=ii(-1,-1)) curr=buc[0].se;
			rep(x,0,sz(bidx)){
				if (it.fi.fi<=bidx[x] && bidx[x]<=it.fi.se){
					ans[it.se]=min(ans[it.se],arr[bidx[x]]-curr);
					curr=arr[bidx[x]];
				}
				if (buc[x+1]!=ii(-1,-1)){
					ans[it.se]=min(ans[it.se],buc[x+1].fi-curr);
					curr=buc[x+1].se;
				}
			}
		}
	}
	
	rep(x,0,q) cout<<ans[x]<<endl;
}