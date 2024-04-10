#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define REP(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int a = 1234567, b = 123456, c = 1234;

int main() {
    cin >> n;
    for (int i = 0; i * a <= n; ++i) {
        for (int j = 0; i * a + j * b <= n; ++j) {
            int rest = n - i * a - j * b;
            if (rest % c == 0) {
                cout << "YES" << endl;
                return 0;
            }
        }
    }
    cout << "NO" << endl;
    return 0;
}