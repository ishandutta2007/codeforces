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


int main()
{   
    #ifdef ACMTUYO
        freopen("a.in","r",stdin);
    #endif
    int n1,n2,k1,k2; cin >> n1 >> n2 >> k1 >> k2;
    if (n1 > n2) cout << "First" << endl;
    else cout << "Second" << endl;
    return 0;
}