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
int n,m,ans,s[100005],p[100005],cur,a[100005];
void solve(){
    cin>>n>>m;
    rep(i,1,n+1){
        cin>>a[i];
    }
    s[n]=m-a[n];
    for(int j=n-1;j>=0;j--){
        s[j]=m-a[j]-s[j+1];
    }
    ans=s[0];
    rep(i,1,n+1){
        if(i%2){
            ans=max(ans,a[i]-1-a[i-1]+s[i]+cur);
        }
        else{
            ans=max(ans,a[i]-1-a[i-1]+s[i+1]+cur);
        }
        if(i%2) cur+=a[i]-a[i-1];
    }
    if(n%2){
        ans=max(ans,cur+m-a[n]-1);
    }
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