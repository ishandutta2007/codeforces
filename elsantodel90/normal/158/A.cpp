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
    int n,k;
    cin >> n >> k;
    int value = 0;
    int res = 0;
    forn(i,n)
    {
        int x; cin >> x;
        if (i < k)
            value = x;
        res += x > 0 && x == value;
    }
    cout << res << endl;
    return 0;
}