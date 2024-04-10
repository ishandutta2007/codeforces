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
#include <ext/hash_map>
#include <set>
#include <assert.h>
#define REP(i,n) for(int i=0;i<n;i++)
#define TR(i,x) for(typeof(x.begin()) i=x.begin();i!=x.end();i++)
#define ALL(x) x.begin(),x.end()
#define SORT(x) sort(ALL(x))
#define CLEAR(x) memset(x,0,sizeof(x))
#define FILL(x,c) memset(x,c,sizeof(x))

using namespace std;
using namespace __gnu_cxx;

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

const int MOD = 1000000007;

int n;
string s;
char buff[555555];

hash_map<int, int> idx;

int getHashCode(const string &s)
{
    int ret = 0;
    REP(i, s.size()) ret = (ret * 137ll + s[i])%MOD;
    return ret;
}

int dp[32769][125];
int stand[66666];
int small[66666][16];
int next[16][500001];
int seq[500001];
int orig[55];

int main()
{
    ios::sync_with_stdio(false);

    cin >> n;
    REP(i, n) stand[1<<i] = i;
    REP(i, (1<<n)) REP(j, n)
    {
        small[i][j] = 0;
        for (int k = j+1; k < n; ++k)
            if (i&(1<<k))
                ++small[i][j];
    }

    REP(i, n)
    {
        cin >> s;
        idx[getHashCode(s)] = i;
        orig[i] = getHashCode(s);
    }

    int bestx = -1, besty;

    int m;
    cin >> m;
    REP(x, m)
    {
        int k;
        cin >> k;
        REP(i, k)
        {
            cin >> s;
            seq[i] = getHashCode(s);
        }

        REP(i, n)
        {
            next[i][k] = -1;
            for (int j = k-1; j >= 0; --j)
            {
                if (seq[j] == orig[i])
                    next[i][j] = j;
                else next[i][j] = next[i][j+1];
            }
        }

        bool cant = false;
        REP(i, n) if (next[i][0] == -1)
        {
            cant = true;
            break;
        }

        if (cant) continue;
        int up = n * (n-1) / 2;
        REP(i, (1<<n)) REP(j, up+1) dp[i][j] = -1;

        int ans = -1;

        REP(i, (1<<n)) REP(j, up+1)
        {
            if (dp[i][j] == -1 && !(!i && !j)) continue;
            if (i+1 == (1<<n))
            {
                if (ans == -1 || j < ans)
                    ans = j;
            }
            int left = (1<<n)-1-i;
            for (; left; left -= left & -left)
            {
                int now = stand[left & -left];
                int nextpos = next[now][dp[i][j]+1];
                if (-1 == nextpos) continue;
                int nextinv = j + small[i][now];
                if (dp[i+(1<<now)][nextinv] == -1)
                    dp[i+(1<<now)][nextinv] = 0x7f7f7f7f;
                dp[i+(1<<now)][nextinv] = min(dp[i+(1<<now)][nextinv], nextpos);
            }
        }
        if (-1 == ans) continue;
        if (bestx == -1 || bestx > ans)
        {
            bestx = ans;
            besty = x;
        }

  //      cout << ans << endl;
    }

    if (bestx == -1)
        cout << "Brand new problem!\n";
    else
    {
        cout << besty+1 << endl;
        int nn = n * (n-1) / 2 - bestx + 1;
        cout << "[:";
        REP(i, nn) cout << "|";
        cout << ":]\n";
    }
    return 0;
}