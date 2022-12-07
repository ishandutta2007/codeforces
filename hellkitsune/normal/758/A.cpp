#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int a[1000];

int main() {
    scanf("%d", &n);
    forn(i, n) scanf("%d", a + i);
    int mx = 0;
    forn(i, n) mx = max(mx, a[i]);
    int sum = 0;
    forn(i, n) sum += mx - a[i];
    cout << sum << endl;
    return 0;
}