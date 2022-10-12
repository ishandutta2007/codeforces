#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int inf = 1e9+10;
const ll inf_ll = 1e18+10;
#define all(x) (x).begin(), (x).end()
#define pb push_back
#define cmax(x, y) (x = max(x, y))
#define cmin(x, y) (x = min(x, y))

#ifndef LOCAL
#define debug(...) 0
#else
#include "../../debug.cpp"
#endif

template<typename it>
long long inversions(it first, it last) {

    using T = typename iterator_traits<it>::value_type;
    long long n = last-first, out = 0;
    vector<T> A(first, last), B(n);

    for (int w = 1; w < n; w <<= 1) {
        for (int k = 0; k < n;) {
            int s = k, j = k+w;
            for (int i = k; i < s+w && i < n; i++) {
                while (j < s+(w<<1) && j < n && A[j] < A[i])
                    B[k++] = A[j++];
                B[k++] = A[i], out += j-(s+w);
            }
            while (j < s+(w<<1) && j < n)
                B[k++] = A[j++];
        }
        swap(A, B);
    }
    return out;
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n; cin >> n;
    vector<ll> a(n);
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 1; i < n; i++)
        a[i] += a[i-1];
    debug(a);
    if (*min_element(all(a)) < 0 || *max_element(all(a)) > a[n-1])
        cout << "-1\n";
    else
        cout << inversions(all(a)) << "\n";
}