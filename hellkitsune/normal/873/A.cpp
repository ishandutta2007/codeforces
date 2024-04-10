#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, k, x;
int a[100];

int main() {
    cin >> n >> k >> x;
    forn(i, n) {
        cin >> a[i];
    }
    forn(i, k) {
        a[n - 1 - i] = min(a[n - 1 - i], x);
    }
    int sum = 0;
    forn(i, n) sum += a[i];
    cout << sum << endl;
    return 0;
}