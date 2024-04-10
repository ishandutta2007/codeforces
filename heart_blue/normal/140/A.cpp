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
const int N = 1e6 + 10;
int a[N];
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
    int n, R, r;
    cin >> n >> R >> r;
    if (n == 1)
    {
        if (r <= R) cout << "YES" << endl;
        else cout << "NO" << endl;
        return 0;
    }
    if (n == 2)
    {
        if (2 * r <= R) cout << "YES" << endl;
        else cout << "NO" << endl;
        return 0;
    }
    double alpha = 360.0 / (2 * n);
    R -= r;
    if(R*sin(alpha*3.141592653 / 180) + 1e-7 >= r) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}