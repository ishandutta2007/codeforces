#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cassert>
#include <algorithm>
#include <sstream>
#include <numeric>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <string>
#include <vector>

using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n);i++)
#define forsn(i,s,n) for(int i=(s);i<(int)(n);i++)


int main()
{
    #ifdef ACMTUYO
        freopen("entrada.in","r",stdin);
    #endif
    int n; cin >> n;
    string s;
    getline(cin,s);
    vector<string> v;
    forn(comandito,n)
    {
        getline(cin,s);
        if (s[0] == 'p')
        {
            cout << "/";
            forn(i,v.size())
                cout << v[i] << "/";
            cout << endl;
        }
        else
        {
            s = s.substr(3) + "/";
            if (s[0] == '/')
            {
                v.clear();
                s.erase(0,1);
            }
            int p = 0;
            while (p < (int)s.size())
            {
                int q = p;
                while (s[q] != '/') q++;
                string dir = s.substr(p,q-p);
                if (dir == "..")
                    v.pop_back();
                else
                    v.push_back(dir);
                p = q+1;
            }
        }
    }
    return 0;
}