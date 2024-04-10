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

tint f(tint tam, int k)
{
    tint base = tam / k;
    int qup = int(tam%k);
    return base*base*(k-qup) + (base+1)*(base+1)*qup;
}

tint reduc(tint tam, int currentK)
{
    return f(tam, currentK) - f(tam, currentK+1);
}

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n,k;
    cin >> n >> k;
    vector<tint> a(n);
    forn(i,n) cin >> a[i];
    const int cuts = k-n;
    
    tint ret = 0;
    for (tint x : a)
        ret += x*x;
        
    priority_queue<pair<tint,int>> reductions;
    forn(i,n)
    if (a[i] > 1)
        reductions.push({reduc(a[i], 1), i});
        
    vector<int> pieces(n, 1);
    forn(cutIndex,cuts)
    {
        assert(!reductions.empty());
        auto par = reductions.top(); reductions.pop();
        int index = par.second;
        ret -= par.first;
        if (a[index] > ++pieces[index])
            reductions.push({reduc(a[index], pieces[index]), index});
    }
    cout << ret << "\n";
    return 0;
}