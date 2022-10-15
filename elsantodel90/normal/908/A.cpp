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

using namespace std;

typedef long long tint;

bool vocal(char x)
{
    return x == 'a' ||
           x == 'e' ||
           x == 'i' ||
           x == 'o' ||
           x == 'u';
}

bool impar(char x)
{
    return '0' <= x && x <= '9' && (x-'0')%2 == 1;
}


int main() 
{
    #ifdef ACMTUYO
        assert(freopen("a.in" ,"r",stdin));
    #endif
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    string s; 
    while (cin >> s)
    {
        int total = 0;
        forn(i,s.size())
        if (vocal(s[i]) || impar(s[i]))
            total++;
        cout << total << endl;
    }
    return 0;
}