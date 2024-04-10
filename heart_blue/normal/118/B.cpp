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
string num2str(int n)
{
    string str;
    if (n == 0) return "0";
    for (int i = 0; i <= n; i++)  str.push_back('0' + i), str.push_back(' ');
    for (int i = n - 1; i >= 0; i--) str.push_back('0' + i), str.push_back(' ');
    str.pop_back();
    return str;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cout << string((n - i) * 2, ' ');
        cout << num2str(i) << endl;
    }
    for (int i = n; i >= 0; i--)
    {
        cout << string((n - i) * 2, ' ');
        cout << num2str(i) << endl;
    }
    return 0;
}