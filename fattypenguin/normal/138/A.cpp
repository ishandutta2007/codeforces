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
#include <cassert>
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

string s[4];
int n,k;
bool yy[257];

bool ok(string &a,string &b)
{
    int n = a.size(),m = b.size();
    int s = -1,c = 0;
    for (int i = n-1;i>=0;--i)
    {
        if (yy[a[i]])
            ++c;
        if (c == k)
        {
            s = i;
            break;
        }
    }
    if (-1 == s) return false;
    int ss = -1,cc = 0;
    for (int i = m-1;i>=0;--i)
    {
        if (yy[b[i]])
            ++cc;
        if (cc == k)
        {
            ss = i;
            break;
        }
    }
    if (-1 == ss) return false;
    if (n-s!=m-ss) return false;
    REP(i,n-s) if (a[s+i]!=b[ss+i]) return false;
    return true;
}

int main()
{
    ios::sync_with_stdio(false);
    CLEAR(yy);
    yy['a'] = yy['e'] = yy['i'] = yy['o'] = yy['u'] = true;
    cin>>n>>k;
    int now = 7;
    REP(i,n)
    {
        REP(j,4) cin>>s[j];
        int t = 0;
        if (ok(s[0],s[1]) && ok(s[2],s[3])) t ^= 1;
        if (ok(s[0],s[2]) && ok(s[1],s[3])) t ^= 2;
        if (ok(s[0],s[3]) && ok(s[1],s[2])) t ^= 4;
        now &= t;
    }
    if (now==7)
        cout<<"aaaa\n";
    else if (now == 0)
        cout << "NO\n";
    else if (now == 1)
        cout << "aabb\n";
    else if (now == 2)
        cout << "abab\n";
    else if (now == 4)
        cout << "abba\n";
    else assert(false);
    return 0;
}