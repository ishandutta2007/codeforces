#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cerr << a << endl
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

int n, xo[MN], used[MN], ans[MN], num, rev[MN], ansfinal[MN];
int qi0[MN], q0i[MN];

int query(int a, int b) {
    if(a == n) a = 0;
    if(b == n) b = 0;

    if(a == 0 && q0i[b] != -1) return q0i[b];
    if(b == 0 && qi0[a] != -1) return qi0[a];

    printf("? %d %d\n", a, b);
    fflush(stdout);

    int x;
    scanf("%d", &x);

    if(a == 0) q0i[b] = x;
    if(b == 0) qi0[a] = x;
    return x;
}

int main() {
    scanf("%d", &n);
    memset(qi0, -1, sizeof qi0);
    memset(q0i, -1, sizeof q0i);

    for(int i=0; i<n; i++) {
        xo[i] = (query(i, 0) ^ query(i + 1, 0));
    }

    for(int i = 0; i < n; i++) {
        memset(used, 0, sizeof used);
        int x = i, flag = 1;

        for(int k = 0; k < n; k++) {
            ans[k] = x;
            rev[x] = k;
            x ^= xo[k];

            if(x >= n || used[x]) {
                flag = 0;
                break;
            }
            used[x] = 1;
        }
        assert(!flag || x == i);

        for(int k = 0; k < n; k++) {
            if((ans[k] ^ rev[0]) != query(k, 0)) flag = 0;
            if((ans[0] ^ rev[k]) != query(0, k)) flag = 0;
        }

        if(flag) {
            num++;
            if(num == 1)
                for(int k = 0; k < n; k++)
                    ansfinal[k] = ans[k];
        }
    }


    printf("!\n%d\n", num);
    for(int i = 0; i < n; i++) {
        printf("%d ", ansfinal[i]);
    }
    fflush(stdout);

    return 0;
}