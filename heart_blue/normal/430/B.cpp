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

const LL INF = 1e7 + 7;
const int N = 1e3 + 10;

int a[N];

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, k, x;
    cin >> n >> k >> x;
    int ans = 0;
    int t = x;
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < n; i++)
    {
        if (a[i] != t) continue;
        x = t;
        int l, r;
        l = i;
        r = i + 1;
        int sum = 0;
        int tmp = 1;
        while (l >= 0 || r < n)
        {
            int pl = l, pr = r;
            while (l >= 0 && a[l] == x) tmp++,l--;
            while (r < n && a[r] == x) tmp++,r++;
            if (tmp >= 3) sum += tmp;
            else
            {
                l = pl, r = pr;
                if (r >= n) break;
                if (a[r] == x) break;
                x = a[r];
                tmp = 0;
                continue;
            }
            tmp = 0;
            if (r < n) x = a[r];
            if (l >= 0) x = a[l];
            
        }
        ans = max(ans, sum-1);
    }
    cout << ans << endl;
    return 0;
}