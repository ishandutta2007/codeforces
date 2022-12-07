#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int x;
string s;

int main() {
    cin >> x >> s >> s;
    if (s[0] == 'w') {
        if (x == 5 || x == 6) cout << 53 << endl;
        else cout << 52 << endl;
    } else {
        if (x <= 29) cout << 12 << endl;
        else if (x <= 30) cout << 11 << endl;
        else cout << 7 << endl;
    }
    return 0;
}