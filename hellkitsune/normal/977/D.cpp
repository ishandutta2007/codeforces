#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
LL a[100];
pair<int, LL> p[100];

int main() {
    cin >> n;
    forn(i, n) cin >> a[i];
    forn(i, n) {
        int bal = 0;
        LL rem = a[i];
        while (rem % 2 == 0) {
            rem /= 2;
            ++bal;
        }
        while (rem % 3 == 0) {
            rem /= 3;
            --bal;
        }
        p[i] = mp(bal, a[i]);
    }
    sort(p, p + n);
    forn(i, n) cout << p[i].second << ' ';
    cout << endl;
    return 0;
}