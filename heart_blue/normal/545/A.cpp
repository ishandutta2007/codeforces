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
const int N = 2e5 + 10;
const double eps = 1e-6;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    int sum = 0;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int flag = 1;
        for (int j = 0; j < n; j++)
        {
            int x;
            cin >> x;
            if (x == 1 || x == 3) flag = 0;
        }
        sum += flag;
        if (flag) v.push_back(i + 1);
    }
    cout << sum << endl;
    for (auto x : v) cout << x << ' ';
    return 0;
}