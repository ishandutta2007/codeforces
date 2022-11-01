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
#include <assert.h>
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
typedef long long int64;
typedef long long ll;
typedef unsigned int UI;
typedef long double LD;
typedef unsigned long long ULL;

int chick[257],pat[257];
char s[1000007],t[1000007];

int main()
{
    ios::sync_with_stdio(false);
    cin>>s>>t;
    CLEAR(chick);
    int n = strlen(s),m = strlen(t);
    if (n >= m)
    {
        CLEAR(pat);
        REP(i,m) ++pat[t[i]];
        int ok = 0;
        REP(i,m)
        {
            ++chick[s[i]];
        }
        REP(i,256)
            if (i!='?' && chick[i]>pat[i]) ++ok;
        int answer = ok==0;
        for (int i = m;i < n;++i)
        {
            --chick[s[i-m]];
            if (s[i-m]!='?' && chick[s[i-m]]==pat[s[i-m]]) --ok;
            ++chick[s[i]];
            if (s[i]!='?' && chick[s[i]]==pat[s[i]]+1) ++ok;
            answer += ok==0;
        }
        cout <<answer << endl;
    }
    else cout << 0 << endl;
    return 0;
}