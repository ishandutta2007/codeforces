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

const int INF = 1e9 + 7;
const int N = 2e5 + 1;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    string str;
    cin >> str;
    int cnt = 0;
    for (auto c : str) if (c == '4' || c == '7') cnt++;
    if (cnt == 0)
    {
        cout << "NO" << endl;
        return 0;
    }
    while (cnt)
    {
        if (cnt % 10 != 4 && cnt % 10 != 7)
        {
            cout << "NO" << endl;
            return 0;
        }
        cnt /= 10;
    }
    cout << "YES" << endl;
    return 0;
}