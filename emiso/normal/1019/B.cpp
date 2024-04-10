#include <bits/stdc++.h>

#define MN 1001000

using namespace std;

int n;

void finish(int x) {
    printf("! %d\n", x);
    fflush(stdout);
    exit(0);
}

int query(int x) {
    int a, b, mult = 1;
    if(x > n/2) {
        x -= n/2;
        mult = -1;
    }

    printf("? %d\n", x);
    fflush(stdout);
    scanf("%d", &a);

    printf("? %d\n", x + n/2);
    fflush(stdout);
    scanf("%d", &b);

    if(a == b) finish(x);
    return mult*(b - a);
}

int main() {
    scanf("%d", &n);
    if(n % 4 != 0) finish(-1);

    int offset = 0, l = 1, r = n/2;

    int dif = query(1);
    if(dif < 0) offset += n/2;

    while(l < r) {
        int m = (l + r) / 2;
        if(query(m + offset) > 0) l = m + 1;
        else r = m - 1;
    }

    if(query(l) != 0) finish(-1);
    return 0;
}