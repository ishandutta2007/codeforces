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

template<typename T>
struct safe_hash {
    size_t operator()(const T& x) const {
        static const size_t fixed = chrono::steady_clock::now().time_since_epoch().count();
        size_t h = std::hash<T>()(x);

        // splitmix64
        h += 0x9e3779b97f4a7c15 + fixed;
        h = (h ^ (h >> 30)) * 0xbf58476d1ce4e5b9;
        h = (h ^ (h >> 27)) * 0x94d049bb133111eb;
        return h ^ (h >> 31);
    }
};

template<typename T>
using safe_unordered_set = unordered_set<T, safe_hash<T>>;

template<typename T1, typename T2>
using safe_unordered_map = unordered_map<T1, T2, safe_hash<T1>>;

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    ll n; fin >> n;
    vector<ll> q(n); for (auto& x : q) fin >> x;
    vector<ll> p(n+1); p[0] = 0;
    for (ll i = 0; i < n; i++)
        p[i+1] = q[i] + p[i];

    ll bad = 0, out = 0, a = 0, b = 0;
    map<ll, ll> m; m[0]++;
    for (a = 0; a < n+1; a++) {
        while (b < n+1 && bad == 0) {
            b++;
            if (b < n+1) {
                m[p[b]]++;
                if (m[p[b]] == 2) bad++;
            }
        }
        out += (b-a-1);
        m[p[a]]--;
        if (m[p[a]] == 1) bad--;
    }
    cout << out << "\n";
}