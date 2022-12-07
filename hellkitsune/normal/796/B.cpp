#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n, m, k;
bool h[1000005] = {};

int main() {
    scanf("%d%d%d", &n, &m, &k);
    forn(i, m) {
        int x;
        scanf("%d", &x);
        h[x] = true;
    }
    int pos = 1;
    forn(i, k) {
        int a, b;
        scanf("%d%d", &a, &b);
        if (!h[pos]) {
            if (pos == a) pos = b;
            else if (pos == b) pos = a;
        }
    }
    cout << pos << endl;
    return 0;
}