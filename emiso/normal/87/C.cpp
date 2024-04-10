#include <bits/stdc++.h>

using namespace std;

int n, grundy[100010], gxor[100010], active[100010], ans;

void calc(int n) {
    for(int i = 3; i <= n; i++) {
        vector<int> ch;

        for(long long p = 2; p*(p+1)/2 <= i; p++) {
            int esc = p*(p+1)/2;
            int rem = i - esc;
            if(rem % p) continue;
            int value = gxor[rem/p + p] ^ gxor[rem/p];

            active[value] = 1;
            if(i == n && value == 0 && ans == 0) ans = p;
            ch.push_back(value);
        }

        int x = 0;
        while(active[x]) x++;
        grundy[i] = x;
        gxor[i] = gxor[i-1] ^ grundy[i];

        for(int y : ch) active[y] = 0;
    }
}

int main() {
    scanf("%d", &n);
    calc(n);
    if(grundy[n] == 0) puts("-1");
    else printf("%d\n", ans);
    return 0;
}