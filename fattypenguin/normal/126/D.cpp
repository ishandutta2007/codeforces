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

const ULL LIMIT = 1000000000000000000ull;
ULL fib[99];
int ok[99];
int tot=0,n=0;
ULL gao[99][3][3];

int main()
{
    fib[0]=fib[1]=1; tot=2;
    while (fib[tot-1]<LIMIT)
        fib[tot] = fib[tot-1]+fib[tot-2],++tot;
    int T;
    cin>>T;
    while (T--)
    {
        ULL x; cin>>x;
        CLEAR(ok);
        for (int i = tot-1;i>0;--i)
            if (x>=fib[i]) ok[i]=true,x-=fib[i];
        CLEAR(gao);
        gao[tot+1][0][0] = 1;
        for (int i = tot+1;i;--i)
            REP(u,3) REP(v,3)
                if (gao[i][u][v])
                {
                    int uu = u+ok[i],vv = v;
                    for (int d=-1;d<=0;++d)
                    {
                        int ww=uu+d+vv,rr=uu+d;
                        if (ww>=0&&ww<3&&rr>=0&&rr<3)
                            gao[i-1][ww][rr]+=gao[i][u][v];
                    }
                }
        cout<<gao[0][0][0]<<endl;
    }
    return 0;
}