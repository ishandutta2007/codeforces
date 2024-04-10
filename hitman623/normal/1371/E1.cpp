#include <bits/stdc++.h>

#define int         long long
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
int n,p,a[100005],f[100005],g[100005];
mi freq;
void solve(){
    cin>>n>>p;
    rep(i,0,n) cin>>a[i];
    sort(a,a+n);
    int l=max(0LL,a[n-1]-n+1),r=a[n-1];
    rep(i,0,n){
    	if(a[i]<=l) a[i]=0;
    	else a[i]-=l;
    }
    rep(i,0,n) g[a[i]]++;
    rep(i,0,n) f[a[i]]++;
    rep(i,1,n) f[i]+=f[i-1];
    rep(i,0,n) f[i]-=i;
    rep(i,0,n){
    	f[i]%=p;
    	f[i]=(f[i]+p)%p;
    	freq[f[i]]++;
    }
    int cur=1,w=0;
    vi res;
    rep(x,0,n){
    	if(freq[(p-x%p)%p]>0);
    	else if(cur) res.pb(l+x);
		w++;
		cur=cur*w%p;
    	freq[f[x]]--;
    }
    cout<<sz(res)<<endl;
    for(auto i:res) cout<<i<<" ";
	cout<<endl;
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