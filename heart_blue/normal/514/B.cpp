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
const int N = 1e8;

int gcd(int n, int m)
{
    return m == 0 ? n : gcd(m, n%m);
}
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    map<pair<int,int>, int> mp;
    int n, x, y;
    cin >> n >> x >> y;
    while(n--)
    {
        int a, b;
        cin >> a >> b;
        a -= x;
        b -= y;
        if(a == 0 || b == 0) a = abs(a), b = abs(b);
        if(a < 0) a = -a, b = -b;
        int g = abs(gcd(a, b));
        a /= g;
        b /= g;
        mp[{a, b}] = 1;
    }
    cout << mp.size() << endl;
    return 0;

}