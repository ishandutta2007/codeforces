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

char a[1000007],b[1000007];
int pw[1000007],pw2[1000007];
int arprefix[1000007],arsuffix[1000007],bsuffix[1000007],bprefix[1000007];
int arprefix2[1000007],arsuffix2[1000007],bsuffix2[1000007],bprefix2[1000007];


const ll MOD = 1000000007ll,MOD2 =238782737ll ;
const int MODD = 100007;

vector<pair<pair<int,int>,int> > has[MODD];
int where[MODD],value[1000007];

int last = 0;

void update(pair<int,int> key,int Value)
{
    ll gao = (key.first*1293898ll + key.second * 23871845)%MODD;
    int siz = has[gao].size();
    for (int i = 0;i < siz;++i)
        if (has[gao][i].first==key)
        {
            value[has[gao][i].second]=Value;
            return;
        }
    has[gao].PB(MP(key,last++));
    value[last-1]=Value;
}

int fin(pair<int,int> key)
{
    ll gao = (key.first*1293898ll + key.second * 23871845)%MODD;
    int siz = has[gao].size();
    for (int i = 0;i < siz;++i)
        if (has[gao][i].first==key)
        {
            return value[has[gao][i].second];
        }
    return -1;
}

int main()
{
    gets(a);
    gets(b);
    int len = strlen(a);
    if (len!=strlen(b))
    {
        cout<<"-1 -1\n";
        return 0;
    }
    pw[0] = pw2[0] = 1;
    for (int i=1;i<=len+2;++i) { pw[i] = pw[i-1] * 127ll % MOD; pw2[i] = pw2[i-1]*127ll%MOD2; }
    bsuffix[len] = 0;
    for (int i = len-1;i >= 0;--i) bsuffix[i] = (bsuffix[i+1] + (ll)b[i]*pw[len-1-i])%MOD;
    bsuffix2[len] = 0;
    for (int i = len-1;i >= 0;--i) bsuffix2[i] = (bsuffix2[i+1] + (ll)b[i]*pw2[len-1-i])%MOD2;
    arprefix[0] = a[0];
    for (int i = 1;i < len;++i) arprefix[i] = (arprefix[i-1] + (ll)a[i]*pw[i])%MOD;
    arprefix2[0] = a[0];
    for (int i = 1;i < len;++i) arprefix2[i] = (arprefix2[i-1] + (ll)a[i]*pw2[i])%MOD2;
    bprefix[0] = b[0];
    for (int i = 1;i < len;++i) bprefix[i] = (bprefix[i-1]*127ll + b[i])%MOD;
    bprefix2[0] = b[0];
    for (int i = 1;i < len;++i) bprefix2[i] = (bprefix2[i-1]*127ll + b[i])%MOD2;
    arsuffix[len] = 0;
    for (int i = len-1;i>=0;--i) arsuffix[i] = (arsuffix[i+1]*127ll + a[i]) % MOD;
    arsuffix2[len] = 0;
    for (int i = len-1;i>=0;--i) arsuffix2[i] = (arsuffix2[i+1]*127ll + a[i]) % MOD2;
    int aa,bb;
    aa=bb=-1;
    int delta,delta2;
    delta = delta2 = 0;
    update(MP(arsuffix[len-1],arsuffix2[len-1]),len-1);
  //  cout<<arprefix[11]<<" " <<bsuffix[len-1-11]<<endl;
    for (int i = len-2;i>=0;--i)
    {
        if (arprefix[i]==bsuffix[len-1-i] && arprefix2[i]==bsuffix2[len-1-i])
        {
      //  cout << arprefix2[i]<<" " << bsuffix2[len-1-i]<<endl;
            int now = (bprefix[len-2-i] - (ll)delta + 10ll*MOD) % MOD;
            int now2 = (bprefix2[len-2-i] - (ll)delta2 + 10ll*MOD2) % MOD2;
            int rst = fin(MP(now,now2));
            if (rst!=-1)
            {
                aa=i,bb=rst;
                break;
            }
        }
        delta = (delta + (ll)a[i]*pw[len-1-i])%MOD;
        int in = (arsuffix[i] - (ll)delta + 10ll*MOD)%MOD;
        delta2 = (delta2 + (ll)a[i]*pw2[len-1-i])%MOD2;
        int in2 = (arsuffix2[i] - (ll)delta2 + 10ll*MOD2)%MOD2;
        update(MP(in,in2),i);
    }
    cout<<aa<<" "<<bb<<endl;


    return 0;
}