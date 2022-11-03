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
const int N = 1e3 + 10;
vector<int> v;
int main()
{
    //freopen("input.txt","r",stdin);
    int n;
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; i++) cin >> v[i];
    sort(v.begin(), v.end());
    cout << 1 << ' ' << v[0] << endl;
    if (v[n - 1] == 0)
    {
        cout << 2 << ' ' << v[1] << ' ' << v[2] << endl;
        cout << n - 3;
        for (int i = 3; i < n; i++) cout << ' ' << v[i];
        cout << endl;
    }
    else
    {
        cout << 1 << ' ' << v[n - 1] << endl;
        cout << n - 2;
        for (int i = 1; i < n - 1; i++) cout << ' ' << v[i];
        cout << endl;
    }
    return 0;
}