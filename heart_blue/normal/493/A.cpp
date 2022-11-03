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

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    vector<string> vs;
    string str;
    cin >> str;
    vs.push_back(str);
    cin >> str;
    vs.push_back(str);
    int c[128];
    c['h'] = 0;
    c['a'] = 1;
    c['y'] = 1;
    c['r'] = 2;
    int a[2][200];
    MEM(a, 0);
    int n;
    cin >> n;
    while (n--)
    {
        int mint, num;
        char ch, clr;
        cin >> mint >> ch >> num >> clr;
        int& t = a[c[ch]][num];
        int color = c[clr];
        if (t >= 2) continue;
        t += color;
        if (t >= 2)
        {
            cout << vs[c[ch]] << ' ' << num << ' ' << mint << endl;
        }
    }
        return 0;
}