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

const int INF = 1e6 + 3;
const int N = 1e3 + 1;
ULL change(string str)
{
    ULL ret = 0;
    for (auto c : str) ret *= 10, ret += c - '0';
    return ret;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    string str;
    cin >> str;
    if (str.length() > 19)
    {
        cout << "BigInteger" << endl;
        return 0;
    }
    ULL n = change(str);
    if (n > (ULL)9223372036854775807) cout << "BigInteger" << endl;
    else if (n > (ULL)2147483647) cout << "long" << endl;
    else if (n > (ULL)32767) cout << "int" << endl;
    else if (n > (ULL)127) cout << "short" << endl;
    else cout << "byte" << endl;
    return 0;
}