#include <cstdio>
#include <cstdlib>
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

#define forn(i,n) for(int i=0;i<(int)(n); i++)
#define forsn(i,s,n) for(int i=(s);i<(int)(n); i++)

#define forall(it, c) for(typeof((c).begin()) it = (c).begin(); it != (c).end(); it++)

using namespace std;

typedef long long tint;

const int MAXN = 128;

vector<int> v[32];
string s[MAXN];

const char * IMPOSSIBLE = "Impossible";
int u[32], curr[32];

string solution = "";

bool dfs(int x)
{
    curr[x] = true;
    u[x] = true;
    forall(it, v[x])
    {
        if (curr[*it]) return false;
        if (!u[*it])
        {
            if (!dfs(*it))
            {
                return false;
            }
        }
    }
    solution += 'a' + x;
    curr[x] = false;
    return true;
}

int main() 
{
    #ifdef ACMTUYO
        freopen("a.in","r",stdin);
    #endif
    int n; cin >> n;
    forn(i,n) cin >> s[i];
    forn(i,n)
    forn(j,i)
    {
        int k = 0;
        while (k < (int)s[i].size() && k < (int)s[j].size() && s[i][k] == s[j][k]) k++;
        if (k == (int)s[i].size())
        {
            cout << IMPOSSIBLE << endl;
            return 0;
        }
        else if (k == (int)s[j].size())
        {
            // OK
        }
        else
        {
            v[s[i][k] - 'a'].push_back(s[j][k] - 'a');
        }
    }
    forn(i,32) u[i] = false;
    forn(i,32) curr[i] = false;
    forn(i,26)
    {
        if (!u[i])
        {
            if (!dfs(i))
            {
                cout << IMPOSSIBLE << endl;
                return 0;
            }
        }
    }
    cout << solution << endl;
    return 0;
}
// END CUT HERE