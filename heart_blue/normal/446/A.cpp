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
const int N = 1e5 + 10;
int a[N];
int cnt[N];
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    cnt[n - 1] = 1;
    int ans = 1;
    for (int i = n - 2; i >= 0; i--)
    {
        if (a[i] < a[i + 1]) cnt[i] = cnt[i + 1] + 1;
        else cnt[i] = 1;
        ans = max(ans, cnt[i]+1);
    }
    ans = min(ans, n);
    if (n > 1)
    {
        ans = max(ans, max(cnt[0], cnt[1] + 1));
    }
    int c = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, c + 1);
        if (i > 0 && i < n-1 && a[i - 1] < a[i + 1] - 1) ans = max(ans, c + 1 + cnt[i + 1]);
        if (a[i] > a[i - 1]) c++;
        else c = 1;
        
    }
    cout << ans << endl;

    return 0;
}