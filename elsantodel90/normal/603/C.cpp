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

const char * const name[2] = {"Nicky", "Kevin"};

const int MAXN = 1000000;

// K impar
int f(int x)
{
    if (x <= 3)
        return x % 2;
    else if (x == 4)
        return 2;
    else if (x % 2)
        return 0;
    else if (f(x/2) == 1)
        return 2;
    else
        return 1;
}

// K par
int g(int x)
{
    if (x <= 2)
        return x;
    else
        return x % 2 == 0;
}

int main()
{
    
    #ifdef ACMTUYO
        if (!freopen("c.in" ,"r",stdin)) return 1;
    #endif
    int _sc = 0;
    int N,K;
    while (scanf("%d%d", &N, &K) != EOF)
    {
        int grundy = 0;
        forn(i,N)
        {
            int x;
            _sc = scanf("%d", &x);
            if (K % 2)
                grundy ^= f(x);
            else
                grundy ^= g(x);
        }
        printf("%s\n", name[grundy > 0]);
    }
    if (_sc) return 0;
    return 0;
}