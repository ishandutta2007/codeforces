#include <bits/stdc++.h>
#define ll long long
using namespace std;

int32_t main() {
    int q; cin>>q; while(q--) {
        int a, b; cin>>a>>b; cout<<(__gcd(a, b)==1?"Finite\n":"Infinite\n");
    }
}