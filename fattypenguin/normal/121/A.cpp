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
    if (dep > 10) return;
    gao(dep+1,now*10+4);
    gao(dep+1,now*10+7);
}

int main()
{
    gao(0,0);
    SORT(lucky);
  //  cout<<lucky.back()<<endl;
    int l,r;
    long long ans = 0;
    cin>>l>>r;
    REP(i,lucky.size())
    {
        long long  x = lucky[i];
        {
            ll prev = 1;
            if (i) prev = lucky[i-1]+1;
            long long t = min((ll)r,x)-max(prev,(ll)l)+1;
            if (t < 0) t = 0;
            ans = ans + x * t;
        }
    }
    cout<<ans<<endl;
    return 0;
}