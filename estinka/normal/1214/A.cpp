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
    int n, d, e;
    cin >> n >> d >> e;
    e *= 5;
    int ans = n;
    for (int id = 0; id <= n; id += d)
    {
        int ie = ((n - id) / e) * e;
        ans = min(ans, n - id - ie);
    }
    cout << ans << "\n";
    return 0;
}