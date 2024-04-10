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
int n,k,a[505][505],ans;
void solve(){
    cin>>n>>k;
    int cur=n*n;
    int row=n,col=n;
    while(row>=1){
        a[row][col]=cur--;
        col--;
        if(col<k) col=n,row--;
    }
    for(int i=n;i>=1;i--){
        for(int j=k-1;j>=1;j--){
            a[i][j]=cur--;
        }
    }
    rep(i,1,n+1){
        rep(j,1,n+1){
            if(j==k) ans+=a[i][j];
        }
    }
    cout<<ans<<endl;
    rep(i,1,n+1){
        rep(j,1,n+1){
            if(j==k) ans+=a[i][j];
            cout<<a[i][j]<<" ";
        }
        cout<<endl;
    }
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