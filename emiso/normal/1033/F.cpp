#include <bits/stdc++.h>

using namespace std;

#define LOGN 12
#define MAXN (1 << LOGN)

int w, n, m;
char s[13];

/// b[i] = quantidade de j cujo (i op j == 0)
vector<int> FST(vector<int> &a, int p, char op) {
    vector<int> b(MAXN);
    for(int m = 0; m < (1 << w); m++) {
        int bit = (1 << p), act = ((bit & m) != 0);
        switch (op) {
        case 'A':
            if(act) b[m] = a[m-bit];
            else b[m] = a[m] + a[m+bit];
            break;
        case 'O':
            if(act) b[m] = 0;
            else b[m] = a[m];
            break;
        case 'X':
            if(act) b[m] = a[m];
            else b[m] = a[m];
            break;
        case 'a':
            if(act) b[m] = a[m];
            else b[m] = 0;
            break;
        case 'o':
            if(act) b[m] = a[m-bit] + a[m];
            else b[m] = a[m+bit];
            break;
        case 'x':
            if(act) b[m] = a[m-bit];
            else b[m] = a[m+bit];
            break;
        default:
            assert(false);
        }
    }
    return b;
}

vector<int> a(MAXN), b;

int main() {
    scanf("%d %d %d", &w, &n, &m);
    for(int i = 0; i < n; i++) {
        int x;
        scanf("%d", &x);
        a[x]++;
    }

    while(m--) {
        scanf("%s", s);
        b = a;
        for(int i = 0; i < w; i++) b = FST(b, w-1-i, s[i]);
        int ans = 0;
        for(int i = 0; i < (1 << w); i++) ans += a[i] * b[i];
        printf("%d\n", ans);
    }

    return 0;
}