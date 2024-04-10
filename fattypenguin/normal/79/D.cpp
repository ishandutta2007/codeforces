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
typedef long long ll;
typedef long double LD;
typedef unsigned long long ULL;

int k,l,n,b[10007],L[107],R[107];
int dis[23][23];

int dist[100007];
ll f[1 << 20];
int bitCount[1 << 20];
int where[1 << 20];
queue<int> Q;

int main()
{
    REP(i,20) where[1 << i] = i;
    REP(i,(1<<20))
    {
        bitCount[i] = 0;
        for (int j = i;j;j-=(j&-j))
            ++bitCount[i];
    }
    cin >> n >> k >> l;
    REP(i,k)
    {
        int aa;
        cin >> aa;
        b[i*2] = aa-1;
        b[i*2+1] = aa;
    }
    sort(b,b+k);
    REP(i,l)
    {
        cin >> L[i];
    }
    REP(i,2*k)
    {
        while (!Q.empty()) Q.pop();
        REP(j,n+1) dist[j] = 0x7f7f7f7f;
        dist[b[i]] = 0;
        Q.push(b[i]);
        while (!Q.empty())
        {
            int now = Q.front();
            Q.pop();
            for (int j = 0;j < l;++j)
            {
                if (now-L[j] >= 0)
                {
                    if (dist[now-L[j]] > dist[now] + 1)
                    {
                        Q.push(now-L[j]);
                        dist[now-L[j]] = dist[now] + 1;
                    }
                }
                if (now+L[j] <= n)
                {
                    if (dist[now+L[j]] > dist[now] + 1)
                    {
                        Q.push(now+L[j]);
                        dist[now+L[j]] = dist[now] + 1;
                    }
                }
            }
        }
        for (int j = 0;j < 2*k;++j)
            dis[i][j] = dist[b[j]];
    }
//    REP(i,2*k) { REP(j,2*k) cout << dis[i][j] << " "; cout << endl;}
    FILL(f,0x7f);
    k *= 2;
    f[(1 << k)-1] = 0;
    for (int i = (1<<k)-1;i;--i)
    {
        if (bitCount[i]&1) continue;
        int head = i & -i;
        for (int j = i-head;j;j-=(j&-j))
        {
            int first = where[head],
                second = where[j&-j],
                next = i-head-(j&-j);
            f[next] = min(f[next],f[i] + dis[first][second]);
        }
    }
    if (f[0] >= 0x7f7f7f7f) f[0] = -1;
    cout << f[0] << endl;
    return 0;
}