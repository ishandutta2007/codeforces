#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;++i)
#define debug(x) cerr<<#x<<": "<<x<<endl
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<ll>> a(n,vector<ll>(n));
    rep(i,0,n) rep(j,0,n) cin >> a[i][j];
    rep(i,0,n) {
        int x = sqrt(a[i][(i+1)%n]*a[i][(i+2)%n]/a[(i+1)%n][(i+2)%n]);
        cout <<x<<" ";
    }
    cout<<"\n";
}