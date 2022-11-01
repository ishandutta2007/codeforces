#include <functional>
#include <algorithm>
#include <stdexcept>
#include <iostream>
#include <sstream>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <cctype>
#include <vector>
#include <string>
#include <bitset>
#include <cmath>
#include <queue>
#include <stdio.h>
#include <stack>
#include <ctime>
#include <list>
#include <map>
#include <set>
#define REP(i,n) for(int i=0;i<n;i++)
#define TR(i,x) for(typeof(x.begin()) i=x.begin();i!=x.end();i++)
#define ALL(x) x.begin(),x.end()
#define SORT(x) sort(ALL(x))
#define CLEAR(x) memset(x,0,sizeof(x))
#define FILL(x,c) memset(x,c,sizeof(x))

using namespace std;

const double eps = 1e-8;

#define PB push_back
#define MP make_pair

typedef map<int,int> MII;
typedef map<string,int> MSI;
typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<long double> VD;
typedef pair<int,int> PII;
typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;

string s,t;
VI ind[128];

int main()
{
    cin >> s >> t;
    int ls = s.size();
    int lt = t.size();
    for (int i = 0;i < 128;++i)
        ind[i].clear();
    for (int i = 0;i < ls;++i)
        ind[s[i]].PB(i);
    int now[128];
    CLEAR(now);
    int ans = 1,last = -1;
    for (int i = 0;i < lt;++i)
    {
        if (ind[t[i]].size() == 0)
        {
            ans = -1;
            break;
        }
        int l = now[t[i]],r = ind[t[i]].size()-1;
        while (l < r)
        {
            int mid = (l+r)>>1;
            if (ind[t[i]][mid] >= last)
                r = mid;
            else
                l = mid+1;
        }
        now[t[i]] = l;
        if (now[t[i]] < ind[t[i]].size() && ind[t[i]][now[t[i]]] > last)
        {
            last = ind[t[i]][now[t[i]]];
            ++now[t[i]];
        }
        else
        {
            ++ans;
            for (int j = 'a';j <= 'z';++j)
                now[j] = 0;
            ++now[t[i]];
            last = ind[t[i]][0];
        }
    }
    cout << ans << endl;
    return 0;
}