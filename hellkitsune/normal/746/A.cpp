#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int a, b, c;

int main() {
    cin >> a >> b >> c;
    int ans = 0;
    while (a >= 1 && b >= 2 && c >= 4) {
        a -= 1;
        b -= 2;
        c -= 4;
        ans += 7;
    }
    cout << ans << endl;
    return 0;
}