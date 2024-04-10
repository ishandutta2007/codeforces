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

int main()
{
    int s[100],n,ma,mi;
    ma = 0,mi = 0x7f7f7f7f;
    cin>>n;
    REP(i,n) cin>>s[i];
    REP(i,n) ma=max(ma,s[i]),mi=min(mi,s[i]);
    int a,b;
    REP(i,n) if (s[i]==ma) {a = i; break;}
    for (int i = n-1;i>=0;--i) if (s[i]==mi) {b=i; break;}
    if (a < b) cout << a+(n-1-b) << endl;
    else cout << a+(n-1-b-1) << endl;
}