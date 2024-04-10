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

int main() 
{
    #ifdef ACMTUYO
        freopen("a.in" ,"r",stdin);
    #endif
    int N;
    while (scanf("%d", &N) != EOF)
    {
        vector<tint> v(N);
        forn(i,N) cin >> v[i];
        sort(v.begin(), v.end());
        int D = N / 2;
        tint ret = 1000000000000000000LL;
        forn(i, N - D)
            ret = min(ret, v[i+D] - v[i]);
        cout << ret << endl;
    }
    return 0;
}