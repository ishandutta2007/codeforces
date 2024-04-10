#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<(b);++i)
#define debug(x) cerr<<#x<<": "<<x<<endl
#define trav(a,x) for(auto &a:x)
#define all(x) x.begin(),x.end()
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int,int> pii;
typedef vector<int> vi;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int tests;
    cin>>tests;
    rep(test,0,tests) {
        int n, m;
        cin>>n>>m;
        vector<vi> a(n,vi(m));
        rep(i,0,n) rep(j,0,m) cin>>a[i][j];
        vector<vi> b(n,vi(m,4));
        rep(i,0,n) {
            --b[i][0];
            --b[i][m-1];
        }
        rep(j,0,m) {
            --b[0][j];
            --b[n-1][j];
        }
        bool bad = false;
        rep(i,0,n) rep(j,0,m) if(a[i][j]>b[i][j]) bad = true;
        if(bad) cout<<"NO\n";
        else {
            cout<<"YES\n";
            rep(i,0,n) rep(j,0,m) {
                cout<<b[i][j];
                if(j==m-1) cout<<"\n";
                else cout<<" ";
            }
        }
    }
}