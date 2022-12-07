#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int a[200005];
int b[200005];
bool used[200005] = {};

int main() {
    scanf("%d", &n);
    forn(i, n) scanf("%d", a + i), --a[i];
    forn(i, n) scanf("%d", b + i);
    int cnt = 0;
    forn(i, n) if (!used[i]) {
        ++cnt;
        for (int j = i; !used[j]; j = a[j]) {
            used[j] = true;
        }
    }
    if (cnt == 1) {
        cnt = 0;
    }
    int z = 0;
    forn(i, n) {
        z += b[i];
    }
    if (z % 2 == 0) {
        ++cnt;
    }
    cout << cnt << endl;
    return 0;
}