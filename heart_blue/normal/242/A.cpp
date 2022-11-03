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
const int N = 3e3 + 10;
int a[N];
int b[31];
int main()
{
    //freopen("input.txt","r",stdin);
    int a, b, x, y;
    cin >> a >> b >> x >> y;
    vector<pair<int, int>> vp;
    for (int i = x; i <= a; i++)
    {
        for (int j = y; j <= b; j++)
        {
            if (i > j) vp.push_back({ i, j });
        }
    }
    cout << vp.size() << endl;
    for (int i = 0; i < vp.size(); i++) cout << vp[i].first << ' ' << vp[i].second << endl;
    return 0;
}