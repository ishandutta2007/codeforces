#include <cstdio>
#include <vector>
#include <algorithm>
#define int long long

using namespace std;

main()
{
    int sum_l = 0, sum_r = 0;
    int n; scanf("%I64d", &n);
    vector <int> v(n);
    for (int i = 0; i < n; i++) scanf("%I64d", &v[i]);
    sort(v.begin(), v.end());
    for (int i = 0; i < n; i++) sum_r += abs(v[i] - v[0]);
    pair <int, int> ans = {sum_l + sum_r, v[0]};
    for (int i = 1; i < n; i++)
    {
        sum_l += (i)     * (v[i] - v[i-1]);
        sum_r -= (n - i) * (v[i] - v[i-1]);
        ans = min(ans, {sum_l + sum_r, v[i]});
    }
    printf("%I64d\n", ans.second);
}