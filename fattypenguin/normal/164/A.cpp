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

VI e[100007], re[100007];
int ty[100007];
bool v[100007], rv[100007];

int main()
{
    ios::sync_with_stdio(false);
    int n, m;
    cin >> n >> m;
    REP(i, n) cin >> ty[i];
    REP(i, m)
    {
        int x, y;
        cin >> x >> y;
        --x , --y;
        if (ty[y] != 1)
            {
                e[x].PB(y);
                re[y].PB(x);
            }
    }
    queue<int> Q;
    CLEAR(v), CLEAR(rv);
    REP(i, n) if (ty[i] == 1)
    {
        v[i] = 1;
        Q.push(i);
    }
    while (Q.size())
    {
        int now = Q.front();
        Q.pop();
        TR(it, e[now])
            if (!v[*it])
            {
                v[*it] = true;
                Q.push(*it);
            }
    }
    REP(i, n) if (ty[i] == 2)
    {
        rv[i] = 1;
        Q.push(i);
    }
    while (Q.size())
    {
        int now = Q.front();
        Q.pop();
        TR(it, re[now])
            if (!rv[*it])
            {
                rv[*it] = true;
                Q.push(*it);
            }
    }
    REP(i, n)
        if (v[i] && rv[i])
            cout << 1 << endl;
        else  cout << 0 << endl;

    return 0;
}