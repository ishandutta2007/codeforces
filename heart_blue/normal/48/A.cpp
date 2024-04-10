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
    map<string, int> ms;
    ms["rock"] = 0;
    ms["scissors"] = 1;
    ms["paper"] = 2;
    int a[3][3] = { 0, 1, -1, -1, 0, 1, 1, -1, 0 };
    vector<string> vs(3);
    for (auto &it : vs) cin >> it;
    string ans = "FMS?";
    int k = 3;
    for (int i = 0; i < vs.size(); i++)
    {
        int cnt = 0;
        for (int j = 0; j < vs.size(); j++)
        {
            cnt += a[ms[vs[i]]][ms[vs[j]]];
        }
        if (cnt == 2)
        {
            k = i;
            break;
        }
    }
    cout << ans[k] << endl;
    return 0;
}