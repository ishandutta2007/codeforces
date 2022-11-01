#include <iostream>
#include <string>
#include <string.h>
#include <algorithm>
#include <map>

using namespace std;

typedef map<int,int> MII;

int BIT[200007],stand[200007];
int n,m,all;
MII has;

struct station
{
    int s,t;
    bool operator < (const station &p) const {return t < p.t;}
} s[200007];

const int MOD = 1000000007;

void ins(int where,int value)
{
    ++where;
    while (where <= all+1)
    {
        BIT[where] += value;
        BIT[where] %= MOD;
        where += where & -where;
    }
}

int quary(int where)
{
    ++where;
    int ret = 0;
    while (where)
    {
        ret += BIT[where];
        ret %= MOD;
        where -= where & -where;
    }
    return ret;
}

int main()
{
    cin >> n >> m;
    has.clear();
    memset(BIT,0,sizeof(BIT));
    for (int i = 0;i < m;++i)
    {
        cin >> s[i].s >> s[i].t;
        has[s[i].s] = 1;
        has[s[i].t] = 1;
    }
    has[0] = 1; has[n] = 1;
    all = 0;
    for (MII::iterator it = has.begin();it != has.end();++it)
    {
        it->second = all++;
        stand[it->second] = it->first;
    }
    for (int i = 0;i < m;++i)
    {
        s[i].s = has[s[i].s];
        s[i].t = has[s[i].t];
    }
    ins(0,1);
    sort(s,s+m);
    for (int i = 0;i < m;++i)
    {
        int contribute = quary(s[i].t-1) - quary(s[i].s-1);
        ins(s[i].t,((contribute % MOD) + MOD) % MOD);
    }
    int ans = quary(has[n]) - quary(has[n]-1);
    cout << (ans % MOD + MOD) % MOD << endl;
    return 0;
}