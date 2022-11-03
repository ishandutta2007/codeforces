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
const LL INF = 1e9 + 7;
const int N = 5e3 + 10;
int a[27];
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
    int k;
    string str;
    cin >> k >> str;
    map<char, int> m;
    for (auto &c : str) m[c] = 1;
    if (m.size() < k)
    {
        cout << "NO" << endl;
        return 0;
    }
    cout << "YES" << endl;

    int cnt = 0;
    int t = 0;
    m.clear();
    for (int i = 0; i < str.length(); i++)
    {
        if (!m.count(str[i])) a[t++] = i, m[str[i]] = 1;
        if (t == k) break;
    }
    a[t] = str.length();
    for (int i = 0; i < k; i++)
    {
        cout << str.substr(a[i], a[i + 1] - a[i]) << endl;
    }
    return 0;
}