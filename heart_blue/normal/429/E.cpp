#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define MIN(a,b) ((a) < (b) ? (a) : (b))
#define MEM(a,b) memset((a),(b),sizeof(a))

const LL INF = 1e7 + 7;
const int N = 2e5 + 10;

vector<int> v[N];
vector<pair<int, int>> vp;
int ans[N];

void dfs(int cur, int clr)
{
    if (ans[cur] >= 0) return;
    ans[cur] = clr;
    for (int i = 0; i < v[cur].size(); i++)
    {
        dfs(v[cur][i], clr ^ 1);
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    MEM(ans, -1);
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        v[i * 2].push_back(i * 2 + 1);
        v[i * 2 + 1].push_back(i * 2);
        vp.push_back({ 2 * x, i * 2 });
        vp.push_back({ 2 * y + 1, i * 2 + 1 });
    }

    sort(vp.begin(), vp.end());
    for (int i = 0; i < vp.size(); i += 2)
    {
        int a = vp[i].second;
        int b = vp[i + 1].second;
        v[a].push_back(b);
        v[b].push_back(a);
    }
    for (int i = 0; i < 2 * n; i++) dfs(i, 0);
    for (int i = 0; i < n; i++) cout << ans[i * 2] << ' ';
    return 0;
}