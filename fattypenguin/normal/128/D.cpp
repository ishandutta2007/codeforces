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

MII has;

bool gao()
{
    int n;
    cin>>n;
    REP(i,n)
    {
        int x;
        cin>>x;
        has[x]++;
    }
    TR(it,has)
    {
        MII::iterator itx = it;
        if (++itx != has.end())
        {
            if (itx->first!=it->first + 1)
                return false;
            if (it->second < 0) return false;
            itx->second -= it->second + 2;
            if (it == has.begin()) ++itx->second;
        }
    }
    MII::iterator itx = has.end();
    --itx;
    return itx->second == -1;
}

int main()
{
    cout << (gao() ? string("YES") : string("NO")) << endl;
    return 0;
}