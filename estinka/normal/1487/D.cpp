#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <set>
#include <chrono>
#include <random>
#include <map>
#include <bitset>
typedef long long ll;
using namespace std;

int bruteforce(int n)
{
    int ans = 0;
    for (int a = 1; a <= n; a++)
    {
        for (int b = a; b <= n; b++)
        {
            for (int c = b; c <= n; c++)
            {
                if (c * c == a * a + b * b && c == a * a - b) ans++;
            }
        }
    }
    return ans;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        ll n;
        cin >> n;
        ll h = 2 * n - 1;
        ll a = sqrt(h);
        while (a * a > h) a--;
        while ((a + 1) * (a + 1) <= h) a++;
        a = min(a, n);
        cout << (a + 1) / 2 - 1 << "\n";
        //cout << bruteforce(n) << "\n";
        //if ((a + 1) / 2 - 1 != bruteforce(n))
    }
    return 0;
}