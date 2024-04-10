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

int flag[1007];
string s;
int total[1007];
int ans[1007];
int sz[257];

int main()
{
    cin>>s;
    int n = s.size();
    CLEAR(flag);
    CLEAR(sz);
    CLEAR(ans);
    CLEAR(total);
    flag[0] = 1;
    total[0] = 1;
    int cnt = 1;
    bool invalid = false;
    for (int i = 2;i <= n;++i)
        if (!flag[i])
        {
            if (i <= n && i * 2 > n)
            {
                total[i-1] = 1;
                ++cnt;
            }
            for (int j = i+i;j <= n;j += i)
                flag[j] = true;
        }
    REP(i,n) ++sz[s[i]];
    vector<PII> v;
    REP(i,256)
        if (sz[i]) v.PB(MP(-sz[i],i));
    SORT(v);
    if (-v[0].first >= n-cnt)
    {
        cout<<"YES"<<endl;
        REP(i,n) if(!total[i]) ans[i] = v[0].second;
        v[0].first += n-cnt;
        REP(i,n)
            if (!ans[i])
            {
                TR(it,v)
                {
                    if (it->first)
                    {
                        ++it->first;
                        ans[i] = it->second;
                        break;
                    }
                }
            }
        REP(i,n) printf("%c",ans[i]);
        cout<<endl;
    }
    else cout<<"NO"<<endl;
    return 0;
    }