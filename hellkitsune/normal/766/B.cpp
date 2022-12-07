#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int a[300000];

int main() {
    scanf("%d", &n);
    forn(i, n) {
        scanf("%d", a + i);
    }
    sort(a, a + n);
    forn(i, n - 2) {
        if (a[i] + a[i + 1] > a[i + 2]) {
            cout << "YES" << endl;
            return 0;
        }
    }
    cout << "NO" << endl;
    return 0;
}