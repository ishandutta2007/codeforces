#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <string>
#include <set>
#include <map>
typedef long long ll;
using namespace std;

const int maxn = 1e5 + 128;
vector<vector<int>> g(maxn);
vector<int> s(maxn, 0);
void dfs(int v)
{
    if (g[v].empty()) s[v] = 1;
    for (int i : g[v])
    {
        dfs(i);
        s[v] += s[i];
    }
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int p;
        cin >> p;
        g[--p].push_back(i + 1);
    }
    dfs(0);
    sort(s.begin(), s.begin() + n);
    for (int i = 0; i < n; i++)
    {
        cout << s[i] << " ";
    }
    cout << "\n";
    return 0;
}