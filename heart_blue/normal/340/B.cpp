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

const int INF = 1e5 + 7;
const int N = 1e3 + 10;

vector<pair<int, int>> vp;

double dist(int i, int j)
{
    double dx = vp[i].first - vp[j].first;
    double dy = vp[i].second - vp[j].second;
    return sqrt(dx*dx + dy*dy);

}
double square(int i, int j, int k)
{
    double x1, y1, x2, y2, x3, y3;
    tie(x1, y1) = vp[i];
    tie(x2, y2) = vp[j];
    tie(x3, y3) = vp[k];
    return (x1*y2 * 1 + x2*y3 * 1 + x3*y1 * 1 - x1*y3 * 1 - x2*y1 * 1 - x3*y2 * 1)/2;
}


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
    double ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i == j) continue;
            double max1, max2;
            max1 = max2 = 0;
            for (int k = 0; k < n; k++)
            {
                if (i == k || j == k) continue;
                double s = square(i, j, k);
                if (s < 0) max1 = max(max1, -s);
                if (s > 0) max2 = max(max2, s);
            }
            if (abs(max1) < 1e-6 || abs(max2) < 1e-6) continue;
            ans = max(ans, max2 + max1);
        }
    }
    printf("%.9f\n", ans);
    return 0;
}