#include <bits/stdc++.h>
using namespace std;

#define inf 1000000000
#define inf_ll 1000000000000000000ll
#define inf_ull 1000000000000000000ull
#define ll long long
#define ull unsigned long long
#define all(x) (x).begin(), (x).end()
#define pb push_back

#ifdef ONLINE_JUDGE
#define debug(...)
#else
#include "../../debug.cpp"
#endif

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
    int q; cin >> q;
    while (q--) {
        int n; cin >> n;
        string s, t; cin >> s >> t;
        string a1(s), a2(t);
        sort(all(a1)); sort(all(a2));
        bool v = 1;
        for (int i = 0; i < n; i++)
            v &= a1[i] == a2[i];
        if (!v) {
            cout << "-1\n"; continue;
        }
        int out = 0;
        for (int i = 0; i < n; i++) {
            int c = 0, k = 0;
            for (int j = i; j < n; j++) {
                while (k < n && s[k] != t[j])
                    k++;
                if (k >= n) break;
                c++; k++;
            }
            out = max(out, c);
        }
        cout << n-out << "\n";
    }
}