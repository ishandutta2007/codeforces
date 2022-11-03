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
    
    int n, m;
    cin >> n >> m;
    vector<string> vs(4);
    int l = 1;
    int r = n;
    while (m--)
    {
        for (auto &it : vs) cin >> it;
        int t;
        cin >> t;
        if (vs[2] == "left") r = min(r, t - 1);
        else l = max(l, t + 1);
    }
    if (r >= l) cout << r - l + 1 << endl;
    else cout << -1 << endl;
    return 0;
}