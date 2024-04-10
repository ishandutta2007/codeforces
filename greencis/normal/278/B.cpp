#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

int n;
string s[30];

int main() {
    ios_base::sync_with_stdio(false);

    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> s[i];
    string z = "a";
    for (int i = 0; i < 26; ++i) {
        int ok = 1;
        for (int j = 0; j < n; ++j) {
            if (s[j].find(z) != string::npos) {
                ok = 0;
                break;
            }
        }
        if (ok) {
            cout << z << endl;
            return 0;
        }
        ++z[0];
    }
    z = "aa";
    for (int i = 0; i < 676; ++i) {
        int ok = 1;
        for (int j = 0; j < n; ++j) {
            if (s[j].find(z) != string::npos) {
                ok = 0;
                break;
            }
        }
        if (ok) {
            cout << z << endl;
            return 0;
        }
        ++z[1];
        if (z[1] > 'z')
            z[1] = 'a', ++z[0];
    }
}