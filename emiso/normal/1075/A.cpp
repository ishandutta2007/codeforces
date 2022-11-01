#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n, x, y, w, b;

int main() {
    scanf("%lld %lld %lld", &n, &x, &y);
    w = max(x, y) - 1;
    b = max(n - x, n - y);

    if(w <= b) printf("White\n");
    else printf("Black\n");
    return 0;
}