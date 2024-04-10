#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ull 1000000000000000000
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#pragma GCC optimize ("O3")
#define debug(...)
#define fin cin
#else
#include "../../debug.cpp"
#define debug(...) cerr << "[" << #__VA_ARGS__ << "]:", debug_out(__VA_ARGS__)
ifstream fin("../../input.in");
#define cin fin
#endif

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    ll n, m; fin >> n >> m;
    ll out = 0;
    vector<ll> fact = {1};
    for (int i = 1; i < n+2; i++) fact.pb((fact.back()*i)%m);
    for (ll w = 0; w < n; w++) {
        ll add = fact[w+1];
        add = (add*(n-w))%m;
        add = (add*(n-w))%m;
        add = (add*fact[n-w-1])%m;
        out = (out+add)%m;
        // debug(w, fact[w+1], add);
    }
    cout << out << "\n";
}