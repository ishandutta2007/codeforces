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
    int b, g, n;
    cin >> b >> g >> n;
    int ans = 0;
    for (int gi = 0; gi <= n; gi++)
    {
        int bi = n - gi;
        if (gi <= g && bi <= b)ans++;
    }
    cout << ans << "\n";
    return 0;
}