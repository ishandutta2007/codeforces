#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

LL n;

int main() {
    cin >> n;
    for (int i = 1; i <= 100000000; ++i) {
        if (n > i) {
            n -= i;
        } else {
            cout << n << endl;
            return 0;
        }
    }
    return 0;
}