#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

string a, b;
bool x, y;

bool solve(string a, string b) {
    char x = 'e', y = 'e';
    if (a[0] != 'X') {
        x = a[0];
    }
    if (a[1] != 'X') {
        if (x == 'e') x = a[1];
        else y = a[1];
    }
    if (b[1] != 'X') {
        if (y == 'e') y = b[1];
    }
    return (x == 'A' && y == 'B') || (x == 'B' && y == 'C') ||
        (x == 'C' && y == 'A');
}

int main() {
    cin >> a >> b;
    x = solve(a, b);
    cin >> a >> b;
    y = solve(a, b);
    if (x == y) {
        cout << "YES" << endl;
    } else {
        cout << "NO" << endl;
    }
    return 0;
}