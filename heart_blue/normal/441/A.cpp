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
const double eps = 1e-10;
const int N = 1e5 + 10;

int main()
{
    //freopen("input.txt", "r", stdin);
    int n, t;
    cin >> n >> t;
    vector<int> v, ans;
    for (int i = 1; i <= n; i++)
    {
        int m;
        cin >> m;
        v.clear();
        v.resize(m);
        for (int j = 0; j < m; j++) cin >> v[j];
        sort(v.begin(), v.end());
        if (t > v[0]) ans.push_back(i);
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++)
    {
        if (i) cout << ' ';
        cout << ans[i];
    }
    cout << endl;
    return 0;
}