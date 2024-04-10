#include <bits/stdc++.h>
#define ll long long
using namespace std;

string solve(ll x, ll y) {
    if(x==1) {
        if(y>1) return "NO";
        else return "YES";
    }
    else if(x<=3) {
        if(y>3) return "NO";
        else return "YES";
    }
    else return "YES";
}

int32_t main() {
    int q; cin>>q; while(q--) {
        ll x, y; cin>>x>>y; cout<<solve(x, y)<<endl;
    }
}