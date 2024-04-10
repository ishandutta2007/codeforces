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

char s[9999];
int ss[9999];

int main()
{
    int n;
    gets(s);
    n = strlen(s);
    int z = 0,ok = s[0];
    for (int i = 0;i < 8;++i)
    {
        z = z + ((ok&1)<<(7-i));
        ok>>=1;
    }
    ss[0]=(-z+256*3)%256;
    cout<<ss[0]<<endl;
    for (int i = 1;i < n;++i)
    {
        z = 0,ok = s[i];
        for (int i = 0;i < 8;++i)
        {
            z = z + ((ok&1)<<(7-i));
            ok>>=1;
        }
        int ok1 = s[i-1], zz = 0;
        for (int i = 0;i < 8;++i)
        {
            zz = zz + ((ok1&1)<<(7-i));
            ok1>>=1;
        }
        z = ( zz-z + 256*10)%256;
        ss[i] = z;
        printf("%d\n",z);
    }
	return 0;
}