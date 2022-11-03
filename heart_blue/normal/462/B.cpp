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

const LL INF = 1e7 + 7;
const int N = 1e2 + 10;
char c[N][N];
int dx[] = { 0, 0, 1, -1 };
int dy[] = { 1, -1, 0, 0 };

priority_queue<int> pq;
int main()
{
    //freopen("input.txt", "r", stdin);
    //freopen("output.txt", "w", stdout);
    
    LL n, k;
    cin >> n >> k;
    string str;
    cin >> str;
    LL a[26] = { 0 };
    for (int i = 0; i < str.length(); i++)
    {
        a[str[i] - 'A']++;
    }
    for (int i = 0; i < 26; i++) if (a[i]) pq.push(a[i]);
    LL sum = 0;
    if (k >= n) k = n;
    while (k)
    {
        LL t = pq.top();
        sum += min(k, t)*min(k, t);
        k -= min(k, t);
        pq.pop();
    }
    cout << sum << endl;
    return 0;
}