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
const int N = 1e5;
LL  a[N + 10];
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    LL sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
    }
    LL avg = sum / n;
    int l, r;
    l = 0;
    r = 0;
    LL ans = 0;
    while (l < n && r < n)
    {
        if (a[l] >= avg)
        {
            l++;
            continue;
        }
        if (a[r] <= avg)
        {
            r++;
            continue;
        }
        LL tmp = min(a[r] - avg, avg - a[l]);
        ans += tmp*abs(l - r);
        a[r] -= tmp;
        a[l] += tmp;
    }
    cout << ans << endl;
    
    
    return 0;
}