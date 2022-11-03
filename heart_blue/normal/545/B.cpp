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
    string s1, s2;
    cin >> s1 >> s2;
    int n = s1.length();
    int sum = 0;
    for (int i = 0; i < n; i++) if (s1[i] != s2[i]) sum++;
    if (sum & 1)
    {
        cout << "impossible" << endl;
        return 0;
    }
    int flag = 0;
    for (int i = 0; i < n; i++)
    {
        if (s1[i] != s2[i])
        {
            if (flag) cout << s1[i];
            else cout << s2[i];
            flag ^= 1;
        }
        else cout << s1[i];
    }
    return 0;
}