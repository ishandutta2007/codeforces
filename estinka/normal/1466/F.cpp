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
typedef long long ll;
typedef long double ld;
using namespace std;

const ll mod = 1e9 + 7;
class DSU
{
public:
    vector<int>p, s, num;
    DSU(int n) :p(n), s(n, 1), num(n, 0)
    {
        for (int i = 0; i < n; i++) p[i] = i;
    }
    int highest(int v)
    {
        int a = v;
        while (a != p[a])
        {
            a = p[a];
        }
        while (v != p[v])
        {
            int tmp = p[v];
            p[v] = a;
            v = tmp;
        }
        return v;
    }
    bool merge(int a, int b, int size)
    {
        a = highest(a);
        b = highest(b);
        if (a != b)
        {
            if (s[a] < s[b]) swap(a, b);
            s[a] += s[b];
            p[b] = a;
            num[a] += num[b];
            if (num[a] < s[a])
            {
                num[a]++;
                return true;
            }
            return false;
        }
        if (size == 2) return false;
        if (num[a] < s[a])
        {
            num[a]++;
            return true;
        }
        return false;
    }
};
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, m, s = 0;
    cin >> n >> m;
    DSU dsu(m);
    vector<vector<int> > x(n);
    for (int i = 0; i < n; i++)
    {
        int k;
        cin >> k;
        for (int j = 0; j < k; j++)
        {
            int a;
            cin >> a;
            x[i].push_back(--a);
        }
    }
    ll ans = 1;
    vector<int> b;
    for (int i = 0; i < n; i++)
    {
        if (dsu.merge(x[i][0], x[i].back(), x[i].size()))
        {
            ans = (ans * 2ll) % mod;
            b.push_back(i);
        }
    }
    cout << ans << " " << b.size() << "\n";
    for (int i = 0; i < b.size(); i++)
    {
        cout << b[i] + 1 << " ";
    }
    cout << "\n";
    return 0;
}