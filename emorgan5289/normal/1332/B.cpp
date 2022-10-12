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
vector<T> primesupto(T n) {
    vector<bool> sieve(n+1, 1);
    for (T i = 2; i <= n; i++)
        if (sieve[i])
            for (T j = 2*i; j <= n; j += i)
                sieve[j] = 0;
    vector<T> out;
    for (T i = 2; i <= n; i++)
        if (sieve[i])
            out.push_back(i);
    return out;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t; fin >> t;
    vector<int> p = primesupto(100);
    while (t--) {
        int n; fin >> n;
        vector<int> a(n); for (auto& x : a) fin >> x;
        vector<int> b(n, -1);
        int m = 1;
        for (int k = 0; k < 11; k++) {
            bool v = 0;
            for (int i = 0; i < n; i++) {
                // debug(b[i], p[k]);
                if (b[i] == -1 && a[i]%p[k] == 0) {
                    b[i] = m;
                    v |= 1;
                }
            }
            if (v) m++;
        }
        cout << m-1 << "\n";
        for (auto& x : b) cout << x << " ";
        cout << "\n";
    }
}