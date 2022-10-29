#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;
const int N = 1e6;
int t;
int n, p, k;
int a[N];
bool check(int sum) {
    int all = 0;
    while (sum) {
        if (sum >= k) {
            all += a[sum];
            sum -= k;
        } else {
            all += a[sum];
            sum --;
        }
    }
    return all <= p;
}
int main() {
    scanf("%d", &t);
    while (t --) {
        scanf("%d %d %d", &n, &p, &k);
        for (int i = 1; i <= n; i ++)
            scanf("%d", &a[i]);
        sort(a + 1,a + n + 1);
        int l = 0, r = n / k, mid, s = 0;
        while (l <= r)
            if (check((mid =  (l + r) / 2) * k)) s = max(s, mid), l = mid  +1;
            else
                r = mid -1;
        int ss = 0;
        l = 0, r = n - s * k;
        while (l <= r)
            if (check((mid = (l + r) / 2) + s * k)) l = mid + 1, ss = max(ss, mid);
            else
                r = mid - 1;
        printf("%d\n", s * k + ss);
    }
    return 0;
}