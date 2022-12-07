#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

char cur = 'a';
string s;

int main() {
    cin >> s;
    for (char c : s) {
        if (c > cur) {
            cout << "NO" << endl;
            return 0;
        }
        if (c == cur) {
            ++cur;
        }
    }
    cout << "YES" << endl;
    return 0;
}