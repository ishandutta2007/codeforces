#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef long double ld;

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, x;
    ll k;
    cin>>n;
    while(n--){
        cin>>k>>x;
        ll ans = 9*(k-1) + x;
        cout<<ans<<endl;
    }
}