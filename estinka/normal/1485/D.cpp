#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
#include <map>
#include <queue>
typedef long long ll;
typedef long double ld;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int lcm = 16 * 9 * 5 * 7 * 11 * 13;
    for (int j = 1; j <= 16; j++)
        if (lcm % j != 0) 
            exit(0);
    int n, m;
    cin >> n >> m;
    vector<vector<int> > a(n, vector<int>(m));
    for (int i = 0; i < n; i++) for (int j = 0; j < m; j++) cin >> a[i][j];
    vector<vector<int> > b(n, vector<int>(m, lcm));
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            if ((i + j) % 2 == 0) 
                b[i][j] += a[i][j] * a[i][j] * a[i][j] * a[i][j];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cout << b[i][j] << " ";
        cout << "\n";
    }
    return 0;
}