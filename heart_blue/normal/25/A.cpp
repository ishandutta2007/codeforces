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
const int N = 3e3;
int a[N];
void init()
{
    MEM(a, 0);
    a[1] = a[0] = 0;
    for (int i = 2; i < N; i++)
    {
        if (a[i]) continue;
        for (int j = i; j < N; j += i) a[j] ++;
    }

}
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
    int cnt = 0;
    int n;
    int x;
    int l1, l2;
    l1 = l2 = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        cnt += x & 1;
        if (x & 1) l1 = i;
        else l2 = i;
    }
    if (cnt == 1) cout << l1+1 << endl;
    else cout << l2+1 << endl;
    return 0;
}