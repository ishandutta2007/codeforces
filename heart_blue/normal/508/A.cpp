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
const LL INF = 1e17;
const int N = 2e3 + 10;
int a[N][N];

bool check(int x, int y)
{
    int sum = 0;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            sum += a[x + i][y + j];
        }
    }
    return sum == 4;
}


int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    MEM(a, 0);
    int n, m;
    cin >> n >> m;
    int s;
    cin >> s;
    int x, y;
    int flag = 0;
    for (int i = 1; i <= s; i++)
    {
        cin >> x >> y;
        if (flag) continue;
        a[x][y] = 1;
        for (int oo = -1; oo <= 1; oo++)
        {
            for (int xx = -1; xx <= 1; xx++)
            {
                if (check(x + oo,y + xx)) flag = i;
            }
        }
    }
    cout << flag << endl;
    return 0;
}