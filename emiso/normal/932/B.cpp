#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cerr << a << endl
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

int n, l, r, k, res[MN], acum[MN][10];

int prod(int x) {
    int res = 1;
    while(x) {
        if(x % 10) res *= (x % 10);
        x /= 10;
    }
    return res;
}

int main() {
    scanf("%d", &n);

    for(int i = 1; i < MN; i++) {
        if(i < 10) res[i] = i;
        else res[i] = res[prod(i)];
    }

    for(int k = 1; k <= 9; k++) {
        for(int i = 1; i < MN; i++) {
            acum[i][k] = acum[i-1][k] + (res[i] == k);
        }
    }

    for(int i=0; i<n; i++) {
        scanf("%d %d %d", &l, &r, &k);
        printf("%d\n", acum[r][k] - acum[l-1][k]);
    }

    return 0;
}