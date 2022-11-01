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

int F[2][10007];
int f[107][107],g[107];
VI a;

int main()
{
    int n,m;
    CLEAR(F);
    int now = 0;
    cin>>n>>m;
    REP(i,n)
    {
        int k;
        cin>>k;
        a.resize(k);
        REP(i,k) cin>>a[i];
        FILL(g,0);
        g[0] = 0;
        for (int i = 0;i < k;++i)
            for (int j = i;j < k;++j)
            {
                if (j==i) f[i][j]=a[i]; else f[i][j]=f[i][j-1]+a[j];
            }

        for (int i = 0;i < k;++i)
            for (int j = i;j < k;++j)
            {
                int idx = k - (j-i+1);
                g[idx] = max(g[idx],f[0][k-1]-f[i][j]);
            }
        g[k]=f[0][k-1];
        int prev = now;
        now ^= 1;
        CLEAR(F[now]);
        REP(j,m+1)
        {
            F[now][j]=F[prev][j];
            REP(t,k+1)
                if (j>=t) F[now][j]=max(F[now][j],F[prev][j-t]+g[t]);
        }
    }
    cout << F[now][m] << endl;
    return 0;
}