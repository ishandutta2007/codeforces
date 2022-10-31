#include <bits/stdc++.h>

#define MN 1001000
#define w1 while(1)
#define debug(a) cerr << a << endl
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

void no() {
    printf("-1\n");
    exit(0);
}

int n, k, arr[MN];

void mrg(int l, int r, int c, int a) {
    if(c % 2 == 0) no();
    if(l + 1 == r && c > 1) no();

    int m = (l + r) / 2;

    if(c == 1) {
        for(int i = l; i < r; i++)
            arr[i] = i - l + a;
        return;
    }

    if((c / 2) % 2 == 1) {
        mrg(l, m, c/2, a + (r-l+1)/2);
        mrg(m, r, c/2, a);
    }

    else {
        mrg(l, m, c/2 - 1, a +(r-l+1)/2);
        mrg(m, r, c/2 + 1, a);
    }
}

int main() {
    scanf("%d %d", &n, &k);

    mrg(0, n, k, 0);

    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i] + 1);
    }
    return 0;
}