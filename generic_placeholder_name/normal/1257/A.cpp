#include <bits/stdc++.h>
#define ll long long
using namespace std;

int32_t main() {
    int q; cin>>q; while(q--) {
        int n, x, a, b; cin>>n>>x>>a>>b; cout<<min(abs(a-b)+x, n-1)<<endl;
    }
}