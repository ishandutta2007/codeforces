#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n;
string t;
bitset<10000> bs[3][26];
int p[10005];

int main() {
    ios_base::sync_with_stdio(false);

    cin >> t;
    n = t.size();
    int b26 = 1;
    for (int sss = 0; sss < 3; ++sss, b26 *= 26) {
        string cur = "";
        for (int i = 0; i < n; ++i) {
            cur += char(i / b26 % 26 + 'a');
        }
        cout << "? " << cur << endl;
        string z;
        cin >> z;
        for (int i = 0; i < n; ++i)
            bs[sss][z[i] - 'a'].set(i);
    }

    for (int i = 0; i < 26; ++i) {
        for (int j = 0; j < 26; ++j) {
            for (int k = 0; k < 26; ++k) {
                int idx = i * 676 + j * 26 + k;
                if (idx >= n) continue;
                bitset<10000> cur = bs[0][k] & bs[1][j] & bs[2][i];
                int go = cur._Find_first();
                p[go] = idx;
            }
        }
    }

    string tt = t;
    for (int i = 0; i < n; ++i)
        tt[p[i]] = t[i];
    cout << "! " << tt << endl;
}