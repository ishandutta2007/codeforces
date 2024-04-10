#include<bits/stdc++.h>
using namespace std;

long long n, m;
int q;

int main() {
    scanf("%lld%lld%d", &n, &m, &q);

    long long d = __gcd(n, m);
    long long arr[3];
    arr[1] = n / d;
    arr[2] = m / d;

    for(int i=0; i<q; i++) {
        long long x1, y1, x2, y2;
        scanf("%lld%lld%lld%lld", &x1, &y1, &x2, &y2);

        y1--;
        y2--;

        if(y1 / arr[x1] == y2 / arr[x2]) printf("YES\n");
        else printf("NO\n");
    }
}