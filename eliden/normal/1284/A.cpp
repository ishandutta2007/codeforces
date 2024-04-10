#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;++i)
#define trav(a,x) for(auto &a:x)
#define all(x) x.begin(), x.end()
#define sz(x) (int)(x).size()
#define debug(x) cerr<<#x<<": "<<x<<endl
using ll = long long;
using vi = vector<int>;
using pii = pair<int,int>;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m;
    cin>>n>>m;
    vector<string> a(n), b(m);
    rep(i,0,n) cin>>a[i];
    rep(i,0,m) cin>>b[i];
    int q;
    cin>>q;
    rep(i,0,q) {
        int t;
        cin>>t;
        cout<<a[(t+n-1)%n];
        cout<<b[(t+m-1)%m];
        cout<<"\n";
    }
}