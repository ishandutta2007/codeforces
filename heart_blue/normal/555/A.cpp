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
const LL N = 1e5+10;
const double eps = 1e-12;
unsigned long long seed;
vector<int> v[N];
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n, k;
    cin >> n >> k;
    int flag = -1;
    int ans = 0;
    for (int i = 0; i < k; i++)
    {
        int m;
        cin >> m;
        v[i].resize(m);
        ans += m - 1;
        for (int j = 0; j < m; j++)
        {
            cin >> v[i][j];
            if (v[i][j] == 1) flag = i;
        }
    }
    int key = v[flag].size();
    for (int i = 1; i < v[flag].size(); i++)
    {
        if (v[flag][i] - v[flag][i - 1] != 1)
        {
            key = i;
            break;
        }
    }
    ans += (n - key) - (key - 1);
    cout << ans << endl;
    return 0;
}