#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

LL n, k;

int main() {
    cin >> n >> k;
    LL can = n / 2 / (k + 1);
    cout << can << ' ' << can * k << ' ' << n - can * (k + 1) << endl;
    return 0;
}