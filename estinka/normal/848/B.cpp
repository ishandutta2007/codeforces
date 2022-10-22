#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <map>
#include <set>
#include <array>
typedef long long ll;
using namespace std;

const int maxn = 1e5 + 128;
vector<int> x(maxn), y(maxn);
bool cmp(int i, int j)
{
    if (x[i] == x[j]) return y[i] < y[j];
    return x[i] > x[j];
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n, w, h;
    cin >> n >> w >> h;
    map<int, vector<int> > m;
    vector<int> p(n), t(n), ans(n);
    for (int i = 0, g; i < n; i++)
    {
        cin >> g >> p[i] >> t[i];
        x[i] = (g == 1 ? p[i] : w);
        y[i] = (g == 1 ? h : p[i]);
        m[p[i] - t[i]].push_back(i);
    }
    for (const pair<int, vector<int> >& i : m)
    {
        vector<int> v = i.second;
        sort(v.begin(), v.end(), cmp);
        int ve = 0;
        for (int j : v) if (y[j] == h) ve++;
        //for (int j : v) cout << x[j] << " " << y[j] << "\n";
        //cout << "\n";
        for (int j = 0; j < v.size(); j++)
        {
            ans[v[j]] = v[(ve + j) % v.size()];
        }
    }
    for (int i = 0; i < n; i++) cout << x[ans[i]] << " " << y[ans[i]] << "\n";
    return 0;
}