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

int C[1007][1007];

int main()
{
    REP(i,1007) C[i][0] = 1;
    int n,m,k;
    cin>>n>>m>>k;
    --n,--m;
    int f = max(n,m);
    for (int i = 1;i <= f;++i)
        for (int j = 1;j <= i;++j)
            C[i][j] = (C[i-1][j]+C[i-1][j-1])%1000000007;
    int ans = 0;
    if (n>=2*k && m>=2*k) ans = C[n][2*k]*1ll*C[m][2*k]%1000000007;
    cout<<ans<<endl;
    return 0;
}