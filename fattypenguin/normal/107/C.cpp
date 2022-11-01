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

ll f[1 << 16];
int before[16],prefix[16];
int mat[16][16],acc[16][16];
int n,m,used,bitCount[1 << 16];
ll y;

ll dp()
{
    f[0] = 1;
    for (int i = 0;i < (1 << n) - 1;++i)
        for (int j = 0;j < n;++j)
        {
            int now = bitCount[i];
            if (prefix[j] == -1 || prefix[j] == now)
                if (!(i & (1 << j)))
                    if ((before[j] & i) == before[j])
                        f[i | (1 << j)] += f[i];
        }
    return f[(1 << n)-1];
}

int main()
{
    REP(i,(1 << 16))
    {
        bitCount[i] = 0;
        for (int j = i;j;j -= (j&-j))
            ++bitCount[i];
    }
    cin >> n >> y >> m;
    REP(i,n) REP(j,n) mat[i][j] = acc[i][j] = 0;
    fill(prefix,prefix+n,-1);
    fill(before,before+n,0);
    REP(i,m)
    {
        int a,b;
        cin >> a >> b;
        mat[--a][--b] = 1;
        acc[a][b] = 1;
    }
    REP(k,n) REP(i,n) REP(j,n)
    if (i != j && i != k && j != k)
        acc[i][j] |= acc[i][k] & acc[k][j];
    REP(i,n) REP(j,n)
    if (acc[i][j]) before[j] |= 1 << i;
    REP(i,n) REP(j,n)
    if (i != j && (acc[i][j] && acc[j][i]))
    {
        cout << "The times have changed" << endl;
        return 0;
    }
    y -= 2000;
    used = 0;
    REP(i,n)
    {
        REP(j,n)
        {
            if (!(used & (1 << j)))
            {
                prefix[i] = j;
                fill(f,f+(1 << n),0);
                ll step = dp();
             //   cout << "i = " << i << " " << y <<  endl;
                if (y > step)
                {
                    if (j == n-1)
                    {
                        cout << "The times have changed" << endl;
                        return 0;
                    }
                    y -= step;
                    continue;
                }
                used |= 1 << j;
                break;
            }
        }
    }
    REP(i,n)
    {
        if (i) cout << " ";
        cout << prefix[i] + 1;
    }
    cout << endl;
    return 0;
}