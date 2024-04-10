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
const int N = 2e3 + 10;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
    vector<string> vs;
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        if (str == "pwd")
        {
            cout << "/";
            if (!vs.empty())    for (auto &x : vs) cout << x << '/';
            cout << endl;

        }
        else
        {
            cin >> str;
            if (str[0] == '/') vs.clear();
            for (auto &c : str) if (c == '/') c = ' ';
            stringstream sin(str);
            while (sin >> str)
            {
                if (str == ".." && !vs.empty()) vs.pop_back();
                if (str != "..")
                {
                    vs.push_back(str);
                }
            }
        }
    }
    return 0;
}