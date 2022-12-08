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
    cin >> tests;
    rep(test,0,tests) {
        int n,k1,k2;
        cin>>n>>k1>>k2;
        vector<int> a(k1), b(k2);
        rep(i,0,k1) cin>>a[i];
        rep(i,0,k2) cin>>b[i];
        bool p1 = false;
        rep(i,0,k1) if(a[i]==n) p1 = true;
        if(p1)cout<<"YES\n";
        else cout<<"NO\n";
    }
}