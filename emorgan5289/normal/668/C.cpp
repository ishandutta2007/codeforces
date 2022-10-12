#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const int inf = 1e9;
const ll inf_ll = 1e18;
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifndef LOCAL
#define debug(...)
#else
#include "../../debug.cpp"
#endif

typedef long double ld;

const int N = 1e5+5;
ld l[N], r[N], a[N], b[N];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    for (int i = 0; i < n+1; i++) cin >> r[i];
    for (int i = 0; i < n; i++) cin >> l[i];
    for (int i = 1; i < n; i++) r[i] += r[i-1];
    for (int i = n-2; i >= 0; i--) l[i] += l[i+1];
    for (int i = 0; i < n; i++) {
        a[i] = ((r[i]-l[i]+1)-sqrt(abs((r[i]-l[i]+1)*(r[i]-l[i]+1)-4*r[i])))/2;
        b[i] = ((r[i]-l[i]+1)+sqrt(abs((r[i]-l[i]+1)*(r[i]-l[i]+1)-4*r[i])))/2;
    }
    for (int i = 0; i < n; i++) cout << a[i]-(i == 0 ? 0 : a[i-1]) << " \n"[i == n-1];
    for (int i = 0; i < n; i++) cout << b[i]-(i == 0 ? 0 : b[i-1]) << " \n"[i == n-1];
}