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
const int N = 1e3 + 1;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    string str;
    map<string, int> ms;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        ms[str]++;
    }
    string ans;
    int maxv = 0;
    for (auto &it : ms) if (it.second>maxv) ans = it.first, maxv = it.second;
    cout << ans << endl;
    return 0;
}