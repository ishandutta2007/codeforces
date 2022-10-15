#include <cstdio>
#include <cstdlib>
#include <cassert>
#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <cmath>
#include <cstring>
#include <algorithm>
#include <numeric>
#include <functional>
#include <stack>
#include <sstream>

#define forn(i,n) for(int i=0;i<(int)(n); i++)
#define forsn(i,s,n) for(int i=(s);i<(int)(n); i++)
#define dforn(i,n) for(int i=(n)-1;i>=0; i--)
#define dforsn(i,s,n) for(int i=(n)-1;i>=(int)(s); i--)

#define esta(x,c) ((c).find(x) != (c).end())

using namespace std;

typedef long long tint;

const int MAXN = 1000000;

char cad[MAXN];

int main() 
{
    
    #ifdef ACMTUYO
        if (!freopen("a.in" ,"r",stdin)) return 1;
    #endif
    int _sc = 0;
    int N;
    while (scanf("%d", &N) != EOF)
    {
        _sc = scanf("%s", cad);
        char last = 0;
        int total = 0;
        int equPos = 0;
        for(char *p = cad; *p; p++)
        {
            total += *p != last;
            equPos += *p == last;
            last = *p;
        }
        int extra = min(2, equPos);
        printf("%d\n", total + extra);
    }
    if (_sc) return 0;
    return 0;
}