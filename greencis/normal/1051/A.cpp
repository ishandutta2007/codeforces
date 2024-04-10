#include <bits/stdc++.h>
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
using namespace std;
typedef unsigned long long ull;
typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;

const string alpha = "aA0";

bool check(const string& s) {
    int ans = 0;
    for (int i = 0; s[i]; ++i) {
        if (s[i] >= '0' && s[i] <= '9') ans |= 1;
        if (s[i] >= 'A' && s[i] <= 'Z') ans |= 2;
        if (s[i] >= 'a' && s[i] <= 'z') ans |= 4;
    }
    return ans == 7;
}

int main() {
    ios_base::sync_with_stdio(false);

    int t;
    cin >> t;
    while (t--) {
        string s;
        cin >> s;
        int n = s.size();
        if (check(s)) { cout << s << "\n"; continue; }
        int ok = 0;
        for (int i = 0; !ok && i < n; ++i) {
            for (int y = 0; y < 3; ++y) {
                string t = s;
                t[i] = alpha[y];
                if (check(t)) {
                    ok = 1;
                    cout << t << "\n";
                    break;
                }
            }
        }
        if (ok) continue;
        for (int i = 0; !ok && i + 1 < n; ++i) {
            //for (int j = 0; !ok && j < n; ++j) {
          int  j = i + 1;
                for (int y = 0; !ok && y < 3; ++y) {
                    for (int z = 0; !ok && z < 3; ++z) {
                        string t = s;
                        t[i] = alpha[y];
                        t[j] = alpha[z];
                        if (check(t)) {
                            ok = 1;
                            cout << t << "\n";
                            break;
                        }
                    }
                }
           // }
        }
    }
}