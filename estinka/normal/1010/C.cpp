#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <queue>
#include <iomanip>
#include <array>
#include <bitset>
#include <stack>
typedef long long ll;
typedef long double ld;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    int g = k;
    for (int i = 0, a; i < n; i++)
    {
        cin >> a; a %= k;
        g = __gcd(g, a);
    }
    cout << k / g << "\n";
    for (int i = 0; i < k; i += g) cout << i << " ";
    cout << "\n";
    return 0;
}