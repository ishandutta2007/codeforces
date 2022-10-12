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

vector<array<int, 2>> out;

void merge(int i, int k) {
    if (k <= 1) return;
    merge(i, k/2), merge(i+k/2, k/2);
    for (int j = i; j < i+k/2; j++)
        out.pb({j, j+k/2});
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n; cin >> n;
    int p = 0;
    for (int k = 0; k < 25; k++)
        if (n&1<<k) merge(p, 1<<k), p += 1<<k;
    p = 0;
    int y = 0;
    for (int k = 0; k < 25; k++)
        if (n&1<<k) {
            int w = 1<<k;
            int r = p+w;
            if (p == 0 || r == n) {
                p += w; continue;
            }

            while (p+y < r-p) {
                int py = y;
                for (int i = n-1; i > n-1-py; i--)
                    out.pb({i, n-1-y}), y++;
                for (int i = 0; i < p; i++)
                    out.pb({i, n-1-y}), y++;
            }

            int x = p;
            for (int i = n-1; i > n-1-y; i--)
                out.pb({i, x}), x++;
            for (int i = 0; i < p; i++)
                out.pb({i, x}), x++;

            p += w;
        }
    cout << out.size() << "\n";
    for (auto& [a, b] : out)
        cout << a+1 << " " << b+1 << "\n";
}