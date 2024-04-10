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
    int n, p, k;
    cin >> n >> p >> k;
    if (p - k >= 2) cout << "<< ";
    for (int i = max(p - k, 1); i < p; i++) cout << i << ' ';
    cout << '(' << p << ')' << ' ';
    for (int i = p + 1; i <= min(p + k, n); i++) cout << i << ' ';
    if (p + k < n) cout << ">>";
    return 0;
}