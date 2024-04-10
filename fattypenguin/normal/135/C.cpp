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
typedef long long ll;
typedef long double LD;
typedef unsigned long long ULL;

int a,b,c;
char s[100007];

int main()
{
    int n;
    a = b = c = 0;
    ios::sync_with_stdio(false);
   // cin>>n;
    cin>>s;
    n = strlen(s);
    int ans = 0;
    REP(i,n)
    {
        if (s[i]=='1') ++b;
        if (s[i]=='0') ++a;
        if (s[i]=='?') ++c;
    }
    if (n & 1)
    {
        int st = (n-1)/2;
        if (b <= st)
            cout << "00\n";
        if (b+c>=st+1 && a+c>=st)
        {
            if (s[n-1]=='1'||(s[n-1]=='?' && a+c>st))
                cout << "01\n";
            if (s[n-1]=='0'||(s[n-1]=='?' && b+c>st+1))
                cout << "10\n";
        }
        if (a < st)
            cout << "11\n";

    }
    else
    {
        if (b<a+c)
            cout << "00\n";
        if (a+c>=n/2&&b+c>=n/2)
        {
            if (s[n-1]=='1'||(s[n-1]=='?' && a+c>n/2))
                cout << "01\n";
            if (s[n-1]=='0'||(s[n-1]=='?' && b+c>n/2))
                cout << "10\n";
        }
        if (a<b+c)
            cout << "11\n";
    }
    return 0;
}