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
typedef long long ll;
typedef long double LD;
typedef unsigned long long ULL;

int F[507][507],S[507][507];
char buf[1007];

int main()
{
    int n,m;
    cin >> n >> m;
    CLEAR(S),CLEAR(F);
    REP(i,n)
    {
        cin >> buf;
        for (int j = 0;j < m;++j)
            if (buf[j] == 'G')
                S[i+1][j+1] = 0;
            else S[i+1][j+1] = 1;
        for (int j = 1;j <= m;++j)
            S[i+1][j] += S[i+1][j-1];
    }
    FILL(F,0x7f);
    F[0][1] = 0;
    int ans = 0x7f7f7f7f;
   // for (int i = 1;i <= n;++i) cout << S[i][m] << endl;
    for (int i = 1;i <= n;++i)
    {
        if (i & 1)
        {
            for (int j = 1;j <= m;++j)
                if (S[i][j] == S[i][m])
                {
                    for (int k = 1;k <= j;++k)
                        if (S[i][k-1]==0)
                            F[i][j] = min(F[i][j],F[i-1][k]+j-k+1);
                }
        }
        else
        {
            for (int j = 1;j <= m;++j)
                if (S[i][j-1]==0)
                {
                    for (int k = j;k <= m;++k)
                        if (S[i][k]==S[i][m])
                            F[i][j] = min(F[i][j],F[i-1][k] + k-j+1);
                }
        }
        bool ok = true;
        for (int j = i+1;j <= n;++j)
            if (S[j][m] != 0)
            {
                ok = false;
                break;
            }
        if (ok)
        {
         //   cout << "i = " << i << endl;
            for (int j = 1;j <= m;++j)
                ans = min(ans,F[i][j]);
        }
    }
    cout << ans-1 << endl;
    return 0;
}