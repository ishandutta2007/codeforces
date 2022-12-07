#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int a[50];

int main() {
    scanf("%d", &n);
    forn(i, n) scanf("%d", a + i);
    int alice = 0, bob = 0;
    for (int i = n - 1; i >= 0; --i) {
        int nalice = max(alice, bob + a[i]);
        int nbob = min(alice, bob + a[i]);
        alice = nalice;
        bob = nbob;
    }
    alice = bob;
    bob = 0;
    forn(i, n) bob += a[i];
    bob -= alice;
    cout << alice << ' ' << bob << endl;
    return 0;
}