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
string num2str(int n)
{
    string str;
    if (n == 0) return "0";
    while (n)
    {
        str += n % 10 + '0';
        n /= 10;
    }
    reverse(str.begin(), str.end());
    return str;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    vector<string> vs = { "ABSINTH", "BEER", "BRANDY", "CHAMPAGNE", "GIN", "RUM", "SAKE", "TEQUILA", "VODKA", "WHISKEY", "WINE" };
    map<string, int> m;
    for (auto &it : vs) m[it] = 1;
    for (int i = 0; i <= 17; i++) m[num2str(i)] = 1;
    int n;
    string str;
    cin >> n;
    int cnt = 0;
    while (n--)
    {
        cin >> str;
        if (m.count(str)) cnt++;
    }
    cout << cnt << endl;
    return 0;
}