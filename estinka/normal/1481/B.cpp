#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

const int maxh = 179;
int roll(vector<int>& h)
{
    for (int i = 0; i < h.size() - 1; i++)
    {
        if (h[i + 1] > h[i]) return i;
    }
    return -1;
}
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
        vector<int> h(n, 0);
        for (int i = 0; i < n; i++)
        {
            cin >> h[i];
        }
        int need = 0;
        for (int i = 0; i < min(k - 1, n*maxh); i++)
        {
            int in = roll(h);
            if (in == -1) break;
            h[in]++;
        }
        int in = roll(h);
        cout << (in == -1 ? -1 : in + 1) << "\n";
    }
    return 0;
}