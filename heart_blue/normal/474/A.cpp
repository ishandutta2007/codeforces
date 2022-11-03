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
const int N = 1e5 + 10;
vector<string> vs;
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    vs.push_back("qwertyuiop");
    vs.push_back("asdfghjkl;");
    vs.push_back("zxcvbnm,./");
    char c;
    string str;
    cin >> c >> str;
    int t = 0;
    if (c == 'R') t = -1;
    else t = 1;
    for (int i = 0; i < str.length(); i++)
    {
        for (int k = 0; k < 3; k++)
        {
            for (int j = 0; j < vs[k].length(); j++)
            {
                if (vs[k][j] != str[i]) continue;
                int x = j + t;
                if (x < 0) x = 0;
                if (x == vs[k].length()) x--;
                cout << vs[k][x];
            }
        }
    }
    return 0;
}