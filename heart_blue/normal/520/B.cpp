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
const LL INF = 1000000007;
const int N = 3e5;
int a[N];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    MEM(a, 0x1f);
    int n, m;
    cin >> n >> m;
    queue<int> q;
    a[n] = 0;
    q.push(n);
    int ans = INF;
    while(!q.empty())
    {
        int x = q.front();
        q.pop();
        if(x == 0) continue;
        if(x >= m)
        {
            ans = min(ans, a[x] + x - m);
            continue;
        }
        if(a[x*2] > a[x] + 1)
        {
            a[x*2] = a[x] + 1;
            q.push(x*2);
        }
        if(a[x-1] > a[x] + 1)
        {
            a[x-1] = a[x] + 1;
            q.push(x-1);
        }
    }
    cout << ans << endl;
    return 0;

}