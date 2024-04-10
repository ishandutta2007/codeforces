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
typedef long long ll;
typedef long double LD;
typedef unsigned long long ULL;

const ll MOD = 1000000007ll;

ll f[1007][1007];
char l[1007],r[1007];
int t,k;

void generate()
{
    CLEAR(f);
    for (int i = 0;i <= k;++i)
        f[0][i] = 1;
    for (int i = 1;i < 1007;++i)
        for (int j = 0;j <= k;++j)
            if (0 == j)
                f[i][j] = (f[i-1][0] * 8ll + f[i-1][k] * 2ll) % MOD;
            else
                f[i][j] = (f[i-1][j-1] * 8ll) % MOD;
}

ll eval(int p,int n,int next,char s[])
{
    ll ret = 0;
    if (p >= n) return 1;
    for (int i = 0;i <= s[p] - '0';++i)
    {
        int nextNext = 0;
        if (i == 4 || i == 7)
        {
            if (next > 0)
                continue;
            nextNext = k;
        }
        else
        {
            nextNext = next - 1;
            if (nextNext < 0) nextNext = 0;
        }

        if (s[p] - '0' ==  i)
            ret += eval(p+1,n,nextNext,s);
        else
            ret += f[n-p-1][nextNext];
        ret %= MOD;
    }
    return ret;
}

ll evalStupid(char s[])
{
    ll ret = 0;
    for (int i = 0;i < strlen(s);++i)
        ret = (ret * 10 + s[i] - '0') % MOD;
    return ret;
}

void dec(char s[])
{
    int len = strlen(s);
    for (int i = 0;i < len;++i)
        s[i] -= '0';
    --s[len-1];
    for (int i = len-1;i > 0;--i)
    {
        s[i] += 10;
        s[i-1] -= 1;
        s[i-1] += s[i]/10;
        s[i] %= 10;
    }
    for (int i = 0;i < len;++i)
        s[i] += '0';
}

int main()
{
    cin >> t >> k;
    generate();
    while (t--)
    {
        cin >> l >> r;
        dec(l);
        ll total = evalStupid(r) - evalStupid(l),bad = eval(0,strlen(r),0,r) - eval(0,strlen(l),0,l);
        ll good = (total - bad + MOD*2) % MOD;
      //  cout << total << " " << bad << endl;
        cout << good << endl;
    }
    return 0;
}