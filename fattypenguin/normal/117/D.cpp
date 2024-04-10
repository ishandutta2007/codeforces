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

ll n,q,mod;

ll calc(ll first,ll delta,ll l,ll r,ll u,ll v,ll n)
{
 //   cout << first << " " << delta << " " << l << " " << r << " " <<u << " " << v << " " << n << endl;
    if (1 == l && n <= r)
    {
     //   cout << first << " " << delta << " " << l << " " << r << " " <<u << " " << v << " " << n << endl;
        ll ret = 0;
        /*
        ll dist = u-first;
        dist /= delta;
        if (dist < 0) dist = 0;
        if (first+delta*dist < u) ++dist;
        ll rest = n - dist;
        first = (first + dist * delta) % mod;
        dist = v - first;
        dist /= delta;
        if (v < first) return 0;
        if (!rest) return 0;
        rest = min(rest,dist+1);
        ll mul;
        if (rest&1ll) mul = rest%mod*((rest-1)/2%mod)%mod; else mul = rest/2%mod*((rest-1)%mod)%mod;
        if (rest > 0) ret = (rest%mod*(first%mod)%mod + mul%mod * (delta%mod)%mod)%mod;
        */
        if (v < first) return 0;
        ll last = first + delta*(n-1);
        if (u > last) return 0;
        ll beg = u - first;
        beg /= delta;
        if (beg < 0) beg = 0;
        if (first + delta * beg < u) ++beg;
        beg = delta * beg + first;
        last = v - first;
        last /= delta;
        last = min(last,n-1);
        last = last * delta + first;
        ll cnt = (last - beg)/delta + 1;
        return ((last%(2*mod)+beg%(2*mod))*(cnt%(2*mod))/2)%mod;
    }
    ll mid = (n+1)/2;
    ll ret = 0;
    if (l <= mid) ret = calc(first,delta*2,l,min(mid,r),u,v,(n+1)/2);
    if (r > mid) ret += calc(first+delta,delta*2,max(l,mid+1)-mid,r-mid,u,v,n/2);
    return ret % mod;
}

int main()
{
    cin >> n >> q >> mod;
    while (q--)
    {
        ll l,r,u,v;
        cin >> l >> r >> u >> v;
        cout << calc(1,1,l,r,u,v,n) << endl;
    }
    return 0;
}