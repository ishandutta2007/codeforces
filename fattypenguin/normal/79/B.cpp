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

const long double eps = 1e-8;

#define PB push_back
#define MP make_pair

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<long double> VD;
typedef pair<int,int> PII;
typedef long long LL;
typedef unsigned long long ULL;

struct pt
{
    int i,j,id;
    void Rd()
    {
        cin >> i >> j;
    }
    bool operator < (const pt &p) const
    {
        if (i != p.i) return i < p.i;
        return j < p.j;
    }
} Q[1024],B[1024];

int ans[1024];

int main()
{
    int n,m,k,t;
    cin >> n >> m >> k >> t;
    for (int i = 0;i < k;++i)
        B[i].Rd();
    for (int i = 0;i < t;++i)
    {
        Q[i].Rd();
        Q[i].id = i;
    }
    sort(B,B+k);
    sort(Q,Q+t);
    int now = 0,bad = 0;
    for (int i = 0;i < t;++i)
    {
        while (B[now] < Q[i] && now < k)
        {
            ++now;
            ++bad;
        }
        if (now < k && B[now].i == Q[i].i && B[now].j == Q[i].j)
        {
            ans[Q[i].id] = -1;
            continue;
        }
        ans[Q[i].id] = ((Q[i].i-1)*m + Q[i].j - bad)%3;
    }
    for (int i = 0;i < t;++i)
        if (ans[i] == 1)
            cout << "Carrots\n";
        else if (ans[i] == 2)
            cout << "Kiwis\n";
        else if (ans[i] != -1)
            cout << "Grapes\n";
        else
            cout << "Waste\n";
}