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
const int INF = 1e9 + 3;
const int N = 4e4 + 10;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    vector<string> vs = { "Sheldon", "Leonard", "Penny", "Rajesh", "Howard" };
    int n;
    cin >> n;
    LL t = 5;
    while (n > t) n -= t, t *= 2;
    int c = (n - 1) / (t / 5);
    cout << vs[c] << endl;
    return 0;
}