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

const int INF = 1e9 + 7;
const int N = 1e3 + 10;
vector<pair<int, int>> vp;
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int x, y;
        cin >> x >> y;
        vp.push_back({ x, y });
    }
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        int sum = 0;
        for (int j = 0; j < n; j++)
        {
            if (i == j) continue;
            if (vp[i].first == vp[j].first)
            {
                if (vp[i].second > vp[j].second) sum |= 1;
                if (vp[i].second < vp[j].second) sum |= 2;
            }
            if (vp[i].second == vp[j].second)
            {
                if (vp[i].first > vp[j].first) sum |= 4;
                if (vp[i].first < vp[j].first) sum |= 8;
            }
        }
        if (sum == 15) ans++;

    }
    cout << ans << endl;
    return 0;
}