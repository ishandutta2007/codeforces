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
    int n, m;
    cin >> n >> m;
    vector<string>v(n);
    vector<int> f(m, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
        bool skip = false;
        for (int j = 0; j < i; j++)
        {
            if (v[j] == v[i])
            {
                skip = true;
                break;
            }
        }
        if (!skip)
        {
            for (int j = 0; j < m; j++)
            {
                if (v[i][j] == '#') f[j]++;
            }
        }
    }
    if (*max_element(f.begin(), f.end()) > 1) cout << "No\n";
    else cout << "Yes\n";
    return 0;
}