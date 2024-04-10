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

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<long double> VD;
typedef pair<int,int> PII;
typedef long long LL;
typedef unsigned long long ULL;



int main()
{
    LL a,b;
    cin >> a >> b;
    LL low = 0,ans = 0;
    while (low < a) low = low*10 + 9;
    ans = a*(low-a);
    while (low/2 <= b)
    {
        LL p = max(a,max(low/2,low/2+1));
        ans = max(ans,p*(low-p));
        low = low*10 + 9;
    }
    if (b*10 <= low) ans = max(ans,b*(low/10-b));
    else  ans = max(ans,b*(low-b));
    cout << ans << endl;
    return 0;
}