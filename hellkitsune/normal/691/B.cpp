#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const string GOOD = {"AHIMOTUVWXYovwx"};
string s;
set<char> se;

int main() {
    for (char c : GOOD) se.insert(c);
    cin >> s;
    int n = (int)s.length();
    REP(i, n / 2) {
        if (s[i] == s[n - 1 - i]) {
            if (!se.count(s[i])) {
                cout << "NIE" << endl;
                return 0;
            }
        } else {
            bool ok = false;
            if (s[i] == 'p' && s[n - 1 - i] == 'q') ok = true;
            if (s[i] == 'q' && s[n - 1 - i] == 'p') ok = true;
            if (s[i] == 'b' && s[n - 1 - i] == 'd') ok = true;
            if (s[i] == 'd' && s[n - 1 - i] == 'b') ok = true;
            if (!ok) {
                cout << "NIE" << endl;
                return 0;
            }
        }
    }
    if (n % 2 == 1 && !se.count(s[n / 2])) {
        cout << "NIE" << endl;
        return 0;
    }
    cout << "TAK" << endl;
    return 0;
}