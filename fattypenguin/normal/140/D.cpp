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

priority_queue<PII> Q;

MII m;

struct PIII
{
    int a,b,c;
    PIII(int a,int b,int c)
    {
        this->a = a;
        this->b = b;
        this->c = c;
    }
    PIII() {};
};

vector<vector<int> > fr;
vector<int> aa;

pair<int,int> f[2][730][730];
int s[1000];

void clear(int x )
{
    REP(i,721)
    {
        for (int j = 0;j <= i;++j) f[x][i][j] = MP(0,0);
        for (int j = i+1;j < 721;++j) f[x][i][j] = MP(0,0x7f7f7f7f);
    }
}

int abs(int x) {return x > 0 ?x : -x;}

int main()
{
    int n;
    ios::sync_with_stdio(false);
    cin>>n;
    REP(i,n) cin>>s[i];
    sort(s,s+n);
    clear(0);
    f[0][0][0] = MP(0,0);
    REP(i,n)
    {
        clear((i&1)^1);
        int now = i&1,next = now^1;
        for (int j = 0;j <= 710;++j)
        {
            for (int k = 0;k <= j;++k)
            {
                if (j) f[now][j][k] = min(f[now][j][k],f[now][j-1][k]);
                f[next][j][k] = min(f[next][j][k],f[now][j][k]);
                if (k+s[i]<=j)
                    f[next][j][k+s[i]] = min(f[next][j][k+s[i]],MP(f[now][j][k].first-1,f[now][j][k].second+abs(j+10-360)));
            }
        }
    }
    PII answer = MP(0,0);
    int now = n&1;
        for (int j = 0;j <= 710;++j)
            for (int k = 0;k <= j;++k)
                answer = min(answer,f[now][j][k]);
    cout << -answer.first << " " << answer.second << endl;
    return 0;
}