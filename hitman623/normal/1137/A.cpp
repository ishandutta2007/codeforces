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
int n,m,a[1001][1001];
vi row[1001];
vi col[1001];
void solve(){
    cin>>n>>m;
    rep(i,0,n){
        rep(j,0,m){
            cin>>a[i][j];
            col[j].pb(a[i][j]);
            row[i].pb(a[i][j]);
        }
    }
    rep(i,0,n){
        sort(all(row[i]));
        row[i].resize(unique(all(row[i]))-row[i].begin());
    }
    rep(i,0,m){
        sort(all(col[i]));
        col[i].resize(unique(all(col[i]))-col[i].begin());
    }
    rep(i,0,n){
        rep(j,0,m){
            int small=max(lower_bound(all(row[i]),a[i][j])-row[i].begin(),lower_bound(all(col[j]),a[i][j])-col[j].begin());
            int large=max(sz(row[i])-(upper_bound(all(row[i]),a[i][j])-row[i].begin()),sz(col[j])-(upper_bound(all(col[j]),a[i][j])-col[j].begin()));
            cout<<small+large+1<<" ";
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