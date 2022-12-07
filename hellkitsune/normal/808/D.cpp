#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

const int INF = int(1e9);

int n;
int a[100000];
LL need = 0;
set<int> have;

int main() {
    scanf("%d", &n);
    forn(i, n) {
        scanf("%d", a + i);
        need += a[i];
    }
    if (need % 2 == 1) {
        cout << "NO" << endl;
        return 0;
    }
    need /= 2;
    forn(_, 2) {
        have.clear();
        LL sum = 0;
        forn(i, n) {
            sum += a[i];
            have.insert(a[i]);
            if (sum == need || (sum > need && have.count(sum - need))) {
                cout << "YES" << endl;
                return 0;
            }
            if (sum > need + INF) {
                break;
            }
        }
        reverse(a, a + n);
    }
    cout << "NO" << endl;
    return 0;
}