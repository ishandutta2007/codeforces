#include <algorithm>
#include <iostream>
#include <string>
#include <random>
#include <chrono>
#include <vector>
#include <cmath>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

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
        if (2 * k - 1 > n)
        {
            cout << "-1\n";
            continue;
        }
        vector<string> v(n, string(n, '.'));
        int cnt = 0;
        for (int i = 0; i < n; i += 2)
        {
            v[i][i] = 'R';
            cnt++;
            if (cnt == k) break;
        }
        for (int i = 0; i < n; i++)
        {
            cout << v[i] << "\n";
        }
    }
    return 0;
}