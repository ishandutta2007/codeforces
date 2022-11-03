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
const int INF = 1e9 + 3;
const int N = 4e5 + 10;
int a[N];
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    vector<string> vs = { "", "", "2", "3", "322", "5", "53", "7", "7222", "7233" };
    int n;
    cin >> n;
    string str;
    cin >> str;
    string ans;
    for (int i = 0; i < str.length(); i++)
    {
        ans += vs[str[i] - '0'];
    }
    sort(ans.rbegin(), ans.rend());
    cout << ans << endl;
    return 0;
}