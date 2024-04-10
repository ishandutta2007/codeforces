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
int n,m,a[103],b[103],row,col,ans[101][101];
void sol(int x,int y){
    if(x==n-1){
        rep(i,y,m){
            ans[n-1][i]=b[i];
        }
        return;
    }
    if(y==m-1){
        rep(i,x,n){
            ans[i][m-1]=a[i];
        }
        return;
    }
    ans[x][y+1]=a[x];
    ans[x+1][y]=b[y];
    b[y+1]^=a[x];
    a[x+1]^=b[y];
    sol(x+1,y+1);
}
void solve(){
    cin>>n>>m;
    rep(i,0,n){
        cin>>a[i];
        row^=a[i];
    }
    rep(i,0,m){
        cin>>b[i];
        col^=b[i];
    }
    if(row!=col){
        cout<<"NO"<<endl;
        return;
    }
    sol(0,0);
    cout<<"YES"<<endl;
    rep(i,0,n){
        rep(j,0,m){
            cout<<ans[i][j]<<" ";
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