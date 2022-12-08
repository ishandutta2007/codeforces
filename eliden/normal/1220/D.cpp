#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;++i)
#define debug(x) cerr<<#x<<": "<<x<<endl
#define sz(x) (int)(x).size()
using ll = long long;
int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    int m = 70;
    vector<set<ll>> a(70);
    rep(i,0,n) {
        ll x;
        cin >> x;
        int c=0;
        ll y = x;
        while(y%2==0) {
            y/=2;
            ++c;
        }
        a[c].insert(x);
    }
    int j = 0;
    rep(i,1,m) if(sz(a[i])>sz(a[j])) j = i;
    int rem = n-sz(a[j]);
    cout<<rem<<"\n";
    rep(i,0,m) if(i!=j) {
        for(ll x:a[i]) cout<<x<<" ";
    }
    cout<<"\n";
}