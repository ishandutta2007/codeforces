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

int n, a[100007], b[100007];
int where[100007];

int main()
{
    cin >> n;
    REP(i, n) scanf("%d", &a[i]);
    REP(i, n) scanf("%d", &b[i]);
    REP(i, n) --a[i], --b[i];
    REP(i, n) where[a[i]] = i;
    multiset<int> l, r;
    REP(i, n) l.insert(where[b[i]]-i);
    int ld, rd;
    ld = 0;
    rd = n;
    REP(i, n)
    {
        int ans = 0x7f7f7f7f;
        if (l.size())
        {
            //x+ld close to 0
            multiset<int>::iterator it = l.lower_bound(-ld);
            if (it != l.end())
                ans = min(ans, abs(*it+ld));
            if (it != l.begin())
            {
                --it;
                ans = min(ans, abs(*it+ld));
            }
        }

        if (r.size())
        {
            //x-rd close to 0
            multiset<int>::iterator it = r.lower_bound(rd);
            if (it != r.end())
                ans = min(ans, abs(*it-rd));
            if (it != r.begin())
            {
                --it;
                ans = min(ans, abs(*it-rd));
            }
        }

        l.erase(l.find(where[b[i]]-i));
        r.insert(where[b[i]]-i);
        ++ld;
        --rd;

        printf("%d\n", ans);
    }
	return 0;
}