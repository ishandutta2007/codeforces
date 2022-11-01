#include <bits/stdc++.h>

using namespace std;
int co;

bool query(int x, int y) {
    assert(++co <= 60);
    printf("1 %d %d\n", x, y);
    fflush(stdout);

    char st[5];
    scanf("%s", st);

    return st[0] == 'N';
}

int main() {
    int fst, scnd, n, k;
    scanf("%d %d", &n, &k);

    int l= 1, r = n;
    while(l < r) {
        int m = (l + r) / 2;
        if(query(m, m + 1))
            l = m + 1;
        else r = m;
    }

    fst = l;
    l = 1, r = fst - 1;
    while(l < r) {
        int m = (l + r) / 2;
        if(query(m, m + 1))
            l = m + 1;
        else r = m;
    }

    if(l == r && !query(l, l + 1)) {
        printf("2 %d %d\n", fst, l);
        fflush(stdout);
        return 0;
    }

    l = fst + 1, r = n;
    while(l < r) {
        int m = (l + r) / 2;
        if(query(m, m + 1))
            l = m + 1;
        else r = m;
    }

    printf("2 %d %d\n", fst, l);
    fflush(stdout);
    return 0;
}