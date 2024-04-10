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
void getans(int n)
{
    if (n>=5) cout << "-O|";
    else cout << "O-|";
    n %= 5;
    for (int i = 0; i < n; i++) cout << "O";
    cout << "-";
    for (int i = 0; i < 4 - n; i++) cout << "O";
    cout << endl;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    while (1)
    {
        getans(n % 10);
        n /= 10;
        if (n == 0) break;
    }

    return 0;
}