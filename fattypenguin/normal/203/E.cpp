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

int deg = 0, total = 0;
vector<PII> data;
int n, d, s;

PII go(int s)
{
    int x, y;

    int ret = 0;
    int now = 0;
    TR(it, data)
    {
        if (it->first + now <= s)
        {
            now += it->first;
            ++ret;
        } else break;
    }
    x = ret; y = -now;

    int buy = 0;
    while (buy < data.size() && data[buy].second == 0) ++buy;
    if (buy == data.size() || data[buy].first > s) return MP(x, y);

    PII ans = MP(x, y);

    now = data[buy].first;
    ans = max(ans, MP(min(n, deg+1), -now));
    int afford = 0;
    REP(i, data.size()) if (i != buy)
    {
        if (now + data[i].first <= s)
            ++afford;
        else break;
        now += data[i].first;
        ans = max(ans, MP(min(n, deg+1+afford), -now));
    }

    return ans;
}

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> d >> s;

    REP(i, n)
    {
        int c, f, l;
        cin >> c >> f >> l;
        deg += c;
        deg = min(deg, n);
        if (l < d)
        {
            ++total;
        } else data.PB(MP(f, c));
    }
    SORT(data);
    PII out = go(s);
    cout << out.first << " " << -out.second << endl;
	return 0;
}