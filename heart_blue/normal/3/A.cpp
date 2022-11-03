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
const int N = 2e3 + 1;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    string s1, s2;
    cin >> s1 >> s2;
    cout << max(abs(s1[0] - s2[0]), abs(s1[1] - s2[1])) << endl;
    while (s1 != s2)
    {
        if (s1[0] > s2[0]) cout << 'L', s1[0]--;
        if (s1[0] < s2[0]) cout << 'R', s1[0]++;
        if (s1[1] > s2[1]) cout << 'D', s1[1]--;
        if (s1[1] < s2[1]) cout << 'U', s1[1]++;
        cout << endl;
    }
    return 0;
}