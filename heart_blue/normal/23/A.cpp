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
const int N = 3e3;
int d[N][N];
int n;
int ans = INF;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
    string str;
    cin >> str;
    int n = str.length();
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (str[i] != str[j]) continue;
            int l = i;
            int r = j;
            int cnt = 0;
            while (l < n && r < n&& str[l++] == str[r++]) cnt++;
            ans = max(ans, cnt);
        }
    }
    cout << ans << endl;
    return 0;
}