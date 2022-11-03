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

const int INF = 1e5 + 7;
const int N = 1e3 + 10;


int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    vector<int> v;
    int n;
    cin >> n;
    while (n--)
    {
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                char c;
                cin >> c;
                if (c == 'K')
                {
                    v.push_back(i);
                    v.push_back(j);
                }
            }
        }
        if ((v[0] == v[2] || abs(v[0] - v[2]) == 4) && (abs(v[1] - v[3]) == 4 || v[1] == v[3]))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
        v.clear();
    }
    return 0;
}