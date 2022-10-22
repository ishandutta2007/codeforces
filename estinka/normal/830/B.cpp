#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <queue>
typedef long long ll;
typedef long double ld;
using namespace std;

const int maxn2 = 1 << 18, inf = 1e9;
vector<int> l(maxn2 * 2), r(maxn2 * 2), sum(maxn2 * 2, 0), mini(maxn2 * 2, inf);
void remove_card(int card, int vr = 0)
{
    if (l[vr] > card || r[vr] < card) return;
    if (l[vr] == r[vr] && l[vr] == card)
    {
        sum[vr] = 0;
        mini[vr] = inf;
        return;
    }
    remove_card(card, vr * 2 + 1);
    remove_card(card, vr * 2 + 2);
    sum[vr] = sum[vr * 2 + 1] + sum[vr * 2 + 2];
    mini[vr] = min(mini[vr * 2 + 1], mini[vr * 2 + 2]);
}
int range_sum(int li, int ri, int vr = 0)
{
    if (ri < l[vr] || li > r[vr]) return 0;
    if (li <= l[vr] && r[vr] <= ri) return sum[vr];
    return range_sum(li, ri, vr * 2 + 1) + range_sum(li, ri, vr * 2 + 2);
}
int first_mini(int li, int val, int vr = 0)
{
    vr += maxn2 - 1 + li;
    if (mini[vr] == val) return li;
    for (; vr; vr = (vr - 1) / 2)
    {
        int dad = (vr - 1) / 2, ls = dad * 2 + 1, rs = dad * 2 + 2;
        if (vr != rs && mini[rs] == val)
        {
            vr = rs;
            break;
        }
    }
    for (; l[vr] != r[vr];)
    {
        int ls = vr * 2 + 1, rs = vr * 2 + 2;
        if (mini[ls] == val) vr = ls;
        else vr = rs;
    }
    return vr - maxn2 + 1;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        mini[i + maxn2 - 1] = mini[i + n + maxn2 - 1] = a[i];
        sum[i + maxn2 - 1] = sum[i + n + maxn2 - 1] = 1;
    }
    for (int i = maxn2 * 2 - 1; i >= maxn2 - 1; i--) l[i] = r[i] = i - (maxn2 - 1);
    for (int i = maxn2 - 2; i >= 0; i--)
    {
        mini[i] = min(mini[i * 2 + 1], mini[i * 2 + 2]);
        sum[i] = sum[i * 2 + 1] + sum[i * 2 + 2];
        l[i] = l[i * 2 + 1];
        r[i] = r[i * 2 + 2];
    }
    int pos = 0; ll ans = 0;
    while (mini[0] != inf)
    {
        int val = mini[0];
        int i = first_mini(pos, val);
        ans += range_sum(pos, i);
        pos = i % n;
        remove_card(pos);
        remove_card(pos + n);
    }
    cout << ans << "\n";
    return 0;
}