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
#include <iomanip>

#define forn(i,n) for(int i=0;i<(int)(n); i++)
#define forsn(i,s,n) for(int i=(s);i<(int)(n); i++)
#define dforn(i,n) for(int i=(n)-1;i>=0; i--)
#define dforsn(i,s,n) for(int i=(n)-1;i>=(int)(s); i--)

#define esta(x,c) ((c).find(x) != (c).end())

#define all(c) (c).begin(), (c).end()

using namespace std;

typedef long long tint;

const char *ans[2] = {"No", "Yes"};

int main() 
{
    #ifdef ACMTUYO
        assert(freopen("b.in" ,"r",stdin));
    #endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    tint N;
    while (cin >> N)
    {
        vector<int> p(N);
        p[0] = -1;
        forn(i,N-1) {cin >> p[i+1]; p[i+1]--;}
        vector<bool> leaf(N, true);
        forsn(i,1,N) leaf[p[i]] = false;
        leaf[0] = false;
        vector<int> leafChildren(N,0);
        forsn(i,1,N)
            leafChildren[p[i]] += leaf[i];
        bool spruce = true;
        forn(i,N)
        if (!leaf[i] && leafChildren[i] < 3)
            spruce = false;
        cout << ans[spruce] << endl;
    }        
    return 0;
}