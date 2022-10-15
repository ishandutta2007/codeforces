#include <iostream>
#include <cstdio>
#include <cstring>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <cassert>

using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define forsn(i,s,n) for(int i=(s);i<(int)(n);i++)
#define dforn(i,n) for(int i=(n)-1;i>=0;i--)

#define forall(it,c) for(typeof((c).begin()) it = (c).begin(); it != (c).end(); it++)
#define dforall(it,c) for(typeof((c).rbegin()) it = (c).rbegin(); it != (c).rend(); it++)

#define esta(x,c) ((c).find(x) != (c).end())

#define all(c) (c).begin(), (c).end()

typedef long long tint;
typedef pair<int,int> pint;

tint v[64];

int main()
{   
    #ifdef ACMTUYO
        freopen("b.in","r",stdin);
    #endif
    tint n,m; cin >> n >> m;
    tint total = 1;
    forn(i,n-1) total *= 2;
    m--;
    int a = 0, b = n;
    forsn(curr, 1, n+1)
    {
        if (m < total/2)
        {
            v[a++] = curr;
        }
        else
        {
            m -= total/2;
            v[--b] = curr;
        }
        total /= 2;
    }
    forn(i,n)
    {
        if (i) cout << " ";
        cout << v[i];
    }
    cout << endl;
    return 0;
}