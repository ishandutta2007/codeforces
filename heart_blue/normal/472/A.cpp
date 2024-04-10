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
const int N = 1e6 + 10;
int a[N];
void init()
{
    MEM(a, 0);
    
    for (int i = 2; i < N; i++)
    {
        for (int j = i + i; j < N; j += i) a[j] = 1;
    }
}
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    init();
    int n;
    cin >> n;
    for (int i = 4; i <= n - i; i++)
    {
        if (a[i] && a[n - i])
        {
            cout << i << ' ' << n - i << endl;
            break;
        }
    }
    return 0;
}