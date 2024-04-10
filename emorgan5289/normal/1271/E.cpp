#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ull 1000000000000000000
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()

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

vector<ull> border;

ull count(ull x, ull n) {
    if (x > n) return 0;
    for (auto y : border)
        if (x == y)
            return 1+count(2*x, n)+count(2*x+1, n);
    return 1+2*count(2*x, n);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    ull n, k; fin >> n >> k;
    ull a = 0, b = n, u = n;
    while (u > 0) {
        border.push_back(u); u /= 2;
    }
    // even
    while (a < b) {
        ull m = (a+b+1)/2;
        ull s = count(2*m, n) + count(2*m+1, n);
        if (s < k) b = m-1;
        else a = m;
    }
    ull t1 = 2*a;
    // odd
    a = 0, b = n;
    while (a < b) {
        ull m = (a+b+1)/2;
        ull s = count(2*m+1, n);
        if (s < k) b = m-1;
        else a = m;
    }
    ull t2 = 2*a+1;
    // debug(t1, t2);
    cout << max(t1, t2) << "\n";
}