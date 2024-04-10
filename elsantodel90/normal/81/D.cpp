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

typedef pair<int,int> pint;

const int MAXM = 1024;
const int MAXN = 1024;

pint col[MAXM];

int res[MAXN];

int main()
{
    #ifdef ACMTUYO
        freopen("entrada.in","r",stdin);
    #endif
    int n,m;
    cin >> n >> m;
    int sum = 0;
    forn(i,m)
    {
        col[i] = pint(0,i+1);
        cin >> col[i].first;
        sum += col[i].first;
    }

    sort(col,col+m, greater<pint>());
    while (sum > n)
    {
        col[0].first--;
        sum--;
        int i=0;
        while (i < m-1 && col[i] < col[i+1])
        {
            swap(col[i],col[i+1]);
            i++;
        }
    }

    const int MAX_COLOR = n/2;
    if (col[0].first > MAX_COLOR || sum < n)
        cout << "-1" << endl;
    else
    {
        int j = 0;
        int nk = 0;
        forn(i,n)
        {
            res[j] = col[nk].second;
            if (--col[nk].first == 0)
                nk++;
            j += 2;
            if (j >= n) j = 1;
        }
        forn(i,n)
        {
            if (i) cout << " ";
            cout << res[i];
        }
        cout << endl;
    }
    return 0;
}