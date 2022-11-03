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
const int N = 1e4;
int a[N * 10];
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    MEM(a, 0);
    int sum = 0;
    for (int i = 1; i ; i++)
    {
        if (sum > N) break;
        sum += i*(i + 1) / 2;
        a[sum] = i;
    }
    for (int i = 1; i <= N; i++)
    {
        if (!a[i]) a[i] = a[i - 1];
    }
    int n;
    cin >> n;
    cout << a[n] << endl;
    return 0;
}