#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

int n;
int a = 0, b = 0;

int main() {
    scanf("%d", &n);
    forn(i, n) {
        int p, q;
        scanf("%d%d", &p, &q);
        if (p > q) ++a;
        if (q > p) ++b;
    }
    if (a > b) cout << "Mishka" << endl;
    else if (a < b) cout << "Chris" << endl;
    else cout << "Friendship is magic!^^" << endl;
    return 0;
}