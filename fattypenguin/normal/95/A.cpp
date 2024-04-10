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
typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;

string o,oo,now,r;
string f[999];

void toL(string &s)
{
    for (int i = 0;i < s.size();++i)
        if (s[i] >= 'a' && s[i] <= 'z')
            s[i] += 'A' - 'a';
}

bool fb[999][256];

void match(int id,int p)
{
    if (p + f[id].size() > now.size()) return ;
    bool mat = true;
    for (int i = 0;i < f[id].size();++i)
        if (f[id][i] != oo[p+i])
        {
            mat = false;
            break;
        }
    if (!mat) return;
    for (int i = 0;i < f[id].size();++i)
        if (oo[p+i] != r[0])
        {
                now[p+i] = r[0];
        }
        else
        {
            if (r[0] == 'A' && oo[p+i] != 'B' )
                now[p+i] = 'B';
            else if (r[0] == 'A')
                now[p+i] = 'C';
            else
                now[p+i] = 'A';
        }
}

int main()
{
    int n;
    cin >> n;
    for (int i = 0;i < n;++i)
    {
        cin >> f[i];
        toL(f[i]);
    }
    cin >> o >> r;
    now = o;
    oo = o;
    toL(oo);
    toL(now);
    toL(r);
    CLEAR(fb);
    for (int i = 0;i < now.size();++i)
        for (int j = 0;j < n;++j)
            match(j,i);
    for (int i = 0;i < o.size();++i)
        if (o[i] >= 'a' && o[i] <= 'z')
            now[i] += 'a' - 'A';
    cout << now << endl;

    return 0;
}