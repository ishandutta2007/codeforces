#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int a[100000];

int main() {
    scanf("%d", &n);
    forn(i, n) scanf("%d", a + i);
    if (n % 2 == 1) {
        cout << "Conan" << endl;
        return 0;
    }
    sort(a, a + n);
    for (int i = 0; i < n; i += 2) {
        if (a[i] != a[i + 1]) {
            cout << "Conan" << endl;
            return 0;
        }
    }
    cout << "Agasa" << endl;
    return 0;
}