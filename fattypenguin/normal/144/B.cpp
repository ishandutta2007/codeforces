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

struct Circle
{
    int x,y,r;
} c[1007];

bool cor[2007][2007];
const int BASE = 1000;

int main()
{
    int x1,y1,x2,y2;
    cin>>x1>>y1>>x2>>y2;
    int p = x1,q = x2;
    x1 = min(p,q) , x2 = max(p,q);
    p = y1, q = y2;
    y2 = min(p,q) , y1 = max(p,q);
    CLEAR(cor);
    int n;
    cin>>n;
    int answer = 0;
    REP(i,n) cin>>c[i].x>>c[i].y>>c[i].r;
    for (int i = x1;i <= x2;++i)
        for (int j = y2;j <= y2;++j)
        {

            bool ok = false;
            for (int k = 0;k < n;++k)
                if ((long long)(i-c[k].x)*(long long)(i-c[k].x) +
                    (long long)(j-c[k].y)*(long long)(j-c[k].y) <=
                    (long long)c[k].r*c[k].r)
                {
                    ok = true;
                    break;
                }
            if (!ok) ++answer;
        }
    for (int i = x1;i <= x2;++i)
        for (int j = y1;j <= y1;++j)
        {
            bool ok = false;
            for (int k = 0;k < n;++k)
                if ((long long)(i-c[k].x)*(long long)(i-c[k].x) +
                    (long long)(j-c[k].y)*(long long)(j-c[k].y) <=
                    (long long)c[k].r*c[k].r)
                {
                    ok = true;
                    break;
                }
            if (!ok) ++answer;
        }
    for (int i = x1;i <= x1;++i)
        for (int j = y2+1;j <= y1-1;++j)
        {
            bool ok = false;
            for (int k = 0;k < n;++k)
                if ((long long)(i-c[k].x)*(long long)(i-c[k].x) +
                    (long long)(j-c[k].y)*(long long)(j-c[k].y) <=
                    (long long)c[k].r*c[k].r)
                {
                    ok = true;
                    break;
                }
            if (!ok) ++answer;
        }
    for (int i = x2;i <= x2;++i)
        for (int j = y2+1;j <= y1-1;++j)
        {
            bool ok = false;
            for (int k = 0;k < n;++k)
                if ((long long)(i-c[k].x)*(long long)(i-c[k].x) +
                    (long long)(j-c[k].y)*(long long)(j-c[k].y) <=
                    (long long)c[k].r*c[k].r)
                {
                    ok = true;
                    break;
                }
            if (!ok) ++answer;
        }
    cout << answer << endl;
    return 0;
}