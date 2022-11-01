#include <bits/stdc++.h>

using namespace std;

int ac[1100], seq[1100], n, m, x;

int main() {
    scanf("%d %d", &n, &m);

    for(int i = 0; i < n; i++) {
        scanf("%d", &seq[i]);
    }

    for(int i = 0; i < m; i++) {
        scanf("%d", &x);
        ac[x] = 1;
    }

    for(int i = 0; i < n; i++) {
        if(ac[seq[i]]) printf("%d ", seq[i]);
    }

    return 0;
}