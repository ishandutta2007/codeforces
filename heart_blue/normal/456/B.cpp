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
const int N = 1e5 + 10;
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
    int a[5];
    MEM(a, 0);
    for (int i = 1; i < 5; i++)
    {
        int t = 1;
        for (int j = 0; j < 5; j++)
        {
            a[j] += t;
            t *= i;
        }
    }
    for (int i = 0; i < 5; i++) a[i] %= 5;
    char c1 = '0';
    char c2 = '0';
    char c;
    while (cin >> c) c2 = c1, c1 = c;
    cout << a[((c2-'0')*10+c1 - '0')%4] << endl;
    return 0;
}