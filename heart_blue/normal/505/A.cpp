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
const LL INF = 1e17;
const int N = 2e3 + 10;
int a[N];
bool check(string str)
{
    string ret = str;
    reverse(ret.begin(), ret.end());
    return ret == str;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    string str;
    cin >> str;
    int flag = 0;
    string ans;
    for (int i = 0; i <= str.length(); i++)
    {
        if (flag) break;
        for (char c = 'a'; c <= 'z'; c++)
        {
            ans = str.substr(0, i) + c + str.substr(i);
            if (check(ans)) flag = 1;
            if (flag) break;
        }
    }
    if (flag) cout << ans << endl;
    else cout << "NA" << endl;
    return 0;
}