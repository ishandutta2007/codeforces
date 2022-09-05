#include <bits/stdc++.h>
using namespace std;

int T, n, m, rb, cb, rd, cd;

int main() {
    scanf("%d", &T);
    while (T--) {
        scanf("%d %d %d %d %d %d", &n, &m, &rb, &cb, &rd, &cd);
        int dx = 1, dy = 1, tim = 0;
        while (rb != rd && cb != cd) {
            if (rb + dx == 0 || rb + dx > n) dx *= -1;
            if (cb + dy == 0 || cb + dy > m) dy *= -1;
            rb += dx, cb += dy, tim++;
        }
        printf("%d\n", tim);
    }
    return 0;
}