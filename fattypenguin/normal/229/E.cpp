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

double c[1007][1007];
int n, m;
vector<VI> w;

double dp[1007][1007];

int main()
{
    for (int i = 0; i <= 1000; ++i)
    {
        c[i][0] = c[i][i] = 1;
        for (int j = 1; j < i; ++j)
            c[i][j] = c[i-1][j] + c[i-1][j-1];
    }

    cin >> n >> m;
    VI goods, must;
    w.resize(m);
    REP(i, m)
    {
        int k;
        cin >> k;
        w[i].resize(k);
        REP(j, k)
        {
            cin >> w[i][j];
            goods.PB(w[i][j]);
        }
    }
    SORT(goods);
    reverse(ALL(goods));
    int aim = goods[n-1];
  //  cout << "here i am!\n";
    must.resize(m);
    fill(ALL(must), 0);
    vector<bool> can;
    can.resize(m);
    fill(ALL(can), 0);
    int count = 0;
    REP(i, m) TR(it, w[i])
    {
        if (*it > aim)
        {
            ++must[i];
            --n;
        }
        if (*it == aim)
        {
            can[i] = true;
            ++count;
        }
    }

   // cout << "here";

    dp[0][0] = 1;
    REP(i, m) REP(j, count+1)
    {
        if (dp[i][j] < 1e-15) continue;
        dp[i+1][j] += dp[i][j] / c[w[i].size()][must[i]];
        if (can[i])
        {
            dp[i+1][j+1] += dp[i][j] / c[w[i].size()][must[i]+1];
        }
    }

    double ans = dp[m][n] / c[count][n];
    printf("%.10f\n", ans);
	return 0;
}