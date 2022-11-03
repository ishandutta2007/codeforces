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
vector<pair<string,string>> vp;
void rotate(pair<string,string> &p)
{
    char c = p.first[0];
    p.first[0] = p.first[1];
    p.first[1] = p.second[1];
    p.second[1] = p.second[0];
    p.second[0] = c;
}
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        string s1, s2;
        cin >> s1 >> s2;
        vp.push_back({ s1, s2 });
        ans++;
        int flag = 0;
        for (int k = 0; k < 4; k++)
        {
            rotate(vp[i]);
            for (int j = 0; j < i; j++)
            {
                if (vp[j] == vp.back())
                {
                    flag = 1;
                    break;
                }
            }
            if (flag) break;
        }
        ans -= flag;
        if(i<n-1) cin >> s1;
    }
    cout << ans << endl;

    return 0;
}