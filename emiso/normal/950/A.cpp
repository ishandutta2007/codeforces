#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int l, r, a, ans;

int main() {
    scanf("%d %d %d", &l, &r, &a);
    if(l > r) swap(l, r);
    if(l + a > r) {
        a -= (r - l);
        l = r;
    } else {
        l += a;
        a = 0;
    }
    printf("%d\n", 2*(l + (a / 2)));
    return 0;
}