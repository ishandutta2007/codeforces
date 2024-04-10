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
const LL INF = 1e9+7;
const int N = 2e5+10;
const int M = 1e4;
int a[N];
int main()
{
    //freopen("input.txt", "r", stdin);
    int maxv;
    int minv;
    minv = INF;
    maxv = -INF;
    LL cnt1 = 0;
    LL cnt2 = 0;
    int x;
    int n;
    cin >> n;
    //cout << LL(1e5)*LL(1e5) << endl;
    for(int i = 0; i < n; i++) cin >> a[i], minv = min(minv,a[i]), maxv = max(maxv,a[i]);
    for(int i = 0; i < n; i++) if(minv == a[i]) cnt1++;
    for(int i = 0; i < n; i++) if(maxv == a[i]) cnt2++;
    cout << maxv -minv << ' ';
    if(maxv == minv)
    {
        cout << cnt1 *(cnt1-1)/2 << endl;
    }
    else
    {
        cout << cnt1 * cnt2 << endl;
    }
    return 0;
}