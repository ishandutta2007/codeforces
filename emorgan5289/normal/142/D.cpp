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

int f[32];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    int n, m, k; cin >> n >> m >> k;
    int fr = 0, fg = 0;
    for (int i = 0; i < n; i++) {
        int r = -1, g = -1;
        string s; cin >> s;
        for (int j = 0; j < m; j++) {
            if (s[j] == 'R') r = j;
            if (s[j] == 'G') g = j;
        }
        if (r != -1 && g == -1) fr++;
        if (r == -1 && g != -1) fg++;
        if (r != -1 && g != -1) {
            int x = abs(r-g)-1;
            for (int j = 0; j < 32; j++)
                if (x&(1<<j)) f[j]++;
        }
        if (s == "G" || s == "GG") fg--;
        if (s == "R" || s == "RR") fr--;
    }
    if (fr > 0 && fg > 0)
        return cout << "Draw\n", 0;
    if (fr == 0 && fg > 0)
        return cout << "First\n", 0;
    if (fr > 0 && fg == 0)
        return cout << "Second\n", 0;
    bool v = 1;
    for (int i = 0; i < 32; i++)
        v = v && (f[i]%(k+1) == 0);
    cout << (v ? "Second\n" : "First\n");
}