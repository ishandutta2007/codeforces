#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
long long a, b;
int sum[60];
int main() {
    scanf("%lld %lld", &a, &b);
    if (a > b) {
        printf("-1");
        return 0;
    }
    b -= a;
    if (b & 1) {
        printf("-1");
        return 0;
    }
    for (int i = 59; i >= 0; i --)
        if ((a >> i) & 1) {
            sum[i] = 1;
        }
    for (int i = 59; i >= 0; i --)
        if (b >= (1ll << (i + 1))) {
            sum[i] += 2;
            b -= (1ll << (i + 1));
        }
    vector<long long>ans;
    while (1) {
        long long v = 0;
        for (int i = 0; i <= 59; i ++)
            if (sum[i]) {
                sum[i] --;
                v += (1ll << i);
            }
        if (!v)break;
        ans.push_back(v);
    }
    printf("%d\n", ans.size());
    for (auto u:ans)
        printf("%lld ", u);
    return 0;
}