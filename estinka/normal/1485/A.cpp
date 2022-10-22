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

int f(int a, int b)
{
    int cnt = 0;
    while (a) a /= b, cnt++;
    return cnt;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int a, b;
        cin >> a >> b;
        int ans = 1e9;
        for (int i = 0; i < 60; i++)
        {
            if (b + i == 1) continue;
            ans = min(ans, f(a, b + i) + i);
        }
        cout << ans << "\n";
    }
    return 0;
}