#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ll 1000000000000000000ll
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

const int maxn = 200005;
int p[maxn];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int t; cin >> t;
    while (t--) {
        string s; cin >> s;
        int n = s.size();
        p[0] = 0;
        int out = inf;
        for (int i = 1; i < n; i++) {
            p[i] = s[i] == s[i-1] ? p[i-1] : i;
            if (p[i] == i && p[i-1] != 0 && s[i] != s[p[i-1]-1])
                out = min(out, i-p[i-1]+2);
        }
        cout << (out == inf ? 0 : out) << "\n";
    }
}