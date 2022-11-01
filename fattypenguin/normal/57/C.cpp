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
#define mod 1000000007

ll fac[200007],dfac[200007];
ll exp(ll a,ll b){
    ll ret=1;
    while (b){
        if ((b&1)==1) ret=(ret*a)%mod;
        a=(a*a)%mod;
        b>>=1;
    }
    return ret;
}

void init_fac(){
    fac[0]=1;
    for (int i=1;i<=200007;i++) fac[i]=(fac[i-1]*i)%mod;
    for (int i=0;i<=200007;i++) dfac[i]=exp(fac[i],mod-2);
}

inline ll c(int n,int m){
    return ((fac[n]*dfac[n-m])%mod*dfac[m])%mod;
}

int main()
{
    init_fac();
    ll ret = 0,part = 0;
    int n;
    cin >> n;
    for (int i = 1;i < n;++i)
    {
        if (i>1)
        {
            int rest = n-1-i;
            ret = (ret + c(i+rest,rest)*c(n,i)%mod)%mod;
        }
        else ret += c(n,1)*(n-1)%mod;
    }
    cout << (((ret+1-n)+ret+1)+mod)%mod << endl;
    return 0;
}