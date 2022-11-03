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
const LL INF = 1e9 + 1;
const int N = 1e3 + 10;
vector<int> v;
int main()
{
    //freopen("input.txt","r",stdin);
    string str;
    int n;
    cin >> n;
    cin >> str;
    if (str[0] != '.') v.push_back(0);
    for (int i = 1; i < str.length(); i++)
    {
        if (str[i] != str[i - 1]) v.push_back(i);
    }
    if (str[str.length() - 1] != '.') v.push_back(str.length() - 1);
    if (v.size() == 2)
    {
        if (str[v[0]] == 'L') cout << v[1] << ' ' << v[0];
        else cout << v[0] + 1 << ' ' << v[1] + 1 << endl;
    }
    else
    {
        cout << v[0] + 1 << ' ' << v[v.size() - 2] << endl;
    }

    return 0;
}