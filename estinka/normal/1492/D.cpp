#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <iomanip>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <random>
#include <chrono>
typedef long long ll;
typedef long double ld;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int a, b, k;
    cin >> a >> b >> k;
    if (!k)
    {
        string good = string(b, '1') + string(a, '0');
        cout << "Yes\n" << good << "\n" << good << "\n";
        return 0;
    }
    if (k + 2 > a + b || b == 1 || a == 0)
    {
        cout << "No\n";
        return 0;
    }
    string x = "1", y = "1"; b--;
    while (k + 1 < a + b)
    {
        if (a > 1)
        {
            x.push_back('0');
            y.push_back('0');
            a--;
        }
        else if (b > 1)
        {
            x.push_back('1');
            y.push_back('1');
            b--;
        }
    }
    for (int i = 0; i < b; i++) x.push_back('1');
    for (int i = 0; i < a; i++) x.push_back('0');
    y.push_back('0');
    for (int i = 0; i < b - 1; i++) y.push_back('1');
    for (int i = 0; i < a - 1; i++) y.push_back('0');
    y.push_back('1');
    cout << "Yes\n" << x << "\n" << y << "\n";
    return 0;
}