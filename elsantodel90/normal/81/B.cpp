#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <cassert>
#include <sstream>
#include <algorithm>
#include <numeric>
#include <functional>
#include <string>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>

using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define forsn(i,s,n) for(int i=(s);i<(int)(n);i++)
#define dforn(i,n) for(int i=(n)-1;i>=0;i--)
#define dforsn(i,s,n) for(int i=(n)-1;i>=(int)(s);i--)

#define forall(it,c) for(__typeof((c).begin()) it = (c).begin(); it != (c).end(); it++)
#define dforall(it,c) for(__typeof((c).rbegin()) it = (c).rbegin(); it != (c).rend(); it++)

#define esta(x,c) ((c).find(x) != (c).end())
#define all(c) (c).begin(),(c).end()

#define DBG(x) cerr << #x << " = " << (x) << endl

string trim(const string &s)
{
    int i=0;
    while (i < (int)s.size() && s[i] == ' ') i++;
    int j = s.size();
    while (j > 0 && s[j-1] == ' ') j--;
    return s.substr(i,j-i);
}

int main()
{
    #ifdef ACMTUYO
        freopen("entrada.in","r",stdin);
    #endif
    string l; getline(cin,l);
    string s;
    for (int i=0,j=0;i<(int)l.size();i=j)
    {
        while (j < (int)l.size() && l[i] == l[j]) j++;
        if (l[i] == ' ' && i > 0 && j < (int)l.size() && isdigit(l[i-1]) && isdigit(l[j]))
            s += " ";
        else if (l[i] == ' ')
            ;
        else
        {
            s += l.substr(i,j-i);
            //DBG(s);
        }
    }
    string res;
    forn(i,s.size())
    {
        const char c = s[i];
        if (c == ',')
            res += ", ";
        else if(c == '.')
        {
            i += 2;
            if (res.empty() || res[res.size()-1] != ' ')
                res += " ";
            res += "...";
        }
        else
            res += c;
    }
    cout << trim(res) << endl;
    return 0;
}