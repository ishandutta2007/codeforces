#include <bits/stdc++.h>

using namespace std;

const int N = 110;

bool marked[N];
int l[N], r[N];

int main() {
    int n;
    scanf("%d", &n);
    for (int i = 1; i <= n; ++i) {
        scanf("%d %d", &l[i], &r[i]);
    }
    int prv = 0;
    bool ok = false;
    while (!ok) {
        int fst;
        for (int i = 1; i <= n; ++i) {
            if (!marked[i] and !l[i]) {
                fst = i;
                break;
            }
        }
        r[prv] = fst;
        l[fst] = prv;
        while (r[prv] != 0) {
            marked[prv] = true;
            prv = r[prv];
        }
        marked[prv] = ok = true;
        for (int i = 1; i <= n; ++i) {
            if (!marked[i]) {
                ok = false;
                break;
            }
        }
    }
    for (int i = 1; i <= n; ++i) {
        printf("%d %d\n", l[i], r[i]);
    }
    return 0;
}