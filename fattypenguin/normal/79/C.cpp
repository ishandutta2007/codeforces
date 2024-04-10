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

const long double eps = 1e-8;

#define PB push_back
#define MP make_pair

typedef vector<int> VI;
typedef vector<string> VS;
typedef vector<long double> VD;
typedef pair<int,int> PII;
typedef long long LL;
typedef unsigned long long ULL;

int F[100000 + 1024];
char s[100000 + 1024],p[16][16];
int l[16],len,n,m;

int main()
{
    scanf("%s",s);
    len = strlen(s);
    scanf("%d",&n);
    for (int i = 0;i < n;++i)
    {
        scanf("%s",p[i]);
        l[i] = strlen(p[i]);
    }
    F[0] = 0;
    int best = 0,l0 = 0;
    for (int i = 1;i <= len;++i)
    {
        F[i] = F[i-1] + 1;
        for (int j = 0;F[i] && j < n;++j)
        {
            if (F[i] >= l[j])
            {
                bool match = true;
                for (int k = i-l[j];k <= i-1;++k)
                    if (s[k] != p[j][k-(i-1-l[j]+1)])
                    {
                        match = false;
                        break;
                    }
                if (match) F[i] = l[j]-1;
            }
        }
        if (F[i] > best)
        {
            best = F[i];
            l0 = i-F[i];
        }
  //      cout << F[i] << " ";
    }
    cout << best;
    cout << " " << l0;
    cout << endl;
    return 0;
}