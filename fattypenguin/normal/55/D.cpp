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

int where[1 << 9],stand[50],position[2521];
ll f[21][10][50][2520];
ll Lcm[10][2521];
ll power[20];
int total;

ll gcd(ll a,ll b) {return !b ? a : gcd(b,a%b);}
ll lcm(ll a,ll b) {return a * b / gcd(a,b);}

MII has;

void initalize()
{
    CLEAR(Lcm);
    for (int i = 1;i <= 2520;++i)
        for (int j = 1;j < 10;++j) Lcm[j][i] = lcm(i,j);
    power[0] = 1;
    for (int i = 1;i < 20;++i) power[i] = power[i-1] * 10;
    has.clear();
    for (int i = 0;i < (1 << 9);++i)
    {
        ll res = 1;
        for (int j = 0;j < 9;++j)
            if (i & (1 << j)) res = lcm(res,(j+1));
        where[i] = res;
        has[res] = 1;
    }
    total = 0;
    for (MII::iterator it = has.begin();it != has.end();it++)
    {
        it->second = total++;
        position[it->first] = it->second;
        stand[it->second] = it->first;
    }
    CLEAR(f);
    //cout << stand[total-1] << endl;
    REP(i,total)
    {
        //cout << "stand[i] = " << stand[i] << endl;
        for (int j = 0;j < 2520;j += stand[i])
            f[0][0][i][j] = 1;
    }
    for (int i = 1;i < 21;++i)
        for (int k = total-1;k >= 0;--k)
            for (int j = 0;j < 10;++j)
                for (int r = 0;r < 2520;++r)
                {
                    if (!j)
                    {
                        for (int s = 0;s < 10;++s)
                            f[i][j][k][r] += f[i-1][s][k][r];
                        continue;
                    }
                    int next = position[Lcm[j][stand[k]]];
                 //   if (next < k) cout << "k = " << k << " stand[k] = " << stand[k] << " j = " << j << " " << " Lcm = " << Lcm[j][stand[k]] << " stand[next] = " << stand[next] << endl;
                    ll mod = ((r - j*power[i-1]) % 2520 + 2520) % 2520;
                    f[i][j][k][r] = f[i][0][next][mod];
                }
}

ll eval(int i,int len,int k,ll mod,char *s,bool bound)
{
    //cout << "i = " << i << " len = " << len << " k = " << k << " stand[k] = " << stand[k] << " mod = " << mod << endl;
    if (i == len)
    {
        if (!bound && (mod % stand[k]) == 0)
            return 1;
        return 0;
    }
    int highest = s[i] - '0';
    ll ret = 0;
    for (int ii = 0;ii <= highest;++ii)
    {
        if (ii < highest)
        {
            ret += f[len-i][ii][k][mod];
            continue;
        }
        int next = ii ? position[Lcm[ii][stand[k]]] : k;
        ll modk = ((mod - ii*power[len-i-1]) % 2520 + 2520) % 2520;
        ret += eval(i+1,len,next,modk,s,bound);
    }
    return ret;
}

char s[255];
int len;

int main()
{
    initalize();
    int Cases;
    cin >> Cases;
    while (Cases--)
    {
        ll l,r;
        cin >> l >> r;
        sprintf(s,"%I64d",l);
        //cout << s << endl;
        ll vLeft = eval(0,strlen(s),0,0,s,true);
        sprintf(s,"%I64d",r);
       // cout << s << endl;
        ll vRight = eval(0,strlen(s),0,0,s,false);
        //if (r > 1000000000000ll) cout << "r = " << s << endl;
        cout << vRight - vLeft << endl;

    }
    return 0;
}