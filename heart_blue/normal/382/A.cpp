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
    string str1, str2;
    cin >> str1 >> str2;
    int l, r;
    for (int i = 0; i < str1.length(); i++)
    {
        if (str1[i] == '|') l = i;
    }
    r = str1.length() - 1 - l;
    if (abs(l - r) > str2.length())
    {
        cout << "Impossible" << endl;
        return 0;
    }
    if ((l + r + str2.length()) & 1)
    {
        cout << "Impossible" << endl;
        return 0;
    }
    int t = abs(l - r);
    if (l < r)
    {
        cout << str2.substr(0, t + (str2.length()-t) / 2) << str1 << str2.substr(t + (str2.length()-t) / 2) << endl;
    }
    else
    {
        cout << str2.substr(0, (str2.length() - t) / 2) << str1 << str2.substr((str2.length() - t) / 2) << endl;
    }
    return 0;
}