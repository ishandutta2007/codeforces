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

int n, t;
pair<pair<int, int>, int> z[300000];
vector<int> ans;

bool ok(int num)
{
    int take = 0;
    int st = 0;
    FOR (i,0,n)
    if (z[i].first.second >= num && take < num)
        take++, st += z[i].first.first;
    if (st > t || take < num) return false;
    ans.clear();
    take = 0;
    FOR (i,0,n)
    if (z[i].first.second >= num && take < num)
        take++, ans.push_back(z[i].second+1);
    return true;
    
}

int main()
{
    cin >> n >> t;
    FOR (i,0,n)
    {
        cin >> z[i].first.second >> z[i].first.first;
        z[i].second = i;
    }
    sort(z,z+n);
    int l = 0, r = n;
    while (l != r)
    {
        int x = (r+l+1)/2;
        if (ok(x)) l = x;
        else r = x-1;
    }
    cout << l<<"\n"<<l<<"\n";
    FOR (i,0,l) cout << ans[i]<<" ";
}