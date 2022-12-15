#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <queue>
#include <cmath>
#include <algorithm>

using namespace std;

#define FOR(i,a,b) for (int i = (a); i < (b); i++)
#define SZ(a) a.size()
#define LL long long

LL n, m, r, k;
priority_queue<pair<LL, pair<int, int>>> rs;

LL solve(LL a, LL b, LL c)
{
    return min(a,b-c)-max(a-r+1,0LL)+1;
}

LL calc(double x, double y)
{
    if (x < 0) return 0;
    if (x >= n) return 0;
    return solve(x,n,r)*solve(y,m,r);
}

int main()
{
    cin >> n >> m >> r >> k;
    LL x = n/2;
    FOR (i,0,m)
        rs.push(make_pair(calc(x,i),make_pair(x,i)));
    LL ans = 0;
    FOR (i,0,k)
    {
        ans += rs.top().first;
        pair<int, int> f = rs.top().second;
        rs.pop();
        
        if (f.first <= x) rs.push(make_pair(calc(f.first-1,f.second),make_pair(f.first-1,f.second)));
        if (f.first >= x) rs.push(make_pair(calc(f.first+1,f.second),make_pair(f.first+1,f.second)));
    }
    printf("%.15lf",ans/(n-r+1.0)/(m-r+1.0));
}