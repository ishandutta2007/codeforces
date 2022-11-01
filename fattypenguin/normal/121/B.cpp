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
typedef unsigned int UI;
typedef long double LD;
typedef unsigned long long ULL;

vector<ll> lucky;

void gao(int dep,long long now)
{
    if (now) lucky.PB(now);
    if (dep > 10) return;
    gao(dep+1,now*10+4);
    gao(dep+1,now*10+7);
}

int n,k;
char s[100007];
vector<int> brk;

int main()
{
    cin>>n>>k;
    scanf("%s",s);
    brk.clear();
    int final = -1;
    REP(i,n-1)
    {
        if (!k) break;
        if (s[i]=='4'&&s[i+1]=='7')
        {
            bool normal = true;
            if (!(i&1) && i+2<n && s[i+2]=='7')
            {
                if (k&1) s[i+1] = '4';
                break;
            }
            if ((i&1) && i && s[i-1] == '4')
            {
                if (k&1) s[i] = '7';
                break;
            }
            if (normal)
            {
                if (!(i&1)) s[i+1]='4'; else s[i] = '7';
                --k; ++i;
            }

        }
    }
    cout<<s<<endl;

    return 0;
}