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
        int n;
        cin>>n;
        vector<int> a(n);
        rep(i,0,n) {
            cin>>a[i];
            a[i] = abs(a[i]);
        }
        rep(j,0,n) {
            if(j&1) cout<<(-a[j]);
            else cout<<a[j];
            if(j==n-1) cout<<"\n";
            else cout<<" ";
        }
    }
}