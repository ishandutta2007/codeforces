#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

ll ans, zeros, sum;
int k, b, n, a[100010];
map<int, int> jonson;

int main() {
    scanf("%d %d %d", &k, &b, &n);

    jonson[0]++;
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
        sum += a[i];
        sum %= (k - 1);
        jonson[sum]++;
    }

    for(int i = 0, streak = 0; i < n; i++) {
        if(a[i]) {
            streak = 0;
            continue;
        }
        zeros += ++streak;
    }

    if(b == 0) ans = zeros;
    else {
        if (b == k-1) b = 0, ans -= zeros;
        for(int i = n-1; i >= 0; i--) {
            jonson[sum]--;
            ans += jonson[(sum - b + k - 1) % (k - 1)];
            sum -= (a[i] % (k-1));
            if(sum < 0) sum += (k-1);
        }
    }
    printf("%lld\n", ans);
    return 0;
}