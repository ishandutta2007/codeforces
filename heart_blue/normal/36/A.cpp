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
const int N = 2e6;

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt", "w", stdout);
    int n;
    string str;
    cin >> n;
    cin >> str;
    map<int, int> m;
    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] == '1')
        {
            str = str.substr(i);
            break;
        }
    }
    while (!str.empty() && str.back() == '0') str.pop_back();
    int pre = 0;
    for (int i = 1; i < str.length(); i++)
    {
        if (str[i] == '1') m[i - pre] ++, pre = i;
    }
    if (m.size() <= 1) cout << "YES" << endl;
    else cout << "NO" << endl;
    return 0;
}