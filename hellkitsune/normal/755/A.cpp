#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;

bool check(int val) {
    for (int i = 2; i * i <= val; ++i) {
        if (val % i == 0) {
            return false;
        }
    }
    return true;
}

int main() {
    cin >> n;
    for (int m = 1; m <= 1000; ++m) {
        if (!check(n * m + 1)) {
            cout << m << endl;
            return 0;
        }
    }
    return 0;
}