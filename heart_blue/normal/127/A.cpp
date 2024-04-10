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
const int N = 2e6;
double dist(int tx, int ty, int sx, int sy)
{
    int dx = tx - sx;
    int dy = ty - sy;
    return sqrt(dx*dx + dy*dy);
}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
    int n, k;
    cin >> n >> k;
    int tx, ty;
    int sx, sy;
    cin >> tx >> ty;
    double sum = 0;
    for (int i = 1; i < n; i++)
    {
        cin >> sx >> sy;
        sum += dist(sx, sy, tx, ty);
        tx = sx;
        ty = sy;
    }
    printf("%.7f\n", sum * k / 50);
    return 0;
}