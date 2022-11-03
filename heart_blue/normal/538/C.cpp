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
const LL INF = 1e9 + 1;
const int N = 1e6;
vector<pair<int, int>> vp;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
    int n, m;
    cin >> n >> m;
    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        ans = max(ans, y);
        vp.push_back({ x, y });
    }
    
    for (int i = 1; i < m; i++)
    {
        int t1, h1;
        int t2, h2;
        tie(t1,h1)= vp[i - 1];
        tie(t2,h2) = vp[i];
        if (t2 - t1 < abs(h2 - h1))
        {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
        int l = t1;
        int r = t2;
        int maxv = h1;
        while (l <= r)
        {
            int mid = (l + r) / 2;
            if (h1 + (mid - t1) <= h2 + (t2 - mid)) maxv = max(maxv,(h1 + mid - t1)), l = mid + 1;
            else r = mid - 1;
        }
        ans = max(maxv, ans);
    }
    ans = max(ans, max(vp[0].second + vp[0].first - 1, vp[m - 1].second + n - vp[m - 1].first));
    cout << ans << endl;
    return 0;
}