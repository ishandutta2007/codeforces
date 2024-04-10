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
    int n; ld m;
    cin >> n >> m;
    vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++) cin >> b[i];
    if (*min_element(a.begin(), a.end()) == 1 || *min_element(b.begin(), b.end()) == 1)
    {
        cout << "-1\n";
        return 0;
    }
    vector<ld> stops;
    for (int i = 0; i < n; i++)
    {
        stops.push_back(a[i]);
        stops.push_back(b[(i + 1) % n]);
    }
    ld x = m;
    for (int i = stops.size() - 1; i >= 0; i--)
    {
        x += x / (stops[i] - 1.);
    }
    cout << setprecision(40) << fixed << x - m << "\n";
    return 0;
}