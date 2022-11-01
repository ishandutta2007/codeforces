#include <bits/stdc++.h>

#define MX 1000100
#define MN 3003000
#define w1 while(1)
#define debug(a) cout << a << endl
#define pb push_back
#define mp make_pair

using namespace std;
typedef long long ll;

int n, a[MX], queryLeft[MX], queryRight[MX];
ll dev, best, bestIdx;
//char s[MN]; string str;

int bit[MN][2];

void update(int idx, int delta, int t) {
    idx += MX;
    for(; idx < MN; idx += (idx & -idx)) bit[idx][t] += delta;
}

int query(int idx, int t) {
    idx += MX;
    int ret = 0;
    for(; idx; idx -= (idx & -idx)) ret += bit[idx][t];
    return ret;
}

int main() {
    scanf("%d", &n);

    for(int i=1; i<=n; i++) {
        scanf("%d",&a[i]);
        dev += abs(a[i] - i);

        int rangeLeft = i - 1;
        queryLeft[i] = 2*query(n - i, 0) - rangeLeft;

        update(a[i] - i, 1, 0);
        update(n + a[i] - i, -1, 0);
    }

    for(int i=n; i>=1; i--) {
        int rangeRight = n - i;
        queryRight[i] = rangeRight - 2*query(n - i, 1);

        update(a[i] - i, 1, 1);
        update(n + a[i] - i, -1, 1);
    }

    best = dev;

    for(int i=0; i<n; i++) {
        dev += (a[n - i] - n) + (a[n - i] - 1);

        dev += queryLeft[n - i] + queryRight[n - i];


        if(best > dev) {
            best = dev;
            bestIdx = i + 1;
        }
    }

    printf("%lld %lld\n", best, bestIdx);
    return 0;
}