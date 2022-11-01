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

int stand[1<<18];
double f[1 << 18];
double mat[23][23];
int bitCount[1<<18];

int main()
{
    REP(i,18) stand[1<<i] = i;
    int n;
    cin >> n;
    REP(i,n) REP(j,n) cin >> mat[i][j];
    CLEAR(f);
    REP(i,(1<<n))
    {
        bitCount[i]=0;
        for (int j = i;j;j-=(j&-j)) bitCount[i]++;
    }
    f[(1 << n)-1] = 1.0;
    for (int i = (1<<n)-1;i;--i)
    {
        int total = bitCount[i];
        if (total<=1) continue;
        double meet = total * (total-1) / 2;
        meet = 1/meet;
        for (int j=i;j;j-=(j&-j))
            for (int k=i;k;k-=(k&-k))
            {
                int fish1 = stand[j&-j],
                    fish2 = stand[k&-k];
                if (fish1 == fish2) continue;
                f[i^(k&-k)] += meet * mat[fish1][fish2] * f[i];
            }
    }
    REP(i,n)
    {
        if (i) cout<<" ";
        printf("%.10f",f[1<<i]);
    }
    cout << endl;

}