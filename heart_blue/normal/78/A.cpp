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
const int N = 2e5 + 1;
map<char, int> m;
int check(string s)
{
    int ret = 0;
    for (auto &c : s) ret += m[c];
    return ret;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    string vo = "aeiou";
    for (int i = 0; i < vo.length(); i++) m[vo[i]] = 1;
    string s1, s2, s3;
    getline(cin, s1);
    getline(cin, s2);
    getline(cin, s3);
    int a = check(s1);
    int b = check(s2);
    int c = check(s3);
    if (a == 5 && b == 7 && c == 5)
    {
        cout << "YES" << endl;
    }
    else
        cout << "NO" << endl;
    return 0;
}