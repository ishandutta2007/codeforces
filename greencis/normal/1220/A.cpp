#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int cnt[256];
string s;
int n;

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n >> s;
    for (int i = 0; s[i]; ++i)
        ++cnt[s[i]];
    int anszero = -1, ansone = -1;
    for (int one = 0; one * 3 <= n; ++one) {
        if ((n - one * 3) % 4) continue;
        int zero = (n - one * 3) / 4;
        if (cnt['o'] != one + zero) continue;
        if (cnt['e'] != one + zero) continue;
        if (cnt['n'] != one) continue;
        if (cnt['z'] != zero) continue;
        if (cnt['r'] != zero) continue;
        if (one + zero > anszero + ansone || (one + zero == anszero + ansone && one > ansone)) {
            ansone = one;
            anszero = zero;
        }
    }
    for (int i = 0; i < ansone; ++i) cout << "1 ";
    for (int i = 0; i < anszero; ++i) cout << "0 ";
}