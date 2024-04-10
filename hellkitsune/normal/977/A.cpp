#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, k;

int main() {
    cin >> n >> k;
    forn(i, k) {
        if (n % 10 == 0) {
            n /= 10;
        } else {
            --n;
        }
    }
    cout << n << endl;
    return 0;
}