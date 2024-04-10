#include <bits/stdc++.h>
#define ll long long
using namespace std;

int32_t main() {
    int q; cin>>q; while(q--) {
        ll a, b, n, s; cin>>a>>b>>n>>s;
        cout<<(s%n>b||a*n+b<s?"NO\n":"YES\n");
    }
}