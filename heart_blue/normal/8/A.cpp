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
const int N = 2e3 + 1;

int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    string str, s1, s2;
    cin >> str >> s1 >> s2;
    int k = -1;
    int flag = 0;
    if ((k = str.find(s1, k + 1)) != -1 && str.find(s2, k + s1.length()) != -1) flag |= 1;
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    k = -1;
    if ((k = str.find(s2, k + 1)) != -1 && str.find(s1, k + s2.length()) != -1) flag |= 2;

    vector<string> vs = { "fantasy", "forward", "backward", "both" };
    cout << vs[flag] << endl;

    return 0;
}