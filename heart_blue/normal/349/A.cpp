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

const int INF = 1e5 + 7;
const int N = 1e3 + 10;


int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    int n;
    int a, b;
    a = b = 0;
    cin >> n;
    string ans = "YES";
    while (n--)
    {
        int x;
        cin >> x;
        if (x == 25) a++;
        if (x == 50)
        {
            if (a == 0)
            {
                ans = "NO";
                break;
            }
            else a--, b++;
        }
        if (x == 100)
        {
            if (b == 0)
            {
                if (a < 3)
                {
                    ans = "NO";
                    break;
                }
                else a -= 3;
            }
            else
            {
                if (a == 0)
                {
                    ans = "NO";
                    break;
                }
                else a--, b--;
            }
        }
    }
    cout << ans << endl;
    return 0;
}