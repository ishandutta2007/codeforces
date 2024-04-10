#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <sstream>
#include <numeric>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>

using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define forsn(i,s,n) for(int i=(s);i<(int)(n);i++)


int main()
{
    #ifdef ACMTUYO
        //freopen("entrada.in","r",stdin);
    #endif
    int n; scanf("%d",&n);
    int C[8]; forn(i,8) C[i] = 0;
    forn(i,n)
    {
        int x; scanf("%d",&x);
        C[x]++;
    }
    int res = 0;
    
    res += C[4]; C[4] = 0;
    
    res += C[3]; C[1] = max(0, C[1] - C[3]); C[3] = 0;
    
    res += (2 * C[2] + C[1] + 3) / 4;
    
    cout << res << endl;
    return 0;
}