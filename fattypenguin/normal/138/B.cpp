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
#include <cassert>
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

char a[500000],b[500000];
char c[500000],d[500000];
int p[10],q[10],n;
int s[10],t[10];

int gao(int where)
{
    for (int i = 0; i <= 9;++i)
    {
        for (;s[i]>0&&t[9-i]>0;--s[i],--t[9-i])
        {
            a[where] = '0'+i;
            b[where--] = '0'+9-i;
        }
    }
    int aa = where,bb = where;
    for (int i = 0;i <= 9;++i)
    {
        while (s[i]--) a[aa--] = '0'+i;
        while (t[i]--) b[bb--] = '0'+i;
    }
    return n - where;
}

int main()
{
    ios::sync_with_stdio(false);
    cin>>a;
    n = strlen(a);
    CLEAR(p); CLEAR(q);
    REP(i,n) p[a[i]-'0']++,q[a[i]-'0']++;
    int good = 0;
    c[n] = d[n] = 0;
    REP(i,n) c[i] = a[i],d[i] = a[i];
    for (int i = 1;i <= 9;++i)
    {
        if (p[i] > 0 && q[10-i]>0)
        {
            memcpy(s,p,sizeof(s));
            memcpy(t,q,sizeof(t));
            int beg = n-1;
            while (s[0]>t[9] && t[0]>s[9])
            {
                a[beg] = '0';
                b[beg--] = '0';
                --s[0],--t[0];
            }
            a[beg] = i+'0';
            b[beg--] = 10-i+'0';
            s[i]--;
            t[10-i]--;
            int best = gao(beg);
            if (best > good)
            {
                good = best;
                REP(i,n) c[i] = a[i],d[i] = b[i];
            }
        }
    }
    int best = p[0];
    int aa = n-1,bb = n-1;
    for (int i = 0;i <= 9;++i)
    {
        while (p[i]--) a[aa--] = '0'+i;
        while (q[i]--) b[bb--] = '0'+i;
    }
    if (best > good)
    {
        good = best;
        REP(i,n) c[i] = a[i],d[i] = b[i];
    }
    cout << c << endl << d << endl;
    return 0;
}