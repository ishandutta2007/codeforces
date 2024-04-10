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
const int N = 1e3 + 10;
int a[5];
int main()
{
    //freopen("input.txt","r",stdin);
    int n;
    MEM(a, -1);
    cin >> n;
    if (n == 1)
    {
        int x;
        cin >> x;
        cout << n << endl;
        cout << x << endl;
        return 0;
    }
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        if (x == 0) a[0] = 0;
        else if (x == 100) a[1] = 100;
        else if (x % 10 == 0) a[2] = x;
        if (x > 0 && x < 10) a[3] = x;
        if (x >= 10 && x % 10) a[4] = x;
    }
    vector<int> ans;
    if (a[0] >= 0) ans.push_back(0);
    if (a[1] == 100) ans.push_back(100);
    if (a[2] == -1 && a[3] == -1)
    {
        if (a[4] >= 0) ans.push_back(a[4]);
    }
    else
    {
        if (a[2] >= 0) ans.push_back(a[2]);
        if (a[3] >= 0) ans.push_back(a[3]);
    }
    cout << ans.size() << endl;
    for (int i = 0; i < ans.size(); i++) cout << ans[i] << ' ';

    return 0;
}