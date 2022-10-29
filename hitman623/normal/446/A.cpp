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
int n,a[100005],l[100005],r[100005];
void solve(){
    cin>>n;
    rep(i,0,n){
        cin>>a[i];
    }
    if(n<=2){ 
        cout<<n<<endl;
        return;
    }
    l[0]=1;
    rep(i,1,n){
        if(a[i]>a[i-1]) l[i]=1+l[i-1];
        else l[i]=1;
    }
    r[n-1]=1;
    for(int i=n-2;i>=0;i--){
        if(a[i]<a[i+1]) r[i]=1+r[i+1];
        else r[i]=1;
    }
    int ans=max(r[1],l[n-2])+1;
    rep(i,1,n-1){
        if(a[i+1]>a[i-1]+1){
            ans=max(ans,l[i-1]+r[i+1]+1);
        }
        ans=max(ans,l[i-1]+1);
        ans=max(ans,r[i+1]+1);
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