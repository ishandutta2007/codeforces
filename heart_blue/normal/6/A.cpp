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

    vector<string> vs = { "IMPOSSIBLE", "SEGMENT", "TRIANGLE" };
    int flag = 0;
    vector<int> v(4);
    for (int i = 0; i < 4; i++) cin >> v[i];
    sort(v.begin(), v.end());
    for (int i = 0; i < 2; i++)
    {
        if (v[i] + v[i + 1] > v[i + 2]) flag = 2;
        if (v[i] + v[i + 1] == v[i + 2] && !flag) flag = 1;
    }
    cout << vs[flag] << endl;
    return 0;
}