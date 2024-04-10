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

int f[101][20007], g[101][20007];
char mat[101][20007], len[101];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    REP(i, n)
    {
        scanf("%s", mat[i]);
        len[i] = strlen(mat[i]);
        for (int j = m; j < 2 * m; ++j)
            mat[i][j] = mat[i][j - m];
    }
    REP(i, n)
    {
        int prev = -1;
        REP(j, 2 * m)
        {
            if (mat[i][j] == '1')
                prev = j;
            f[i][j] = prev;
            if (prev != -1)
                f[i][j] = j - prev;
        }

        prev = -1;
        for (int j = 2 * m - 1; j >= 0; --j)
        {
            if (mat[i][j] == '1')
                prev = j;
            g[i][j] = prev;
            if (prev != -1)
                g[i][j] = prev - j;
        }
    }

    int ans = -1;
    REP(pos, m)
    {
        bool good = true;
        int sum = 0;
        REP(i, n)
        {
            int cost = -1;
            if (g[i][pos] == -1)
                cost = f[i][pos + m];
            else if (f[i][pos + m] == -1)
                cost = g[i][pos];
            else cost = min(g[i][pos], f[i][pos + m]);

            if (cost == -1)
            {
                good = false;
                break;
            }

            sum += cost;
        }

        if (good)
            if (ans == -1 || sum < ans)
                ans = sum;
    }

    cout << ans << endl;
	return 0;
}