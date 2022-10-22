#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <deque>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <random>
#include <set>
#include <string>
#include <vector>
typedef long long ll;
typedef long double ld;
using namespace std;

const int mod = 998244353;
void upd(int& a, int b) { a = (a + b) % mod; }
int add(int a, int b) { return (a + b) % mod; }
int mul(int a, int b) { return (a * 1ll * b) % mod; }
int pwr(int a, int b = mod - 2)
{
    if (!b) return 1;
    int h = pwr(a, b >> 1);
    h = mul(h, h);
    if (b & 1) h = mul(h, a);
    return h;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n, k;
        cin >> n >> k;
        vector<int> p(n);
        bool bad = false;
        for (int i = 0; i < n; i++)
        {
            int x;
            cin >> x;
            if (x > i)
            {
                bad = true;
            }
            if (i + k >= n && x > 0)
            {
                bad = true;
            }
            p[(i + k) % n] = x;
        }
        if (bad)
        {
            cout << "0\n";
            continue;
        }
        int ans = 1;
        for (int i = 0; i < n; i++) if (p[i] <= 0)
        {
            int cnt = (p[i] == 0 ? k + 1 : n + 1);
            ans = mul(ans, min(i + 1, cnt));
        }
        cout << ans << "\n";
    }
    return 0;
}