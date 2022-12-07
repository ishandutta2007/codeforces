#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
bool was[100001] = {};

int main() {
    scanf("%d", &n);
    int pos = n;
    forn(i, n) {
        int x;
        scanf("%d", &x);
        was[x] = true;
        while (pos > 0 && was[pos]) {
            printf("%d ", pos);
            --pos;
        }
        printf("\n");
    }
    return 0;
}