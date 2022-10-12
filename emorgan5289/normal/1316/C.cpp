#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ll 1000000000000000000ll
#define inf_ull 1000000000000000000ull
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#define fin cin
#else
#include "../../debug.cpp"
#endif

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    ll n, m, p; fin >> n >> m >> p;
    vector<ll> a(n), b(m);
    for (auto& x : a) fin >> x;
    for (auto& x : b) fin >> x;
    int c = 0, d = 0;
    while (a[c]%p == 0) c++;
    while (b[d]%p == 0) d++;
    cout << c+d << "\n";
}