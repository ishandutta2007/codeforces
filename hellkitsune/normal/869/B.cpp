#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

LL a, b;

int main() {
    LL x = 1;
    cin >> a >> b;
    for (LL i = a + 1; i <= b; ++i) {
        x = x * (i % 10) % 10;
        if (x == 0) {
            break;
        }
    }
    cout << x << endl;
    return 0;
}