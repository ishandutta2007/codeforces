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
const int N = 1e6+10;
const int M = 1e4;
LL a[N];
int x[N];
int b[N];
int c[N];
int lowbit(int x) {return x&-x;}
LL sum(int x)
{
    LL ret = 0;

    while(x)
    {
        ret += a[x];
        x -= lowbit(x);
    }
    return ret;
}

void add(int x, int y)
{
    if(x == 0) return;
    while(x < N)
    {
        a[x] += y;
        x += lowbit(x);
    }
}
int READ()
{
    int n = 0;
    char ch = getchar();
    while(ch < '0' || ch > '9') ch = getchar();
    while(1)
    {
        n = (n<<1) + (n<<3) + ch-'0';
        ch = getchar();
        if(ch <'0' || ch >'9') break;
    }
    return n;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    int n;
    cin >> n;
    map<int,int> m;
    for(int i = 0; i < n; i++) cin >> x[i], m[x[i]] = 1;
    int k = 1;
    for(map<int,int>::iterator it = m.begin(); it != m.end(); it++) it->second = k++;
    for(int i = 0; i < n; i++) x[i] = m[x[i]];
    MEM(a,0);
    MEM(b,0);
    MEM(c,0);
    for(int i = n-1; i >= 0; i--)
    {
        b[x[i]]++;
        add(b[x[i]], 1);
    }
    map<int,int> m1;
    LL ans = 0;
    for(int i = 0; i < n; i++)
    {
        c[x[i]]++;
        add(b[x[i]],-1);
        b[x[i]]--;
        ans += sum(c[x[i]]-1);
    }
    cout << ans << endl;
    
    return 0;
}