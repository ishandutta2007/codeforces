#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout<<setprecision(30);

    ll w1, w2, h1, h2;
    cin>>w1>>h1>>w2>>h2;
    ll ans = (h1 + h2) + 1 + w2 + 1 + h2 + (w1 - w2) + h1 + 1 + w1 + 1;
    cout<<ans<<endl;

}