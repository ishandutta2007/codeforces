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

    int TT;
    cin >> TT;
    forn(tt,TT)
    {
        int n;
        cin >> n;
        string s;
        cin >> s;
        bool allLeft = true;
        bool allRight = true;
        for (char c : s)
        {
            if (c == '<')
                allRight = false;
            else if (c == '>')
                allLeft = false;
        }
        int basic = 0;
        forn(i,n)
            basic += s[i] == '-' || s[(i+1)%n] == '-';
        int total = (allRight || allLeft) ? n : basic;
        cout << total << "\n";
    }
    return 0;
}