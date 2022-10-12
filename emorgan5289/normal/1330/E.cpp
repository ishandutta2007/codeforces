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

ll g, h;
ll a[3000000];

bool check(ll i) {
    ll lid = 2*i, rid = 2*i+1;
    if (a[lid] == 0 && a[rid] == 0) {
        return (i >= (1<<g));
    } else {
        if (a[lid] > a[rid]) {
            return check(lid);
        } else {
            return check(rid);
        }
    }
}

void f(ll i) {
    ll lid = 2*i, rid = 2*i+1;
    if (a[lid] == 0 && a[rid] == 0) {
        a[i] = 0;
    } else {
        if (a[lid] > a[rid]) {
            a[i] = a[lid];
            f(lid);
        } else {
            a[i] = a[rid];
            f(rid);
        }
    }
}

ll s = 0;
vector<ll> out;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    ll t; fin >> t;
    while (t--) {
        fin >> h >> g;
        s = 0;
        for (ll i = 1; i < (1<<h); i++) {
            fin >> a[i]; s += a[i];
        }
        out.clear();
        for (ll i = 1; i < (1<<g); i++)
            while (check(i)) {
                out.pb(i);
                s -= a[i];
                f(i);
            }
        cout << s << "\n";
        for (auto& x : out)
            cout << x << " ";
        cout << "\n";
        for (ll i = 1; i < (1<<h); i++) {
            a[i] = 0;
        }
    }
}