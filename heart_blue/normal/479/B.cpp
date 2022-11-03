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
const LL INF = 1e9 + 7;
const int N = 2e3 + 10;
int a[N];
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
    int n, m;
    cin >> n >> m;
    vector<int> ans;
    for (int i = 1; i <= n; i++) cin >> a[i];
    if (n == 1)
    {
        cout << "0 0" << endl;
        return 0;
    }
    int k = m;
    while (m--)
    {
        int k1, k2;
        int maxv, minv;
        maxv = -1;
        minv = INF;
        for (int i = 1; i <= n; i++)
        {
            if (maxv < a[i]) maxv = a[i], k1 = i;
            if (minv > a[i]) minv = a[i], k2 = i;
        }
        if (k1 == k2) break;
        a[k1]--;
        a[k2]++;
        ans.push_back(k1);
        ans.push_back(k2);

    }
    int maxv = -1;
    int minv = INF;
    for (int i = 1; i <= n; i++)
    {
        maxv = max(maxv, a[i]);
        minv = min(minv, a[i]);
    }
    cout << maxv - minv << ' ' << ans.size() / 2 << endl;
    for (int i = 0; i < ans.size(); i += 2)
    {
        cout << ans[i] << ' ' << ans[i + 1] << endl;
    }

    return 0;
}