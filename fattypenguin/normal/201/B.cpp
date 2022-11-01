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

long long mat[3000][3000];
int n, m;

long long col[3000], row[3000];
long long costx[3000], costy[3000];

int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> m;
    CLEAR(col);
    CLEAR(row);
    REP(i, n) REP(j, m)
    {
        cin >> mat[i][j];
        col[j] += mat[i][j];
        row[i] += mat[i][j];
    }

    REP(i, m+1)
    {
        costx[i] = 0;
        REP(j, m)
        {
            long long d = abs(i*4-(j*4+2));
            costx[i] += d * d * col[j];
        }
   //     cout << costx[i] << " ";
    }
   // cout << endl;

    REP(i, n+1)
    {
        costy[i] = 0;
        REP(j, n)
        {
            long long d = abs(i*4-(j*4+2));
            costy[i] += d * d * row[j];
        }
    }

    long long best = 0x7f7f7f7f7f7f7f7fll;
    PII ans = MP(0x7f7f7f7f, 0x7f7f7f7f);
    REP(i, n+1) REP(j, m+1)
    {
        long long cost = costx[j] + costy[i];
        if (cost < best)
        {
            best = cost;
            ans = MP(0x7f7f7f7f, 0x7f7f7f7f);
        }
        if (cost == best)
            ans = min(ans, MP(i, j));
    }
    cout << best << endl << ans.first << " " << ans.second << endl;
	return 0;
}