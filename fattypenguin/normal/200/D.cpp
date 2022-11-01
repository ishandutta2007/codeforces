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

char buff[1000007];

map<VS, int> fun;
map<string, string> var;
set<int> can;

vector<string> scan()
{
    gets(buff);
    int length = strlen(buff);
    int i = 0;
    while (' ' == buff[i]) ++i;
    i += 4;
    while (' ' == buff[i]) ++i;
    string func;
    while (buff[i] != ' ' && buff[i] != '(')
    {
        func += buff[i];
        ++i;
    }
    while (buff[i] == ' ') ++i;
    VS ret;
    ret.PB(func);
    for (++i ; i < length;++i)
    {
        string tmp;
        while (buff[i] != ',' && buff[i] != ')')
        {
            if (buff[i] != ' ')
                tmp += buff[i];
            ++i;
        }
        ret.PB(tmp);
        if (buff[i] == ')') break;
    }
    return ret;
}

vector<string> scan1()
{
    gets(buff);
    int length = strlen(buff);
    int i = 0;
    while (' ' == buff[i]) ++i;
    string func;
    while (buff[i] != ' ' && buff[i] != '(')
    {
        func += buff[i];
        ++i;
    }
    while (buff[i] == ' ') ++i;
    VS ret;
    ret.PB(func);
    for (++i ; i < length;++i)
    {
        string tmp;
        while (buff[i] != ',' && buff[i] != ')')
        {
            if (buff[i] != ' ')
                tmp += buff[i];
            ++i;
        }
        ret.PB(tmp);
        if (buff[i] == ')') break;
    }
    return ret;
}

void dfs(int depth, VS &idx)
{
    if (depth == idx.size())
    {
        if (fun.find(idx) != fun.end())
            can.insert(fun[idx]);
        return;
    }

    dfs(depth+1, idx);
    if ("T" == idx[depth]) return;
    string tmp = idx[depth];
    idx[depth] = "T";
    dfs(depth+1, idx);
    idx[depth] = tmp;

}

int main()
{
    int n;
    cin >> n;
    gets(buff);
    REP(i, n)
        fun[scan()] = i;
    int m;
    cin >> m;
    REP(i, m)
    {
        string x, y;
        cin >> x >> y;
        var[y] = x;
    }
    int k;
    cin >> k;
    gets(buff);
    REP(i, k)
    {
        VS idx = scan1();
        for (int i = 1; i < idx.size(); ++i)
            idx[i] = var[idx[i]];
     //   TR(it, idx) cout << *it << " ";
     //   cout << endl;
        can.clear();
        dfs(1, idx);
        cout << can.size() << endl;
    }
    return 0;
}