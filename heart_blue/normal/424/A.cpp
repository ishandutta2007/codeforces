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
const int N = 1e6 + 10;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    string str;
    cin >> n;
    cin >> str;
    int s, S;
    s = S = 0;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == 'x') s++;
        else S++;
    }
    char c1 = 'x', c2 = 'X';
    if (s < S) swap(c1, c2);
    int d = abs(s - S);
    cout << d / 2 << endl;
    for (int i = 0; i < str.length(); i++)
    {
        if (d == 0) break;
        if (str[i] == c1) str[i] = c2, d -= 2;
    }
    cout << str << endl;

    return 0;
}