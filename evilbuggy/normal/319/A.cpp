#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const ll mod = 1000000007;

int main(){

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    string s;
    cin>>s;
    int n = s.size();
    ll ans = 0;
    for(int i = 0; i < n; i++){
        ans <<= 1;
        ans += (s[i] - '0');
        ans %= mod;
    }
    for(int i = 1; i < n; i++){
        (ans <<= 1) %= mod;
    }
    cout<<ans<<endl;

}