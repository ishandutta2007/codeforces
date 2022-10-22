#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <array>
#include <bitset>
#include <chrono>
#include <random>
typedef long long ll;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m;
    cin >> n >> m;
    vector<string> v(n);
    int xmin = n, ymin = m, xmax = 0, ymax = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        for (int j = 0; j < m; j++)
        {
            if (v[i][j] == 'B')
            {
                xmin = min(i, xmin);
                ymin = min(j, ymin);
                xmax = max(i, xmax);
                ymax = max(j, ymax);
            }
        }
    }
    cout << xmin + abs(xmin - xmax) / 2 + 1 << " " << ymin + abs(ymin - ymax) / 2 + 1 << "\n";
    return 0;
}