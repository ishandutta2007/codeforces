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

double p[1007][1007],d[1007][1007];
bool P[1007][1007],D[1007][1007];

double dragon(int w,int b);
double princess(int w,int b)
{
    if (w == 0) return 0;
    if (P[w][b]) return p[w][b];
    P[w][b] = true;
    double pp = (double)w/(w+b);
    p[w][b] = pp;
    if (b) p[w][b] += (1-pp)*(1-dragon(w,b-1));
    return p[w][b];
}

double dragon(int w,int b)
{
    if (w == 0) return 1.0;
    if (D[w][b]) return d[w][b];
    D[w][b] = true;
    double pp = (double)w/(w+b);
    d[w][b] = pp;
    if (b)
    {
        d[w][b] += (1-pp)*(((double)w/(w+b-1)*(1-princess(w-1,b-1))));
        if (b-1>0) d[w][b] +=(1-pp)*((double)(b-1)/(w+b-1)*(1-princess(w,b-2)));
    }
    return d[w][b];
}

int main()
{
    int n,m;
    cin>>n>>m;
    CLEAR(P);
    CLEAR(D);
    cout << fixed << setprecision(10) << princess(n,m) << endl;
	return 0;
}