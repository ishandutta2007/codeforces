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
int h,n,p[200005];
void solve(){
	int ans=0;
    cin>>h>>n;
    rep(i,1,n+1) cin>>p[i];
    n++;
    p[n]=0;
    int cur=h;
    rep(i,2,n+1){
    	if(cur<=2) break;
    	cur=p[i]+1;
    	if(cur<=2) break;
    	if(p[i+1]==cur-2) cur-=2,i++;
    	else cur=p[i]-1,ans++;
    }
    cout<<ans<<endl;
}

signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    int t=1;
    cin>>t;
    while(t--){
        solve();
    }
    return 0;
}