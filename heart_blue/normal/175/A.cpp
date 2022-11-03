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
int str2num(string str)
{
    int ret = 0;
    for (int i = 0; i < str.length(); i++)
    {
        ret *= 10;
        ret += str[i] - '0';
    }
    return ret;
}
bool check(string s1)
{
    if (s1.length() == 7) return s1 == "1000000";
    if (s1.length() > 6) return false;
    if (s1.length() > 1 && s1[0] == '0') return false;
    return true;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);

    string str;
    cin >> str;
    int ans = -1;
    for (int i = 0; i < str.length(); i++)
    {
        string s1 = str.substr(0, i+1);
        if (!check(s1)) break;
        for (int j = i + 1; j < str.length()-1; j++)
        {
            string s2 = str.substr(i + 1, j - i);
            if (!check(s2)) break;
            string s3 = str.substr(j + 1);
            if (!check(s3)) continue;
            ans = max(str2num(s1) + str2num(s2) + str2num(s3), ans);
        }
    }
    cout << ans << endl;
    return 0;
}