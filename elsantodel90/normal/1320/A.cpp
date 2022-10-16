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

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    map<tint,tint> beauty;
    int N; cin >> N;
    forn(i,N)
    {
        int b; cin >> b;
        beauty[i-b] += b;
    }
    tint maxi = 0;
    for (auto it : beauty)
        maxi = max(maxi, it.second);
    cout << maxi << "\n";
    return 0;
}