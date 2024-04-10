#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> f(128, 0);
    for (int i = 0; i < n; i++)
    {
        int r;
        cin >> r;
        for (int j = 0; j < r; j++)
        {
            int a;
            cin >> a;
            f[a]++;
        }
    }
    for (int i = 0; i < f.size(); i++)
    {
        if (f[i] == n) cout << i << " ";
    }
    cout << "\n";
    return 0;
}