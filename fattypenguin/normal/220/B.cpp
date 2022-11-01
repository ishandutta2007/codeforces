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

int n, q;
int a[120007];
pair<PII, int> b[120007];
MII has;

bool cmp(const pair<PII, int> &a, const pair<PII, int> &b)
{
    return a.first.second < b.first.second;
}

int BIT[120007];
VI vec[120007];

int ans[120007];

void insert(int x, int val)
{
    ++x;
    while (x <= n+2)
    {
        BIT[x] += val;
        x += x & -x;
    }
}

int sum(int x)
{
    ++x;
    int ret = 0;
    while (x)
    {
        ret += BIT[x];
        x -= x & -x;
    }

    return ret;
}

int main()
{
    cin >> n >> q;
    REP(i, n) scanf("%d", &a[i]);
    REP(i, n) has[a[i]] = 1;
    int cur = 0;
    TR(it, has) it->second = cur++;
    REP(i, q) scanf("%d%d", &b[i].first.first, &b[i].first.second);
    REP(i, q) b[i].second = i;
    sort(b, b+q, cmp);
    int pos = 0;
    REP(i, n)
    {
        int idx = has[a[i]];
        if (vec[idx].size() >= a[i]+1)
            insert(vec[idx][vec[idx].size()-a[i]-1], 1);
        if (vec[idx].size() >= a[i])
            insert(vec[idx][vec[idx].size()-a[i]], -1);
        vec[idx].PB(i);
        if (vec[idx].size() >= a[i])
            insert(vec[idx][vec[idx].size()-a[i]], 1);
        if (vec[idx].size() >= a[i]+1)
            insert(vec[idx][vec[idx].size()-a[i]-1], -1);

        while (pos < q && b[pos].first.second == i+1)
        {
            ans[b[pos].second] = sum(b[pos].first.second-1) - sum(b[pos].first.first-2);
            ++pos;
        }
    }
    REP(i, q) cout << ans[i] << endl;
	return 0;
}