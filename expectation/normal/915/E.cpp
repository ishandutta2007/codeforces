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

int n, m;
set<pair<int,int>> e;
set<pair<int,int>>::iterator it, it2;

int main()
{
    cin >> n >> m;
    int ans = n;
    FOR(i,0,m)
    {
        int a, b, c;
        scanf("%d%d%d",&a,&b,&c);
        if (c == 2)
        {
            vector<pair<int,int>> add;
            it = e.upper_bound(make_pair(a,-1));
            if (it != e.begin())
            {
                it--;
                if (a <= it->second)
                {
                    add.push_back(make_pair(it->first,a-1));
                    add.push_back(make_pair(b+1,it->second));
                    it2 = it;
                    it++;
                    ans += it2->second-it2->first+1;
                    e.erase(it2);
                }
                else it++;
            }
            while (it != e.end() && b >= it->first)
            {
                add.push_back(make_pair(b+1,it->second));
                it2 = it;
                it++;
                ans += it2->second-it2->first+1;
                e.erase(it2);
            }
            FOR (i,0,add.size())
            if (add[i].first <= add[i].second)
            {
                ans -= add[i].second-add[i].first+1;
                e.insert(add[i]);
            }
        }
        else
        {
            int L = a, R = b;
            it = e.upper_bound(make_pair(a,-1));
            if (it != e.begin())
            {
                it--;
                if (it != e.end() && a <= it->second)
                {
                    L = min(L,it->first);
                    R = max(R,it->second);
                    it2 = it;
                    it++;
                    ans += it2->second-it2->first+1;
                    e.erase(it2);
                }
                else it++;
            }
            while (it != e.end() && b >= it->first)
            {
                R = max(R,it->second);
                it2 = it;
                it++;
                ans += it2->second-it2->first+1;
                e.erase(it2);
            }
            ans -= R-L+1;
            e.insert(make_pair(L,R));
        }
        //for(it=e.begin();it!=e.end();it++)
        //   cout << it->first<<" "<<it->second<<endl;
        cout << ans << "\n";
    }
}