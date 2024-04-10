#include <bits/stdc++.h>

using namespace std;

int n,k;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>k;
    int ans = 2*min(k-1,n-k)+max(k-1,n-k)+2*n+1;
    cout<<ans;
    return 0;
}