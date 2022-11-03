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
int a[N];
int getans(int p, int t)
{
    return max(3 * p / 10,p - p*t / 250);
}
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    int x = getans(a, c);
    int y = getans(b, d);
    if (x == y) cout << "Tie";
    if (x > y) cout << "Misha";
    if (x < y) cout << "Vasya";
    return 0;
}