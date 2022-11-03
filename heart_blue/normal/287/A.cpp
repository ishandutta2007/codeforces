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
const int N = 1e3 + 10;
char c[4][4];
int dx[] = { 0, 0, 1, 1 };
int dy[] = { 0, 1, 0, 1 };
bool check(int x, int y)
{
    int ans = 0;
    for (int i = 0; i < 4; i++)
    {
        if (c[x+dx[i]][y+dy[i]] == '#') ans++;

    }
    return ans != 2;
}
int main()
{
    // freopen("input.txt","r",stdin);
    for (int i = 0; i < 4; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cin >> c[i][j];
        }
    }
    string ans = "NO";
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (check(i, j)) ans = "YES";
        }
    }
    cout << ans << endl;
    return 0;
}