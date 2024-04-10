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

#define forn(i,n) for(int i=0;i<(int)(n); i++)
#define forsn(i,s,n) for(int i=(s);i<(int)(n); i++)
#define dforn(i,n) for(int i=(n)-1;i>=0; i--)
#define dforsn(i,s,n) for(int i=(n)-1;i>=(int)(s); i--)

#define esta(x,c) ((c).find(x) != (c).end())
#define all(x) (x).begin(), (x).end()

using namespace std;

typedef long long tint;
typedef pair<int,int> pint;

bool possible[256];

int main() 
{
    #ifdef ACMTUYO
        assert(freopen("a.in" ,"r",stdin));
    #endif
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    forn(i,256) possible[i] = true;
    int N; cin >> N;
    int shocks = 0;
    forn(i,N)
    {
        int options = 0;
        forsn (l, 'a','z'+1)
            options += possible[l];
        string action;
        string word;
        cin >> action >> word;
        if (action == ".")
        {
            for (char c : word)
                possible[int(c)] = false;
        }
        else if (action == "!")
        {
            shocks += (options == 1);
            forsn (l, 'a','z'+1)
            if (word.find(char(l)) == string::npos)
                possible[l] = false;
        }
        else
        {
            assert(action == "?");
            if (i < N-1)
            {
                possible[int(word[0])] = false;
                shocks += (options == 1);
            }
        }
    }
    cout << shocks << endl;
    return 0;
}