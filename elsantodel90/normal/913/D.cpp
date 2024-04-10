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
#define dforn(i,n) for(int i=int(n)-1;i>=0; i--)
#define dforsn(i,s,n) for(int i=int(n)-1;i>=(int)(s); i--)

#define esta(x,c) ((c).find(x) != (c).end())

#define all(c) (c).begin(), (c).end()

using namespace std;

typedef long long tint;

const int MAXN = 300000;

// tiempo, id
vector<pair<int,int>> pt[MAXN]; 

int main() 
{
    #ifdef ACMTUYO
        assert(freopen("d.in" ,"r",stdin));
    #endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    tint N;
    while (cin >> N)
    {
        tint T;
        cin >> T;
        forn(i,N+1) pt[i].clear();
        forn(i,N)
        {
            int a,t;
            cin >> a >> t;
            pt[a].push_back({t,i+1});
        }
        bool resuelto = false;
        set<pair<int,int>> available;
        set<pair<int,int>> used;
        tint usedTime = 0;
        dforsn(k,0, N+1)
        {
            available.insert(all(pt[k]));
            if (int(used.size()) < k && !available.empty())
            {
                while (!used.empty() && used.rbegin()->first > available.begin()->first)
                {
                    auto itLast = used.end();
                    --itLast;
                    auto peor = *itLast;
                    usedTime -= peor.first;
                    usedTime += available.begin()->first;
                    
                    used.erase(itLast);
                    used.insert(*available.begin());
                    available.erase(available.begin());
                    available.insert(peor);
                }
                while (int(used.size()) < k && !available.empty() && usedTime + available.begin()->first <= T)
                {
                    usedTime += available.begin()->first;
                    used.insert(*available.begin());
                    available.erase(available.begin());
                }
            }
            if (int(used.size()) == k)
            {
                resuelto = true;
                cout << k << endl;
                cout << k << endl;
                bool pri = true;
                for (auto it : used)
                {
                    if (pri)
                        pri = false;
                    else
                        cout << " ";
                    cout << it.second;
                }
                cout << endl;
            }
        }
        assert(resuelto);
    }
    return 0;
}