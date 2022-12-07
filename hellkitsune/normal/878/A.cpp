#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int a[10];
char s[10];
int x;

int main() {
    scanf("%d", &n);
    forn(i, n) {
        scanf("%s%d", s, &x);
        if (s[0] == '|') {
            forn(i, 10) if (x & (1 << i)) {
                a[i] = 3;
            }
        } else if (s[0] == '&') {
            forn(i, 10) if (!(x & (1 << i))) {
                a[i] = 2;
            }
        } else {
            forn(i, 10) if (x & (1 << i)) {
                a[i] ^= 1;
            }
        }
    }
    printf("3\n");
    int mask = 1023;
    forn(i, 10) if (a[i] == 2) mask ^= 1 << i;
    printf("& %d\n", mask);
    mask = 0;
    forn(i, 10) if (a[i] == 3) mask ^= 1 << i;
    printf("| %d\n", mask);
    mask = 0;
    forn(i, 10) if (a[i] == 1) mask ^= 1 << i;
    printf("^ %d\n", mask);
    return 0;
}