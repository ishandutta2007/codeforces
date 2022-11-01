#include <functional>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <cctype>
#include <vector>
#include <string>
#include <bitset>
#include <cmath>
#include <queue>
#include <stdio.h>
#include <stack>
#include <ctime>
#include <list>
#include <map>
#include <set>
#include <assert.h>
#define REP(i,n) for(int i=0;i<n;i++)
#define TR(i,x) for(typeof(x.begin()) i=x.begin();i!=x.end();i++)
#define ALL(x) x.begin(),x.end()
#define SORT(x) sort(ALL(x))
#define CLEAR(x) memset(x,0,sizeof(x))
#define FILL(x,c) memset(x,c,sizeof(x))

using namespace std;

const double eps = 1e-8;

#define PB push_back
#define MP make_pair

typedef map<int,int> MII;
typedef map<string,int> MSI;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<long double> VD;
typedef pair<int,int> PII;
typedef long long int64;
typedef long long ll;
typedef unsigned int UI;
typedef long double LD;
typedef unsigned long long ULL;

const int MAXN = 5007;

int n, a[MAXN];
int f[MAXN], height[MAXN], sum[MAXN];

PII q[MAXN * 2];

int main()
{
    scanf("%d", &n);
    REP(i, n) scanf("%d", &a[i]);
    REP(i, n) sum[i+1] = sum[i] + a[i];

    int front = MAXN, rear = MAXN;

    f[0] = 0;
    height[0] = 0;
    q[rear++] = MP(0, 0);
    int last = -1;
    for (int i = 1; i <= n; ++i)
    {
        while (front < rear && q[front].first <= sum[i])
        {
            last = q[front++].second;
        }

        f[i] = f[last] + 1;
        height[i] = sum[i] - sum[last];

        while (front < rear && height[i] + sum[i] <= q[rear-1].first)
            --rear;
        q[rear++] = MP(height[i] + sum[i], i);
    }

    cout << n - f[n] << endl;
	return 0;
}