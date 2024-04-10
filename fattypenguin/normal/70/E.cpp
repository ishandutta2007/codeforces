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

int f[207][207],best[207],wherebest[207];
int father[207],N,K,W[207],d[207][207],where[207];
VI temp[207],edge[207];

void init_tree(int u,int Fa)
{
    father[u] = Fa;
    if (Fa != -1 && temp[u].size() <= 1) return;
    TR(it,temp[u])
        if (*it != Fa)
        {
            edge[u].PB(*it);
            init_tree(*it,u);
        }
}

void calc(int u)
{
    TR(it,edge[u]) calc(*it);
    best[u] = 0x7f7f7f7f;
    REP(i,N)
    {
        f[u][i] = W[d[u][i]] + K;
        TR(it,edge[u])
            f[u][i] += min(f[*it][i]-K,best[*it]);
        if (f[u][i] < best[u])
        {
            best[u] = f[u][i];
            wherebest[u] = i;
        }
    }
}

void output(int u,int from)
{
    where[u] = from;
    int i = from;
    TR(it,edge[u])
        if (f[*it][i]-K < best[*it])
            output(*it,i);
        else output(*it,wherebest[*it]);
}

queue<int> Q;
void calc_dist(int u,int d[])
{
    while (!Q.empty()) Q.pop();
    REP(i,N) d[i] = 0x7f7f7f7f;
    d[u] = 0;
    Q.push(u);
    while (!Q.empty())
    {
        int now = Q.front();
        Q.pop();
        TR(it,temp[now])
            if (d[*it] > d[now] + 1)
            {
                d[*it] = d[now] + 1;
                Q.push(*it);
            }
    }
}

int main()
{
    cin >> N >> K;
    W[0] = 0;
    REP(i,N-1) cin >> W[i+1];
    REP(i,N-1)
    {
        int a,b;
        cin >> a >> b;
        --a,--b;
        temp[a].PB(b);
        temp[b].PB(a);
    }
    init_tree(0,-1);
    REP(i,N) calc_dist(i,d[i]);
    calc(0);
    int begin = 0;
    REP(i,N)
        if (f[0][begin] > f[0][i]) begin = i;
    output(0,begin);
    cout << f[0][begin] << endl;
    REP(i,N)
    {
        if (i) cout << " ";
        cout << where[i] + 1;
    }
    cout << endl;
    return 0;
}