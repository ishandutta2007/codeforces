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
typedef long long LL;
typedef unsigned int UI;
typedef long double LD;
typedef unsigned long long ULL;

LL mulmod( LL a, LL b, LL c){
	a %= c; b %= c;
	if(a < 0) a += c;
	if(b < 0) b += c;
	LL ret = 0;
	while(b){
		if(b & 0x1) if((ret+=a)>=c) ret -= c;
		if((a<<=1)>=c)a-=c;
		b>>=1;
	}
	return ret;
}

int powmod( LL a, int b, int c){
    LL ret = 1 ;
    while(b){
         if(b & 0x1) ret = ret * a % c;
         a = a * a % c;
         b >>= 1;
    }
    return ret;
}

LL tmp[2][2];

void matMul(LL a[2][2], LL b[2][2], LL MOD)
{
    REP(i, 2) REP(j, 2) tmp[i][j] = 0;
    REP(k, 2) REP(i, 2) REP(j, 2)
    {
        tmp[i][j] += mulmod(a[i][k], b[k][j], MOD);
        if (tmp[i][j] >= MOD) tmp[i][j] -= MOD;
    }
    REP(i, 2) REP(j, 2) a[i][j] = tmp[i][j];
}

LL fibMod(LL x, LL MOD)
{
    LL res[2][2], step[2][2] = { {0, 1}, {1, 1} };
    REP(i, 2) REP(j, 2) res[i][j] = (i == j);
    for (; x; x >>= 1ll)
    {
        if (x & 1ll) matMul(res, step, MOD);
        matMul(step, step, MOD);
    }
    return res[1][0];
}

const LL low = 100000ll,
         high = 10000000000000ll;

const LL BIG = 100000000ll;

LL getRep(LL nxt, LL rep)
{
    for (LL k = rep; ; k += rep)
        if (fibMod(k+BIG, nxt) == fibMod(k*2+BIG, nxt))
            if (fibMod(k+BIG+1, nxt) == fibMod(k*2+BIG+1, nxt))
                return k;

}

LL need;

void expend(LL cnt, LL &rep, vector<LL> &pos)
{
    LL nextRep = getRep(cnt * 10l, rep);
    vector<LL> nextPos;

    LL times = nextRep / rep;

    LL aim = need % (cnt * 10);

    TR(it, pos)
    {
        LL cur = *it;
        REP(k, times)
        {
            if (fibMod(cur, cnt*10) == aim)
                nextPos.PB(cur);
            cur += rep;
        }
    }

    pos = nextPos;
    rep = nextRep;
}

int main()
{
    cin >> need;
    LL rep, cnt = low;

    map<pair<int, int>, int> hash;

    int prev = 0, now = 1, tmp = need % cnt;
    vector<LL> pos;

    if (tmp == 0) pos.PB(0);
    if (tmp == 1) pos.PB(1);

    for (int i = 2; ; ++i)
    {
        if (hash.find(MP(prev, now)) != hash.end())
        {
            rep = i - hash[MP(prev, now)];
            break;
        }
        hash[MP(prev, now)] = i;
        prev = prev + now;
        if (prev >= cnt) prev -= cnt;
        swap(prev, now);
        if (now == tmp) pos.PB(i);
    }

    for (; cnt < high; cnt *= 10ll)
        expend(cnt, rep, pos);

    LL ans = -1;
    TR(it, pos) if (-1 == ans || *it < ans) ans = *it;
    cout << ans << endl;
	return 0;
}