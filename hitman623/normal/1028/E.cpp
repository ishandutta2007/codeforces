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
int n,a[200005],in=-1,mx=-1,ans[200005];
bool check(){
    rep(i,0,n){
        if(a[i]!=ans[i]%ans[(i+1)%n]) return 0;
    }
    return 1;
}
void solve(){
    cin>>n;
    rep(i,0,n){
        cin>>a[i];
        if(mx<a[i]) mx=a[i],in=i;
    }
    ans[in]=mx;
    if(mx==0){
        cout<<"YES"<<endl;
        rep(i,0,n) cout<<1<<" ";
        cout<<endl;
        return;
    }
    rep(i,0,2*n-1){
        in=(in-1+n)%n;
        int l=(in-1+n)%n;
        int alpha=(a[l]-a[in]+ans[(in+1)%n])/ans[(in+1)%n];
        ans[in]=max(ans[in],alpha*ans[(in+1)%n]+a[in]);
        while(ans[in]<=0) ans[in]+=ans[(in+1)%n];
    }
    if(check()){
        cout<<"YES"<<endl;
        rep(i,0,n) cout<<ans[i]<<" ";
        cout<<endl;        
    }
    else cout<<"NO"<<endl;
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