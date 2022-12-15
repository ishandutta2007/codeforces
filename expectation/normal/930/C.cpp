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

int x,y,n,m;
int a[200000];
int ans[2][200000];

int main()
{
    scanf("%d%d",&n,&m);
    FOR (i,0,n)
    {
        scanf("%d%d",&x,&y);
        a[x-1]++; a[y]--;
    }
    FOR (i,1,m) a[i] += a[i-1];
    set<pair<int,int>> f;
    
    f.insert(make_pair(0,0));
    FOR (i,0,m)
    {
        set<pair<int,int>> ::iterator it = f.upper_bound(make_pair(a[i],100000000));
        it--;
        pair<int,int> g = *it;
        ans[0][i] = g.second + 1;
        if (g.first == a[i]) f.erase(it);
        f.insert(make_pair(a[i],ans[0][i]));
        while (true)
        {
            it = f.upper_bound(make_pair(a[i],ans[0][i]));
            if (it != f.end() && it->second <= ans[0][i]) f.erase(it);
            else break;
        }
    }
    
    f.clear();
    
    f.insert(make_pair(0,0));
    for (int i = m-1; i>= 0; i--)
    {
        set<pair<int,int>> ::iterator it = f.upper_bound(make_pair(a[i],100000000));
        it--;
        pair<int,int> g = *it;
        ans[1][i] = g.second + 1;
        if (g.first == a[i]) f.erase(it);
        f.insert(make_pair(a[i],ans[1][i]));
        while (true)
        {
            it = f.upper_bound(make_pair(a[i],ans[1][i]));
            if (it != f.end() && it->second <= ans[1][i]) f.erase(it);
            else break;
        }
    }
    
    int e = 0;
    FOR (i,0,m) e = max(e,ans[0][i]+ans[1][i]-1);
    cout << e;
    return 0;
}