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

bool u(char x) {return x>='A'&&x<='Z';}

ll c[107][107];

int main()
{
    ll n,m,t,as;
    REP(i,107) c[i][0]=1;
    for (int i = 1;i < 107;++i)
        for (int j = 1;j <= i;++j)
            c[i][j] = c[i-1][j] + c[i-1][j-1];
    cin>>n>>m>>t;
    as=0;
    for (int a = 4;a <= n;++a)
    {
        int x = a,y = t-a;
        if (y >= 1 && y <= m)
            as += c[n][x] * c[m][y];
    }
    cout<<as<<endl;
    return 0;
}