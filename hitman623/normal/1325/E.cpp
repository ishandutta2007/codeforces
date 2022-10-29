#include <bits/stdc++.h>
 
#define ll          long long
#define pb          push_back
#define pii         pair<int,int>
#define vi          vector<int>
#define vii         vector<pii>
#define mi          map<int,int>
#define mii         map<pii,int>
#define all(a)      (a).begin(),(a).end()
#define x           first
#define y           second
#define sz(x)       (int)x.size()
#define endl        '\n'
#define hell        1000000007
#define rep(i,a,b)  for(int i=a;i<b;i++)
using namespace std;
vi p[1000001];
void process_seive(int n){
    rep(i,2,n+1){
        if(sz(p[i])) continue;
        for(int j=i;j<=n;j+=i){
            if(sz(p[j])<2) p[j].pb(i);
        }
    }
}
int n,a[100005],vis[1000006],par[1000006];
vi adj[1000006];
mii mp;
void solve(){
	process_seive(1000000);
    cin>>n;
    int ans=hell;
    rep(i,1,n+1){
    	cin>>a[i];
		vi v=p[a[i]];
		for(auto k:v){
			ll pp=1LL*k*k;
			while(a[i]%pp==0) a[i]/=pp;
		}
		if(a[i]==1){
			cout<<1<<endl;
			return;
		}
		if(sz(p[a[i]])==1){
			int pp=p[a[i]][0];
			if(vis[pp]) ans=2;
			vis[pp]=1;
			adj[1].pb(pp);
			adj[pp].pb(1);
		}
		else{
			int p1=p[a[i]][0],p2=p[a[i]][1];
			if(mp.count({p1,p2})) ans=2;
			mp[{p1,p2}]=1;
			adj[p1].pb(p2);
			adj[p2].pb(p1);
		}
    }
    if(ans==2){
    	cout<<2<<endl;
    	return;
    }
    memset(vis,0,sizeof vis);
    rep(i,1,1001){
    	if(sz(adj[i])){
    		vector<int> v;
    		v.pb(i);
    		vis[i]=2;
    		vi er;
    		er.pb(i);
    		int cnt=0,f=0;
    		while(1){
    			vi vv;
    			for(auto ii:v){
    				for(auto j:adj[ii]){
    					if(par[ii]==j) continue;
    					if(vis[j]==2){
    						ans=min(ans,2*cnt+1);
    						f=1;
    					}
    					else if(vis[j]==1){
    						ans=min(ans,2*cnt+2);
    						f=1;
    					}
    					else{
	    					vv.pb(j);
	    					par[j]=ii;
    						vis[j]=1;
    						er.pb(j);
    					}
    				}
    			}
    			cnt++;
    			swap(v,vv);
    			for(auto k:v) vis[k]=2;
    			if(2*cnt>ans or f or sz(v)==0) break;
    		}
    		for(auto k:er) vis[k]=0,par[k]=0;
    	}
    }
    if(ans<hell) cout<<ans<<endl;
    else cout<<-1<<endl;
}
 
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    // cin>>t;
    while(t--){
        solve();
    }
    return 0;
}