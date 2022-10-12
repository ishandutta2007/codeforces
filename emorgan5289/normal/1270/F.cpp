#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

const ll N = 2e5+5, S = 470;
ll p[N], l[N];
int f[N*(S+5)];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    string s; cin >> s;
    ll n = s.size()+1;
    for (ll i = 1; i < n; i++)
        p[i] = p[i-1]+(s[i-1]-'0');
    ll out = 0;
    for (ll k = 1; k < min(n+1, S); k++) {
        for (ll i = 0; i < n; i++)
            out += f[p[i]*k+N-i]++;
        for (ll i = 0; i < n; i++)
            f[p[i]*k+N-i] = 0;
    }
    for (ll i = 0; i < n; i++) {
        if (l[p[i]] == 0) l[p[i]] = i;
        f[p[i]]++;
    }
    for (ll i = 1; i < n; i++) {
        for (ll k = 1; k < min(p[n-1]-p[i-1]+1, N/S+5); k++) {
            ll a = max(l[p[i-1]+k], i-1+S*k);
            ll b = l[p[i-1]+k]+f[p[i-1]+k];
            if (a >= b) continue;
            out += (b-i)/k-(a-i)/k;
        }
    }
    cout << out << "\n";
}