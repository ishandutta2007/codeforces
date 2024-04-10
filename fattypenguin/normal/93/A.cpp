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
typedef long long LL;
typedef long double LD;
typedef unsigned long long ULL;

int main()
{
    int n,m,a,b;
    cin >> n >> m >> a >> b;
    int ret = 3;
    if ((a-1)/m == (b-1)/m)
    {
            ret = 1;
    }
    else if ((a-1)/m  + 1 == (b-1)/m)
    {
        ret = 2;
        if ((a-1)%m == 0 && (b%m == 0 || b == n)) --ret;
    }
    else
    {
        if (b%m == 0 || b == n) --ret;
        if ((a-1)%m == 0) --ret;
        if (ret > 2 && ((a-1)%m) == b%m)
            ret = 2;
    }
    cout << ret << endl;
    return 0;
}