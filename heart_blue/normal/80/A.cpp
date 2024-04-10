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

const int INF = 1e9 + 7;
const int N = 2e5 + 1;
int a[N];
void init()
{
    MEM(a, 0);
    a[0] = a[1] = 1;
    for (int i = 2; i < N; i++)
    {
        if (a[i]) continue;
        for (int j = i+i; j < N; j += i) a[j] = 1;
    }
}

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    init();
    int n, m;
    cin >> n >> m;
    for (int i = n + 1; i < N; i++)
    {
        if (a[i]) continue;
        if (i == m) cout << "YES" << endl;
        else cout << "NO" << endl;
        return 0;
    }
    return 0;
}