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

deque<long long> Q;
int a[2000007], b[2000007];
int where[2000007];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    REP(i, n) scanf("%d", &a[i]);
    for (int i = n; i < 2*n; ++i)
        a[i] = a[i-n];
    FILL(where, -1);
    REP(i, m)
    {
        scanf("%d", &b[i]);
        where[b[i]] = i;
    }
    int cnt = 0, ans = 0 ;
    for (int i = 0; i < 2*n; ++i)
    {
        long long pos = where[a[i]];
        if (-1 == pos)
        {
            Q.clear();
      //      cout << "here\n";
            continue;
        }
        if (Q.size() >= n)
            Q.pop_front();
        if (!Q.size())
            Q.push_back(pos);
        else
        {
            long long bk = Q.back();
            if (bk >= pos)
            {
                long long div = (bk - pos) / m;
                pos = pos + 1ll*(div+1)*m;
            }
            Q.PB(pos);
            while (Q.back() - Q.front() >= m)
                Q.pop_front();
        }
        ans = max(ans, (int)Q.size());
  //      cout << "i = " << i << " , ";
  //      REP(i, Q.size())
  //          cout << Q[i] << " ";
  //      cout << endl;
    }
    cout << ans << endl;
    return 0;
}