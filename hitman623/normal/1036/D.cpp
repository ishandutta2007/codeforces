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
int n,m,a[300005],b[300005],ans;
void solve(){
    cin>>n;
    rep(i,0,n){
        cin>>a[i];
        if(i) a[i]+=a[i-1];
    }
    cin>>m;
    rep(i,0,m){
        cin>>b[i];
        if(i) b[i]+=b[i-1];
    }
    if(a[n-1]!=b[m-1]){
        cout<<-1<<endl;
        return;
    }
    int p1=0,p2=0;
    while(p1<n and p2<m){
        if(a[p1]==b[p2]) ans++,p1++,p2++;
        else if(a[p1]<b[p2]) p1++;
        else p2++;
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