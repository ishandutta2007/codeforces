#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <functional>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>

using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define forsn(i,s,n) for(int i=(s);i<(int)(n);i++)
#define dforn(i,n) for(int i=(n)-1;i>=0;i--)
#define dforsn(i,s,n) for(int i=(n)-1;i>=(int)(s);i--)

#define forall(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); it++)
#define dforall(it,c) for(__typeof((c).rbegin()) it = (c).rbegin(); it != (c).rend(); it++)

#define esta(x,c) ((c).find(x) != (c).end())
#define all(c) (c).begin(),(c).end()

#define DBG(x) cerr << #x << " = " << (x) << endl

const int MAXN = 1000000;

int v[MAXN];
int res[MAXN];

int main()
{
    #ifdef ACMTUYO
        freopen("entrada.in","r",stdin);
    #endif
    int n; cin >> n;
    int a,b; cin >> a >> b;
    forn(i,n) cin >> v[i];
    if (a == b)
    {
        forn(i,a)
        {
            res[i] = 1;
            res[a+i] = 2;
        }
    }
    else if (a < b)
    {
        forn(i,n)
            res[i] = 2;
        dforsn(k,1,6)
        forn(i,n)
        {
            if (res[i] == 2 && v[i] == k)
            {
                res[i] = 1;
                if (--a == 0)
                    goto end;
            }
        }
        end:;
    }
    else
    {
        forn(i,n)
            res[i] = 1;
        dforsn(k,1,6)
        dforn(i,n)
        {
            //DBG(i);
            if (res[i] == 1 && v[i] == k)
            {
                res[i] = 2;
                if (--b == 0)
                    goto end2;
            }
        }
        //DBG(b);
        end2:;
    }

    forn(i,n)
    {
        if (i) cout << " ";
        cout << res[i];
    }
    cout << endl;
    return 0;
}