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

int a[128];
int sumv[128];
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    MEM(a, 0);
    a['e'] = 3;
    a['i'] = 1;
    a['t'] = 1;
    MEM(sumv, 0);
    string str;
    cin >> str;
    for (int i = 0; i < str.length(); i++)
    {
        sumv[str[i]] ++;
    }

    int ans = INF;
    for (int i = 'a'; i <= 'z'; i++)
    {
        if (!a[i]) continue;
        ans = min(ans, sumv[i] / a[i]);
    }
    cout << min(ans, (sumv['n'] - 1) / 2) << endl;
    return 0;
}