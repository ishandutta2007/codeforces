#include <bits/stdc++.h>
#define ll long long
using namespace std;

int32_t main() {
    int q; cin>>q; while(q--) {
        ll a, b; cin>>a>>b; cout<<abs(a-b)/5+(abs(a-b)%5)/2+(abs(a-b)%5)%2<<endl;
    }
}