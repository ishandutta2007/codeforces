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
#include <cassert>
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


bool flag[500000 * 8];
double poss[500000 * 8];

int cor[500000*2];
MII has;

void build(int l,int r,int p)
{
    poss[p] = 1;
    flag[p] = 1;
    if (l < r)
    {
        int mid = (l + r) >> 1;
        build(l,mid,p*2);
        build(mid+1,r,p*2+1);
    }
}

inline void down(int p)
{
    if (!flag[p]) return;
    flag[p] = 0;
    flag[p*2] = flag[p*2+1] = true;
    poss[p*2] *= poss[p];
    poss[p*2+1] *= poss[p];
    poss[p] = 1;
    flag[p] = false;
}

void mult(int left,int right,int l,int r,int p,double d)
{
    if (l <= left && r >= right)
    {
        flag[p] = true;
        poss[p] *= d;
        return;
    }
    int mid = (left + right) >> 1;
    down(p);
    if (l <= mid) mult(left,mid,l,r,p*2,d);
    if (r > mid) mult(mid+1,right,l,r,p*2+1,d);
}

double final[500000];

void dump(int left,int right,int p)
{
    if (left == right)
    {
        final[left] = poss[p];
        return;
    }
    int mid = (left + right) >> 1;
    down(p);
    dump(left,mid,p*2);
    dump(mid+1,right,p*2+1);
}

int a[500000],h[500000],l[500000],r[500000];
int b[500000],z[500000];
int n,m;

int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m;
    REP(i,n) cin>>a[i]>>h[i]>>l[i]>>r[i];
    REP(i,m) cin>>b[i]>>z[i];
    has.clear();
    REP(i,n) has[a[i]+1] = has[a[i]-1] = has[a[i]-h[i]] = has[a[i]+h[i]] = 1;
    REP(i,m) has[b[i]] = 1;
    int total = 0;
    TR(it,has)
    {
        cor[total] = it->first;
        it->second = total++;
    }
    build(0,total-1,1);
    REP(i,n)
    {
        mult(0,total-1,has[a[i]-h[i]],has[a[i]-1],1,1 - (l[i]/100.0));
        mult(0,total-1,has[a[i]+1],has[a[i]+h[i]],1,1 - (r[i]/100.0));
    }
    dump(0,total-1,1);
    double answer = 0;
    REP(i,m)
        answer += z[i] * final[has[b[i]]];
    cout << fixed << setprecision(10) << answer << endl;
    return 0;
}