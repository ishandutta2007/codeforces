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
typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;

int BIT[100000 + 1023];
int n,n0;

void insert(int x,int t)
{
    while (x <= n0)
    {
        BIT[x] = min(BIT[x],t);
        x += (x & -x);
    }
}

int quary(int x)
{
    int ret = 0;
    while (x > 0)
    {
        ret = min(ret,BIT[x]);
        x -= (x & -x);
    }
    return ret;
}

MII ind;
int peop[100000 + 1023];
int ans[100000 + 1023];

int main()
{
    cin >> n;
    ind.clear();
    REP(i,n)
    {
        cin >> peop[i];
        ind[peop[i]] = 1;
    }
    n0 = 0;
    CLEAR(BIT);
    TR(i,ind)
        i->second = ++n0;
    REP(i,n)
        peop[i] = ind[peop[i]];
    for (int i = n-1;i >= 0;--i)
    {
        ans[i] = quary((peop[i]-1));
        if (!ans[i])
            ans[i] = -1;
        else
            ans[i] = -i - ans[i] -1;
        insert(peop[i],-i);
    }
    REP(i,n)
    {
        cout << ans[i];
        if (i != n-1) cout << " ";
    }
    cout << endl;

    return 0;
}