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
typedef unsigned int UI;
typedef long double LD;
typedef unsigned long long ULL;

vector<ll> lucky;

void gao(int dep,long long now)
{
    if (now) lucky.PB(now);
    if (dep > 11) return;
    gao(dep+1,now*10+4);
    gao(dep+1,now*10+7);
}

int n,k;
char s[100007];
long long fac[14];
int us[14],stand[14];

bool isLucky(long long x)
{
    for (;x;x/=10)
    {
        if (x%10!=4&&x%10!=7) return false;
    }
    return true;
}

bool use[14];
int res[14];

void gao(int dep,int n,int k)
{
    if (dep >= n)
        return;
    REP(i,n)
        if (!use[i])
        {
            if (k > fac[n-1-dep])
            {
                k -= fac[n-1-dep];
                continue;
            }
            use[i] = true;
            res[dep] = us[i];
            gao(dep+1,n,k);
        }

}

int main()
{
    gao(0,0);
    SORT(lucky);
    int n,k;
    long long ans = 0;
    cin>>n>>k;
    fac[0] = 1;
    for (int i = 1;i <= 13;++i) fac[i] = fac[i-1]*i;
    CLEAR(use);
    if (n < 13)
    {
        if (fac[n]<k)
        {
            cout<<-1<<endl;
            return 0;
        }
        REP(i,n) us[i] = i+1;
        gao(0,n,k);
        REP(i,n) if (isLucky(i+1)&&isLucky(res[i])) ++ans;
        //REP(i,n) cout<<res[i]<<" ";
        //cout<<endl;
        cout<<ans<<endl;
        return 0;
    }
    TR(it,lucky)
        if (*it <= n-13)
            ++ans;
        else break;
    for (int i = n-12;i <= n;++i)
        us[i-(n-12)] = i;
    gao(0,13,k);
    REP(i,13) if (isLucky(us[i]) && isLucky(res[i])) ++ans;
    cout<<ans << endl;
    return 0;
}