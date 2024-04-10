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
#include <vector>

using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define forsn(i,s,n) for(int i=(s);i<(int)(n);i++)

const int MAXN = 1<<20;
const int INF = 1000000000;

int v[MAXN];
int s[MAXN];

int main()
{
    #ifdef ACMTUYO
        //freopen("entrada.in","r",stdin);
    #endif
    int n; scanf("%d",&n);
    forn(i,n)
        scanf("%d",v+i);
    int res = -INF;
    forsn(k,1,n)
    if (n % k == 0 && (n/k) >= 3)
    {
        forn(i,k) s[i] = 0;
        forn(i,n) s[i%k] += v[i];
        forn(i,k) if (s[i] > res) res = s[i];
    }
    cout << res << endl;
    return 0;
}