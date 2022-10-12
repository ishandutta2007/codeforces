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

template<typename T>
vector<T> primefactors(T n) {
    vector<T> out;
    for (T i = 2; i <= n; i++) {
        if (i >= (T)(sqrt(n))+1)
            i = n;
        if (n%i == 0) {
            out.push_back(i);
            n /= i; i--;
        }
    }
    return out;
}

const ll N = 1e6+5, K = 5005;
ll a[K][K], f[K], c[K], r[K], t[K], p[K];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    for (ll i = 1; i < K; i++) {
        for (auto& x : primefactors(i))
            a[i][x]++;
        for (ll j = 1; j < K; j++)
            a[i][j] += a[i-1][j];
    }
    for (int i = 0; i < K-1; i++) {
        for (int j = K-1; j >= 0; j--) {
            if (a[i][j] == a[i+1][j])
                c[i] += a[i][j];
            else {
                c[i] += min(a[i][j], a[i+1][j]);
                break;
            }
        }
    }

    ll n, x; cin >> n;
    for (int i = 0; i < n; i++)
        cin >> x, f[x]++;
    ll s = 0, out = 0;
    for (int i = 0; i < K; i++)
        for (ll j = 0; j < K; j++) {
            s += a[i][j]*f[i];
            p[i] += a[i][j];
        }
    for (int i = 1; i < p[K-1]; i++) {
        copy(f, f+K, r);
        for (int j = 0; j < K-1; j++)
            if (c[j] >= i) r[j+1] += r[j];
        for (int j = K-2; j >= 0; j--)
            if (c[j] >= i) r[j] = r[j+1];
        // debug(i, vector(r, r+K));
        for (int j = 0; j < K; j++) {
            t[j] += r[j];
            if (i > p[j]) t[j] -= f[j];
        }
        out = max(out, 2**max_element(t, t+K)-n*i);
    }
    cout << s-out << "\n";
}