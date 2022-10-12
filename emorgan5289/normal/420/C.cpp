#include <bits/stdc++.h>
 
#define ll long long
#define ull unsigned long long
#define PI 3.14159265358979323846
 
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back
#define eb emplace_back
#define vec vector
 
using namespace std;
 
#ifndef LOCAL 
 
#pragma GCC optimize ("O3")
#define debug(...)
 
#else 
 
#include "../../debug.cpp"
 
#endif 
 
int main(){
    ios_base::sync_with_stdio(false), cin.tie(NULL);
    
    ll n; ll k; cin >> n >> k;
    vec<ll> n1(n), n2(n);
    set<pair<ll, ll>> ee;
    map<pair<ll, ll>, ll> fq;
    for(int i = 0; i < n; ++i){
        int u, v; cin >> u >> v; --u; --v;
        if (u > v) swap(u, v);
        n1[u]++;n2[u]++;
        n1[v]++;n2[v]++;
        ee.insert({u, v});
        fq[{u, v}]++;
    }
    sort(all(n1));
    ll ans = 0;
    for(auto i : n1){
        ll l = max(0ll, k - i);
        ll nl = n1.end() - lower_bound(all(n1), l);
        if(i + i >= k) --nl;
        ans += nl;
    }
    ans >>= 1;
    for(auto [i, j] : ee){
        ll oc = n2[i]+n2[j];
        ll ac = oc - fq[{i, j}];      
        if(oc >= k and ac < k){
            --ans;
        }
    }
    cout << ans << endl;
 
    return 0;
}