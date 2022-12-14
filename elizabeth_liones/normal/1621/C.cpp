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

int query(int i)
{
    cout << "? " << i << endl;
    int x;
    cin >> x;
    if (!x) exit(0);
    return x;
}
int main()
{
    //ios::sync_with_stdio(false);
    //cin.tie(0);
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        vector<int> vis(n + 1, 0);
        vector<int> p(n + 1, 0);
        for (int i = 1; i <= n; i++) if (!vis[i])
        {
            vector<int> c;
            int j = query(i);
            while (!vis[j])
            {
                c.push_back(j);
                vis[j] = 1;
                j = query(i);
            }
            for (int i = 0; i < c.size(); i++)
            {
                p[c[i]] = c[(i + 1) % c.size()];
            }
        }
        cout << "! ";
        for (int i = 1; i <= n; i++) cout << p[i] << (i == n ? "" : " ");
        cout << endl;
    }
    return 0;
}