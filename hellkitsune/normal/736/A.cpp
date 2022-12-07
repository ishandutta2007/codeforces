#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

LL n;

int main() {
    cin >> n;
    LL a = 1, b = 2;
    int ans = 1;
    while (true) {
        LL c = a + b;
        a = b;
        b = c;
        if (c > n) {
            break;
        }
        ++ans;
    }
    cout << ans << endl;
    return 0;
}