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

map<int,int> Count,ranking,need;
int peop[100000*3 + 1024];
int ans[100000*3 + 1024];

int main()
{
    int n,a,b;
    cin >> n >> a >> b;
    for (int i = 0;i < n;++i)
    {
        int x;
        scanf("%d",&x);
        peop[i] = x;
        if (Count.find(-x) == Count.end())
            Count[-x] = 1;
        else
            Count[-x]++;
    }
    if (a == b)
    {
        for (int i = 0;i < a;++i)
            printf("1 ");
        for (int i = 0;i < b-1;++i)
            printf("2 ");
        printf("2\n");
        return 0;
    }
    int total = 0,nowm = 0,enough = -1;
    for (map<int,int>::iterator i = Count.begin();i != Count.end();++i)
    {
        ranking[-i->first] = ++nowm;
        total += i->second;
        need[-i->first] = 0;
        if (total < min(a,b))
        {
            need[-i->first] = i->second;
        }
        if (total >= min(a,b) && enough == -1)
        {
            need[-i->first] = min(a,b) - (total-(i->second));
            enough = nowm;
        }
    }
    int nowo = 0;

    if (a > b)
    {
        for (int i = n-1;i >= 0;--i)
            if (nowo < b && need[peop[i]])
            {
                ++nowo;
                ans[i] = 2;
                --need[peop[i]];
            } else ans[i] = 1;
    }
    else
    {
        for (int i = 0;i< n;++i)
            if (nowo < b && need[peop[i]])
            {
                ++nowo;
                ans[i] = 1;
                --need[peop[i]];
            } else ans[i] = 2;
    }
    for (int i = 0;i < n;++i)
    {
        printf("%d",ans[i]);
        if (i == n-1) cout << endl; else printf(" ");
    }

    return 0;
}