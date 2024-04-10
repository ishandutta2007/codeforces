#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#define int long long

using namespace std;

const int inf = 0x7fffffffffffffff;
int n, k, b, c;

int solve(vector <int> v, int rm)
{
    sort(v.begin(), v.end());
    for (int i = 1; i < n; i++) v[i] -= (v[0] - rm);
    v[0] -= (v[0] - rm);
    vector <int> blg(n), tax(n);
    for (int i = 0; i < n; i++)
    {
        blg[i] = (v[i] + 4) / 5;
        int coms = blg[i] * 5 - v[i];
        blg[i] *= b;
        tax[i] = blg[i] - coms * c;
    }
    multiset <int> s;
    int sum = 0;
    for (int i = 0; i < k; i++)
    {
        sum += tax[i];
        s.insert(tax[i]);
    }
    int ans = k * blg[k-1] - sum;
    for (int i = k; i < n; i++)
    {
        if (tax[i] > *s.begin())
        {
            sum -= *s.begin();
            s.erase(s.begin());
            s.insert(tax[i]);
            sum += tax[i];
        }
        ans = min(ans, k * blg[i] - sum);
    }
    return ans;
}

signed main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> k >> b >> c;
    b = min(b, 5 * c);
    vector <int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    int ans = inf;
    for (int i = 0; i < 5; i++)
        ans = min(ans, solve(v, i));
    cout << ans;
}