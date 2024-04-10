#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <iomanip>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <random>
#include <list>
#include <array>
#include <fstream>
#include <chrono>
typedef long long ll;
typedef long double ld;
using namespace std;

const int maxc = 1079;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, k;
    cin >> n >> k;
    vector<int> f(maxc, 0), a(k);
    for (int i = 0; i < k; i++)
    {
        cin >> a[i];
    }
    if (*min_element(a.begin(), a.end()) > n || *max_element(a.begin(), a.end()) < n)
    {
        cout << "-1\n";
        return 0;
    }
    int mini = *min_element(a.begin(), a.end());
    n -= mini;
    vector<int> delta;
    vector<int> dist(maxc * 2, 1e9);
    queue<int> q;
    for (int i = 0; i < k; i++)
    {
        f[a[i] - mini]++;
    }
    for (int i = 0; i < maxc; i++)
    {
        if (!f[i]) continue;
        delta.push_back(i - n);
        if (i - n >= 0)
        {
            dist[i - n] = 1;
            q.push(i - n);
        }
    }
    // chceme skoncit na vrchole 0. Zacat mozeme na lubovolnom a[i] - n;
    while (!q.empty())
    {
        int f = q.front();
        q.pop();
        for (int i : delta)
        {
            int nw = f + i;
            if (nw < dist.size() && nw >= 0 && dist[nw] > dist[f] + 1)
            {
                q.push(nw);
                dist[nw] = dist[f] + 1;
            }
        }
    }
    cout << dist[0] << "\n";
    return 0;
}