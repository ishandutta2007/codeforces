#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <set>
#include <map>
#include <array>
typedef long long ll;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> m(n), mini(n + 1, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> m[i];
        mini[i + 1] = m[i] + 1;
    }
    for (int i = n - 1; i >= 0; i--) mini[i] = max(mini[i], mini[i + 1] - 1);
    for (int i = 1; i <= n; i++) mini[i] = max(mini[i], mini[i - 1]);
    ll sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += mini[i + 1] - m[i] - 1;
    }
    cout << sum << "\n";
    return 0;
}