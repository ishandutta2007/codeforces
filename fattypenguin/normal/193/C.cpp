#include <functional> //aa
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

const double eps = 1e-14;

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

const int MAXN = 10;

int coff[7][6] =
{
    {1, 1, 1, 0, 0, 0},
    {1, 0, 0, 1, 1, 0},
    {0, 1, 0, 1, 0, 1},
    {0, 0, 1, 0, 1, 1},
    {0, 1, 1, 1, 1, 0},
    {1, 0, 1, 1, 0, 1},
    {1, 1, 0, 0, 1, 1}
};

double mat[MAXN][MAXN];

int solveLinearEquations(double a[MAXN][MAXN], int n, int k, int m = 1)
{
    int y, i;
    for (i = y = 0; i < k && y < n; ++i, ++y)
    {
        int u = i;
        for (int j = i; j < n; ++j)
            if (fabs(a[j][y]) > fabs(a[u][y]))
                u = j;

        if (fabs(a[u][y]) < eps)
        {
            --i;
            continue;
        }

        for (int j = i; j < n+m; ++j)
            swap(a[i][j], a[u][j]);

        double t = a[i][y];
        for (int j = y; j < n+m; ++j)
            a[i][j] /= t;

        for (int j = 0; j < n; ++j)
            if (j != i)
            {
                t = a[j][y];
                for (int k = y; k < n+m; ++k)
                    a[j][k] -= a[i][k] * t;
            }
    }
    return i;
}

int a[6], x[7];

int best, good[7];

int main()
{
    REP(i, 6) cin >> a[i];
    CLEAR(mat);
    REP(j, 6) REP(i, 7) if (coff[i][j]) mat[j][i] = 1;
    REP(j, 6) mat[j][7] = a[j];
    solveLinearEquations(mat, 7, 6);

   // REP(i, 6) { REP(j, 8) cout << mat[i][j] << " "; cout << endl;}
   // while(1);
    best = -1;

    for (x[6] = 0; x[6] <= a[0]; ++x[6])
    {
        bool ok = true;
        int sum = x[6];
        REP(i, 6)
        {
            double t = (mat[i][7] - mat[i][6]*1ll*x[6])/mat[i][i];
            if (fabs((long long)(fabs(t)+eps)-fabs(t))>eps || t < -eps)
            {
                ok = false;
                break;
            }

            long long tt = (long long)(fabs(t) + eps);
            if (t < 0) tt = -tt;
            x[i] = tt;
            sum += x[i];
        }

        if (!ok) continue;

        if (best == -1 || sum < best)
        {
            REP(i, 7) good[i] = x[i];
            best = sum;
        }
    }

    cout << best << endl;

    //REP(i, 7) cout << good[i] << " ";
    //cout << endl;

    if (best != -1)
    {
        string a, b, c, d;
        REP(i, good[0]) a += "a", b += "b", c += "b", d += "b";
        REP(i, good[1]) a += "b", b += "a", c += "b", d += "b";
        REP(i, good[2]) a += "b", b += "b", c += "a", d += "b";
        REP(i, good[3]) a += "b", b += "b", c += "b", d += "a";
        REP(i, good[4]) a += "a", b += "a", c += "b", d += "b";
        REP(i, good[5]) a += "a", b += "b", c += "a", d += "b";
        REP(i, good[6]) a += "a", b += "b", c += "b", d += "a";
        cout << a << endl << b << endl << c << endl << d << endl;
    }
	return 0;
}