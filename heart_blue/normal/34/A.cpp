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
const int N = 2e6;

int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
    int n;
    cin >> n;
    vector<int> v(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    int minv = INF;
    pair<int, int> p;
    for (int i = 0; i < n; i++)
    {
        if (abs(v[(i+1)%n] - v[i]) < minv) minv = abs(v[(i+1)%n] - v[i]), p = { i + 1, (i+1)%n + 1 };
    }
    cout << p.first << ' ' << p.second << endl;
    return 0;
}