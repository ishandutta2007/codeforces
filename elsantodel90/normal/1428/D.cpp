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

int main() 
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;
    vector<int> a(n);
    forn(i,n) cin >> a[i];

    vector<pair<int,int>> targets;
    
    vector<int> pending2;
    vector<int> pending3;
    int nextY = 1;
    forsn(x,1,n+1)
    {
        int value = a[x-1];
        if (value == 0)
        {
        }
        else if (value == 1 && !pending2.empty())
        {
            targets.emplace_back(pending2.back(), x);
            pending2.pop_back();
        }
        else
        {
            if (!pending3.empty())
            {
                targets.emplace_back(pending3.back(), x);
                pending3.pop_back();
            }
            targets.emplace_back(nextY, x);
            if (value == 2)
                pending2.push_back(nextY);
            else if (value == 3)
                pending3.push_back(nextY);
            nextY++;
        }
    }
    if (pending2.empty() && pending3.empty())
    {
        cout << targets.size() << "\n";
        for (auto p : targets)
            cout << p.first << " " << p.second << "\n";
    }
    else
        cout << "-1\n";
    return 0;
}