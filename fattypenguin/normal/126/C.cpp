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
#define FOR(i,a,b) for (int i=a;i<b;++i)
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

char img[2007][2007];
int c[2007],r[2007];

int main()
{
    int n;
    cin>>n;
    REP(i,n) scanf("%s",img[i]);
    REP(i,n) REP(j,n) img[i][j]-='0';
    int ans = 0;
    REP(i,n) for (int j = n-1;j>i;--j)
        if (c[j]^r[i]^img[i][j])
        {
            ++ans;
            c[j]^=1,r[i]^=1;
        }
    REP(i,n) img[i][i]^=c[i]^r[i];
    CLEAR(c),CLEAR(r);
    for (int i = n-1;i >= 0;--i) REP(j,i+1)
        if (c[j]^r[i]^img[i][j])
        {
            ++ans;
            c[j]^=1,r[i]^=1;
        }
    cout<<ans<<endl;
    return 0;
}