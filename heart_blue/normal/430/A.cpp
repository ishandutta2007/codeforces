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
const int N = 1e3 + 10;
class Point
{
public:
    int x;
    int num;
    Point(){}
    Point(int _x, int _num) :x(_x), num(_num){}
    bool operator < (Point &p)
    {
        if (x != p.x) return x < p.x;
        return num < p.num;
    }
};

int a[N];
vector<Point> vp;
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    int n, m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        vp.push_back({ x, i });
    }
    sort(vp.begin(), vp.end());
    for (int i = 0; i < n; i++)
    {
        a[vp[i].num] = i & 1;
    }
    for (int i = 0; i < n; i++) cout << a[i] << ' ';
    return 0;
}