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

const LL mod = 1000000007;

vector<vector<int>> ans;
string q;
set<int> s[2];

int main()
{
    cin >> q;
    FOR (i,0,q.size()) s[q[i]-'0'].insert(i);
    while (s[0].size())
    {
        vector<int> cur;
        int st = *s[0].begin();
        cur.push_back(st);
        s[0].erase(s[0].begin());
        while (true)
        {
            set<int>::iterator it = s[1].lower_bound(st);
            if (it == s[1].end()) break;
            st = *it;
            cur.push_back(st);
            s[1].erase(it);
            
            it = s[0].lower_bound(st);
            if (it == s[0].end()) {cout << -1; return 0;}
            st = *it;
            cur.push_back(st);
            s[0].erase(it);
        }
        ans.push_back(cur);
    }
    if (s[1].size()) cout << -1;
    else
    {
        cout << ans.size() << "\n";
        FOR (i,0,ans.size()) {
            cout << ans[i].size()<<" ";
            FOR (j,0,ans[i].size()) cout <<ans[i][j]+1<<" ";
            cout << "\n";
        }
    }
}