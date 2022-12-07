#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

string s;

int main() {
    cin >> s;
    bool was = false;
    int cnt = 0;
    for (char c : s) {
        if (c == '1') {
            was = true;
        } else if (was) {
            ++cnt;
        }
    }
    if (cnt >= 6) {
        cout << "yes" << endl;
    } else {
        cout << "no" << endl;
    }
    return 0;
}