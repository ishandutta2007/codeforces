#include <bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef long double ld;

int a[300005];

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin>>n;


    for(int i = 1; i <= n; i++){
        cin>>a[i];
    }
    sort(a + 1, a + n + 1);
    ll ans = 0;
    for(int i = 1; i <= n/2; i++){
        ans += 1LL*(a[i] + a[n-i+1])*(a[i] + a[n-i+1]);
    }
    cout<<ans<<endl;
}