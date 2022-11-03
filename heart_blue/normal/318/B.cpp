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
const int N = 1e3 + 10;



int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    string str;
    cin >> str;
    vector<int> v1, v2;
    int t = 0;
    while (1)
    {
        t = str.find("heavy",t);
        if (t == -1) break;
        v1.push_back(t);
        t++;
    }
    t = 0;
    while (1)
    {
        t = str.find("metal", t);
        if (t == -1) break;
        v2.push_back(t);
        t++;
    }
    int l, r;
    l = r = 0;
    LL ans = 0;
    while (l < v1.size() && r < v2.size())
    {
        if (v1[l] < v2[r])
        {
            ans += v2.size() - r;
            l++;
        }
        else
        {
            r++;
        }
    }
    cout << ans << endl;
    return 0;
}