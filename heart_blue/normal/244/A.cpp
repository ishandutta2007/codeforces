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
const int N = 3e3 + 10;
int a[N];
int b[31];
int main()
{
    //freopen("input.txt","r",stdin);
    int n, k;
    cin >> n >> k; 
    for (int i = 1; i <= k; i++)
    {
        int x;
        cin >> x;
        a[x] = 1;
        b[i] = x;
    }
    int t = 1;
    int l, r;
    l = 1;
    r = 0;
    while (l <= k && r <= k*n)
    {
        int t = n - 1;
        cout << b[l];
        while (t)
        {
            r++;
            if (a[r]) continue;
            cout << ' ' << r;
            t--;
            if (t == 0) break;
        }
        l++;
        cout << endl;
    }
    return 0;
}