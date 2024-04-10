#include <bits/stdc++.h>

const int N = 1000000;

int n, perm[N];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; ++ i) {
        scanf("%d", perm + i);
        perm[i] --;
    }
    int cycles = 0;
    for (int i = 0; i < n; ++ i) {
        if (~perm[i]) {
            int j = i;
            do {
                int nxt = perm[j];
                perm[j] = -1;
                j = nxt;
            } while (j != i);
            cycles ^= 1;
        }
    }
    puts(cycles ? "Um_nik" : "Petr");
}