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
const int N = 5e3 + 10;
int dp[N];
int pre[N];
vector<pair<pair<int, int>,int>> vp;
bool cmp(pair<int, int> p1, pair<int, int> p2)
{
    return p1.first > p2.first && p1.second > p2.second;
}

void output(int k)
{
    if (k == -1) return;
    output(pre[k]);
    cout << vp[k].second << ' ';
    
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt", "w", stdout);

    int n, w, h;
    cin >> n >> w >> h;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        if (x <= w ||y <= h) continue;
        vp.push_back({ { x, y }, i+1 });
    }
    if (vp.empty())
    {
        cout << 0 << endl;
        return 0;
    }
    sort(vp.begin(), vp.end());
    for (int i = 0; i < vp.size(); i++)
    {
        pre[i] = -1;
        dp[i] = 0;
        for (int j = 0; j < i; j++)
        {
            if (cmp(vp[i].first, vp[j].first))
            {
                if (dp[i] < dp[j])
                {
                    pre[i] = j;
                    dp[i] = dp[j];
                }
            }
        }
        dp[i]++;
    }
    int maxv = 0;
    int k = -1;
    for (int i = 0; i < vp.size(); i++)
    {
        if (maxv < dp[i]) maxv = dp[i], k = i;
    }
    cout << maxv << endl;
    output(k);
    return 0;
}