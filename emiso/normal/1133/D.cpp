#include <bits/stdc++.h>

#define MN 1001000

using namespace std;
typedef long long ll;

int n, ans, a[MN], b[MN], nice;
map<pair<int, int>, int> f;

int main() {
    scanf("%d", &n);

    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    for(int i = 0; i < n; i++) {
        scanf("%d", &b[i]);
    }

    for(int i = 0; i < n; i++) {
        if(a[i] == 0 && b[i] == 0) nice++;
        else if(a[i] == 0);
        else if(b[i] == 0) f[{0, 0}]++;
        else {
            if(a[i] < 0) {b[i] = -b[i]; a[i] = -a[i];}
            int g = __gcd(a[i], abs(b[i]));
            f[{-b[i] / g, a[i] / g}]++;
        }
    }

    for(auto tt : f) {
        ans = max(ans, tt.second);
    }

    printf("%d\n", ans + nice);
    return 0;
}