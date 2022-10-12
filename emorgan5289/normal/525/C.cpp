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

#define maxn 1000005
int a[maxn], b[maxn];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    ll n; fin >> n;
    for (ll i = 0; i < n; i++) {
        ll x; fin >> x; a[x]++;
    }
    vector<ll> c;
    for (ll i = maxn; i > 0; i--) {
        if (a[i] > 0 && (a[i]+b[i])%2 == 1) {
            a[i]--; b[i-1]++;
        }
        for (ll j = 0; j < (a[i]+b[i])/2; j++)
            c.push_back(i);
    }
    ll out = 0;
    for (ll i = 1; i < c.size(); i += 2)
        out += c[i]*c[i-1];
    cout << out << "\n";
}