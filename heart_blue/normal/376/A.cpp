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
    string str;
    int key;
    cin >> str;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '^')
        {
            key = i;
            break;
        }
    }
    LL sum = 0;
    for (int i = key; i >= 0; i--)
    {
        if (isdigit(str[i])) sum += LL(str[i] - '0')*(key - i);
    }
    for (int i = key; i < str.length(); i++)
    {
        if (isdigit(str[i])) sum -= LL(str[i] - '0')*(i - key);
    }
    if (sum > 0) cout << "left";
    if (sum == 0) cout << "balance";
    if (sum < 0) cout << "right";
    return 0;
}