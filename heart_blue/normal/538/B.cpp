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
const int N = 1e6;
int a[N+10];
int pre[N + 10];
int main()
{
    //freopen("input.txt","r",stdin);
    //freopen("output.txt", "w", stdout);
    vector<int> v;
    v.push_back(1);
    for (int i = 0; i < v.size(); i++)
    {
        if (v[i] > N) break;
        v.push_back(v[i] * 10);
        v.push_back(v[i] * 10 + 1);
    }
    sort(v.begin(), v.end());
    while (v.back() > N) v.pop_back();
    int n;
    cin >> n;
    MEM(a, 0x1f);
    a[0] = 0;
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = v[i]; j <= n; j++)
        {
            if (a[j] > a[j - v[i]] + 1) a[j] = a[j - v[i]] + 1, pre[j] = j - v[i];
        }
    }
    cout << a[n] << endl;
    while (n)
    {
        cout << n - pre[n] << ' ';
        n = pre[n];
    }
    return 0;
}