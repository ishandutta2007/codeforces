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

#define PB push_back
#define MP make_pair

const LL mod = 1000000007;

int n,m;
set<pair<int,int>> res[200000];
set<pair<int,int>>::iterator it2,it3;
int ans = 0;

int main()
{
    cin >> n >> m;
    FOR (i,0,n) res[i].insert(MP(0,0));
    FOR (i,0,m)
    {
        int a,b,c;
        cin >> a >> b >> c;
        a--; b--;
        set<pair<int,int>>::iterator it = res[a].lower_bound(MP(c,0));
        it--;
        ans = max(ans,it->second+1);
        res[b].insert(MP(c,it->second+1));
        it = res[b].find(MP(c,it->second+1));
        it2 = it; it2--;
        if (it2->second >= it->second)
        {
            res[b].erase(it);
        } else {
            while (true)
            {
                it2 = it; it2++;
                if (it2 == res[b].end() || it2->second > it->second) break;
                res[b].erase(it2);
            }
        }
    }
    cout << ans;
}