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
vector<int> a, b;
int main()
{
    //freopen("input.txt", "r", stdin);

    int n;
    cin >> n;

    a.resize(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    b = a;
    sort(a.begin(), a.end());
    int l;
    int r;
    for (l = 0; l < n; l++) if (a[l] != b[l]) break;
    for (r = n - 1; r >= 0; r--) if (a[r] != b[r]) break;
    int flag = 0;
    if (l >= r) l = r = 0;
    for (int i = 0;; i++)
    {
        if (l + i >= r - i) break;
        swap(b[r - i], b[l + i]);
    }
    for (int i = 0; i < n; i++) if (a[i] != b[i]){ flag = 1; break; }
    if (flag) cout << "no" << endl;
    else
    {
        cout << "yes" << endl;
        cout << l + 1 << ' ' << r + 1 << endl;
    }
    
    return 0;
}