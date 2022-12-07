#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

LL n;
int q;
string s;

int main() {
    ios_base::sync_with_stdio(false);
    cin >> n >> q;
    forn(i, q) {
        LL v;
        cin >> v >> s;
        for (char c : s) {
            LL bit = 1;
            while (!(v & bit)) {
                bit <<= 1;
            }
            if (c == 'U') {
                LL ov = v;
                v ^= bit;
                v |= bit << 1;
                if (v > n) {
                    v = ov;
                }
            } else if (c == 'L') {
                if (bit != 1) {
                    v ^= bit;
                    v ^= bit >> 1;
                }
            } else {
                if (bit != 1) {
                    v ^= bit >> 1;
                }
            }
        }
        cout << v << '\n';
    }
    return 0;
}