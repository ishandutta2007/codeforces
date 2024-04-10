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
    ll n;
    cin >> n;
    ll lo = 1, hi=n;
    while(lo<hi) {
        ll k=(lo+hi)/2;
        ll eaten=0, m=n;
        while(m) {
            ll take=min(m,k);
            eaten+=take;
            m-=take;
            m -=(m/10);
        }
        if(eaten*2>=n) hi = k;
        else lo = k+1;
    }
    cout << lo << "\n";
}