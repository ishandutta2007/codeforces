#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int cnt;
string s;

int dif(string t) {
    int res = 0;
    if (t[0] != s[0]) ++res;
    if (t[1] != s[1]) ++res;
    return res;
}

int main() {
    cin >> cnt >> s;
    if ((s[3] - '0') * 10 + s[4] - '0' > 59) {
        s[3] = '0';
    }
    string best = "01";
    int mn = 3;
    if (cnt == 24) {
        forn(i, 24) {
            string x = "00";
            x[0] = '0' + (i / 10);
            x[1] = '0' + (i % 10);
            int cur = dif(x);
            if (cur < mn) {
                mn = cur;
                best = x;
            }
        }
    } else {
        for (int i = 1; i <= 12; ++i) {
            string x = "00";
            x[0] = '0' + (i / 10);
            x[1] = '0' + (i % 10);
            int cur = dif(x);
            if (cur < mn) {
                mn = cur;
                best = x;
            }
        }
    }
    cout << best << ":" << s[3] << s[4] << endl;
    return 0;
}