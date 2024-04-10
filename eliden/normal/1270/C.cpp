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
        ll sum = 0, xo = 0;
        rep(i,0,n) {
            ll x;
            cin>>x;
            sum+=x;
            xo^=x;
        }
        ll a = xo, b = sum+xo;
        assert((sum+a+b)==2*(xo^a^b));
        cout<<"2\n";
        cout<<a<<" "<<b<<"\n";
    }
}