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
typedef long long int64;
typedef long long ll;
typedef unsigned int UI;
typedef long double LD;
typedef unsigned long long ULL;

int s[1000007];
int w[5007][5007]; //col num
int pq[5007][5007];
int ans[2][5007];

int main()
{
    ios::sync_with_stdio(false);
    int n,m,p;
    cin>>n>>m>>p;
    int maxi = 0;
    REP(i,n)
    {
        cin>>s[i];
        maxi = max(maxi,s[i]);
    }
    CLEAR(pq);
    for (int i = 1;i <= min(maxi,m);++i)
    {
        pq[i][0] = 0;
        pq[i][1] = i%p;
        for (int j = 2;j <= i;++j)
            pq[i][j] = pq[i][j-1]*(long long)(i-j+1)%p;
        for (int j = i+1;j <= maxi;++j)
        {
            pq[i][j] = pq[i][j-1]*(long long)(i-1)%p;
            if (i>1) pq[i][j] = (pq[i][j] + 1ll*i*pq[i-1][j-1])%p;
        }
    }
    for (int i = 1;i <= min(maxi,m);++i)
    {
        for (int j = 0;j <= maxi;++j)
            w[i][j] = 0;
        w[i][0] = 0;
        w[i][1] = m%p;
        for (int j = 2;j <= i;++j)
            w[i][j] = w[i][j-1]*(long long)(m-j+1)%p;
        for (int j = i+1;j <= maxi;++j)
        {
            w[i][j] = w[i][j-1]*(long long)(i-1)%p;
            if (i>1) w[i][j] = (w[i][j] + w[i-1][j-1]*(long long)(m-i+1)%p)%p;
        }
    }
    for (int i = 1;i <= min(m,s[0]);++i)
    {
        ans[0][i] = w[i][s[0]];
    }

    REP(i,n-1)
    {
        int now = i & 1,next = now ^ 1;
        int mnext = min(m,s[i+1]),mnow = min(m,s[i]);
        int common = min(mnext,mnow);
        int sum = 0;
        for (int j = 1;j <= mnow;++j)
            sum = (sum + (long long)ans[now][j])%p;
        for (int j = 1;j <= mnext;++j)
            ans[next][j] = sum*(long long)w[j][s[i+1]]%p;
        for (int j = 1;j <= common;++j)
            ans[next][j] = (ans[next][j] - ans[now][j]*(long long)pq[j][s[i+1]]%p)%p;
    }
    int sum = 0,num = ((n-1)&1);
    int mnow = min(s[n-1],m);
    for (int j = 1;j <= mnow;++j)
        sum = (sum + p + (long long)ans[num][j])%p;
    cout << sum << endl;
    return 0;
}