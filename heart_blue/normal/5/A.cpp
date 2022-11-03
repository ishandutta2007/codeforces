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

const int INF = 1e6 + 3;
const int N = 2e3 + 1;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    int cnt = 0;
    string str;
    int ans = 0;
    while (getline(cin, str))
    {
        if (str[0] == '+')
        {
            cnt++;
            continue;
        }
        if (str[0] == '-')
        {
            cnt--;
            continue;
        }
        ans += cnt*(str.length() - 1 - str.find(':'));
    }
    cout << ans << endl;
    return 0;
}