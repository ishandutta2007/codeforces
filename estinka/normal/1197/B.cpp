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

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int m = max_element(a.begin(), a.end()) - a.begin();
    for (int i = m - 1; i >= 0; i--)
    {
        if (a[i + 1] < a[i])
        {
            cout << "NO\n";
            return 0;
        }
    }
    for (int i = m + 1; i < n; i++)
    {
        if (a[i - 1] < a[i])
        {
            cout << "NO\n";
            return 0;
        }
    }
    cout << "YES\n";
    return 0;
}