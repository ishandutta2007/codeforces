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
int n,a[101],b[101],vis[10004],res[10004],ans;
string s;
void solve(){
    cin>>n>>s;
    rep(i,0,n) cin>>a[i]>>b[i];
    rep(i,0,n){
    	memset(vis,-1,sizeof vis);
    	int cur=s[i]-'0';
    	int tim=b[i];
    	vis[0]=cur;
    	while(tim<=10000){
    		cur=cur^1;
    		vis[tim]=cur;
    		tim+=a[i];
    	}
    	rep(j,1,10001) if(vis[j]==-1) vis[j]=vis[j-1];
    	rep(j,0,10001) res[j]+=vis[j];
    }
    rep(i,0,10001) ans=max(ans,res[i]);
    cout<<ans<<endl;
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