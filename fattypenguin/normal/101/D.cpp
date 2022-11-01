#pragma comment(linker, "/STACK:65777216")

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

vector<PII> edge[300000 + 7];
int n;
ll f[300000 + 7];
ll sum[300000 + 7],total[300000 + 7];

bool cmp(const int &a,const int &b)
{
    return total[a]*sum[b] - sum[a]*total[b] > 0;
}

vector<int> child;

void trough(int u,int Fa)
{
    sum[u] = f[u] = 0;
    total[u] = 1;
    TR(it,edge[u])
    {
        if (it->first == Fa) continue;
        trough(it->first,u);
        sum[it->first] += it->second;
        f[it->first] += it->second * total[it->first];
        sum[u] += sum[it->first];
        total[u] += total[it->first];
    }
    child.clear();
    TR(it,edge[u]) if (it->first != Fa) child.PB(it->first);
    sort(child.begin(),child.end(),cmp);
    ll nowsum = 0;
    TR(it,child)
    {
        f[u] += f[*it] + nowsum*total[*it];
        nowsum += 2*sum[*it];
    }
}

int main()
{
    cin >> n;
    REP(i,n) edge[i].clear();
    REP(i,n-1)
    {
        int a,b,c;
        cin >> a >> b >> c;
        --a,--b;
        edge[a].PB(MP(b,c));
        edge[b].PB(MP(a,c));
    }
    trough(0,-1);
   // REP(i,n) cout << "F[" << i << "] = " << f[i] << endl;
    printf("%.10f\n",(double)f[0] / (double)(n-1));
    return 0;
}