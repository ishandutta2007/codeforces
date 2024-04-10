#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;

int main() {
    cin >> n;
    int a = 1, b = n;
    for (int i = 2; i * i <= n; ++i) {
        if (n % i == 0) {
            a = i;
            b = n / i;
        }
    }
    cout << a << ' ' << b << endl;
    return 0;
}