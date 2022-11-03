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

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    int a[4];
    string str;
    for (int i = 0; i < 4; i++)
    {
        cin >> str;
        a[i] = str.length() - 2;
    }
    int ans = -1;
    int key = -1;
    int tmp = -1;
    for (int i = 0; i < 4; i++)
    {
        if (tmp < a[i]) tmp = a[i], key = i;
    }
    int flag = 1;
    for (int i = 0; i < 4; i++)
    {
        if (i == key) continue;
        if (a[key] / a[i] < 2)  flag = 0;
    }
    if (flag) ans = key;
    for (int i = 0; i < 4; i++)
    {
        if (tmp > a[i]) tmp = a[i], key = i;
    }
    flag = 1;
    for (int i = 0; i < 4; i++)
    {
        if (i == key) continue;
        if (a[i] / a[key] < 2) flag = 0;
    }
    if (flag)
    {
        if (ans == -1) ans = key;
        else ans = 2;
    }
    if (ans == -1) ans = 2;
    cout << char(ans + 'A') << endl;
    return 0;
}