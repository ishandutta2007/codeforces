#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

ll t, n, ans, a[MN], x[MN], rep = -1;
vector<int> occ[MN];

ll qx(int id) {
    printf("XOR %d %d\n", 1, id + 1); fflush(stdout);
    int ret;
    scanf("%d", &ret);
    return ret;
}

ll qa(int i, int j) {
    printf("AND %d %d\n", i + 1, j + 1); fflush(stdout);
    int ret;
    scanf("%d", &ret);
    return ret;
}

int main() {
    scanf("%lld", &n);

    for(int i = 1; i < n; i++) {
        x[i] = qx(i);
        occ[x[i]].push_back(i);
        if(occ[x[i]].size() > 1) rep = x[i];
    }

    if(!occ[0].empty()) {
        a[0] = qa(0, occ[0][0]);
        for(int i = 1; i < n; i++) a[i] = a[0] ^ x[i];
    } else if(rep != -1) {
        int i = occ[rep][0], j = occ[rep][1];
        a[i] = qa(i, j);
        for(int k = 0; k < n; k++)
            if(i != k) a[k] = a[i] ^ x[i] ^ x[k];
    } else {
        int i1 = -1, i2 = -1;
        for(int i = 1; i < n; i++) {
            if(x[i] == 1) i1 = i;
            if(x[i] == 2) i2 = i;
        }
        a[0] = qa(0, i1) | qa(0, i2);
        for(int i = 1; i < n; i++) a[i] = a[0] ^ x[i];
    }

    printf("!");
    for(int i = 0; i < n; i++) printf(" %d", a[i]);
    fflush(stdout);
    return 0;
}