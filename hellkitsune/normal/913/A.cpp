#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m;

int main() {
    cin >> n >> m;
    int mod = 1;
    forn(i, n) {
        mod = 2 * mod;
        if (mod >= int(2e8)) {
            break;
        }
    }
    cout << m % mod << endl;
    return 0;
}