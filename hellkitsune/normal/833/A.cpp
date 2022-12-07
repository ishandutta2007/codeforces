#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define mp make_pair
#define forn(i, n) for (int i = 0; i < (int)(n); ++i)
typedef long long LL;
typedef pair<int, int> PII;

map<LL, int> ma;

int main() {
    for (int i = 1; i <= 1000000; ++i) {
        ma[(LL)i * i * i] = i;
    }
    int tc;
    scanf("%d", &tc);
    forn(test, tc) {
        int a, b;
        scanf("%d%d", &a, &b);
        LL mul = (LL)a * b;
        auto it = ma.find(mul);
        if (it == ma.end()) {
            puts("No");
            continue;
        }
        int val = it->second;
        if (a % val != 0 || b % val != 0) {
            puts("No");
        } else {
            puts("Yes");
        }
    }
    return 0;
}