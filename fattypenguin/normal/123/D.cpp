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

const int maxn = 200007;

char tmp[100007];
int n,len,t;
int who[maxn],str[maxn],sa[maxn],height[maxn],rank[maxn];
int wa[maxn],wb[maxn],wc[maxn],wd[maxn];

inline int min(int a,int b) {return a < b?a:b;}
inline int max(int a,int b) {return a > b ? a:b;}

bool cmp(int *r,int a,int b,int l,int n)
{
    int la = r[a],lb = r[b],ra,rb;
    ra = a+l < n? r[a+l] : -1;
    rb = b+l < n? r[b+l] : -1;
    return (la == lb) && (ra == rb);
}

void makesa(int *r,int *sa,int n,int m)
{
    int *x = wa, *y = wb;
    for (int i = 0;i < m;++i)
        wc[i] = 0;
    for (int i = 0;i < n;++i)
        ++wc[x[i] = r[i]];
    for (int i = 1;i < m;++i)
        wc[i] += wc[i-1];
    for (int i = n-1;i >= 0;--i)
        sa[--wc[x[i]]] = i;
    for (int tot = 0,p = 1;tot+1<n;p <<= 1,m = tot+1)
    {
        tot = 0;
        for (int i = n-p;i < n;++i)
            y[tot++] = i;
        for (int i = 0;i < n;++i)
            if (sa[i] >= p)
                y[tot++] = sa[i]-p;
        for (int i = 0;i < n;++i)
            wd[i] = x[y[i]];
        for (int i = 0;i < m;++i)
            wc[i] = 0;
        for (int i = 0;i < n;++i)
            ++wc[wd[i]];
        for (int i = 1;i < m;++i)
            wc[i] += wc[i-1];
        for (int i = n-1;i >= 0;--i)
            sa[--wc[wd[i]]] = y[i];
        int *t = x; x = y; y = t;
        x[sa[0]] = tot = 0;
        for (int i = 1;i < n;++i)
            x[sa[i]] = cmp(y,sa[i-1],sa[i],p,n) ? tot : ++tot;
    }
}

void makeheight(int *r,int *sa,int *height,int n)
{
    for (int i = 0;i < n;++i)
        rank[sa[i]] = i;
    height[0] = 0;
    for (int i = 0;i < n;++i)
    {
        if (!rank[i])
            continue;
        if (!i)
            height[rank[i]] = 0;
        else
            height[rank[i]] = height[rank[i-1]] - 1;
        if (height[rank[i]] < 0)
            height[rank[i]] = 0;
        for (;r[i + height[rank[i]]] == r[sa[rank[i]-1] + height[rank[i]]];++height[rank[i]]);
    }
}

struct Node
{
    int l,r,len;
    bool zero;
    long long sum,delta;
} tree[maxn*4];

void buildTree(int l,int r,int p)
{
    tree[p].l = l;
    tree[p].r = r;
    tree[p].len = r-l+1;
    tree[p].sum = tree[p].delta = 0;
    tree[p].zero = false;
    int mid = (l+r)>>1;
    if (l<r)
    {
        buildTree(l,mid,p*2),
        buildTree(mid+1,r,p*2+1);
    }
}

void down(int p)
{
    if (tree[p].zero)
    {
        tree[p*2].zero = true;
        tree[p*2+1].zero = true;
        tree[p*2].sum = tree[p*2+1].sum = 0;
        tree[p*2].delta = tree[p*2+1].delta = 0;
        tree[p].zero = false;
    }
    if (!tree[p].delta) return;
    tree[p*2].delta += tree[p].delta;
    tree[p*2].sum += tree[p].delta * tree[p*2].len;
    tree[p*2+1].delta += tree[p].delta;
    tree[p*2+1].sum += tree[p].delta * tree[p*2+1].len;
    tree[p].delta = 0;
}

void up(int p)
{
    tree[p].sum = tree[p*2].sum + tree[p*2+1].sum;
}

void sum(int l,int r,int p,long long &s)
{
    if (l <= tree[p].l && r >= tree[p].r)
    {
        s += tree[p].sum;
        return;
    }
    int mid = (tree[p].l + tree[p].r) >> 1;
    down(p);
    if (l <= mid) sum(l,r,p*2,s);
    if (r  > mid) sum(l,r,p*2+1,s);
    up(p);
}

void addByOne(int l,int r,int p)
{
    if (l <= tree[p].l && r >= tree[p].r)
    {
        tree[p].delta += 1;
        tree[p].sum += tree[p].len;
        return;
    }
    int mid = (tree[p].l + tree[p].r) >> 1;
    down(p);
    if (l <= mid) addByOne(l,r,p*2);
    if (r  > mid) addByOne(l,r,p*2+1);
    up(p);
}

void setToZero(int l,int r,int p)
{
    if (l <= tree[p].l && r >= tree[p].r)
    {
        tree[p].delta = tree[p].sum = 0;
        tree[p].zero = true;
        return;
    }
    int mid = (tree[p].l + tree[p].r) >> 1;
    down(p);
    if (l <= mid) setToZero(l,r,p*2);
    if (r  > mid) setToZero(l,r,p*2+1);
    up(p);
}

int main()
{
    scanf("%s",tmp);
    int len = strlen(tmp);
    REP(i,len) str[i] = tmp[i];
    makesa(str,sa,len,200);
    makeheight(str,sa,height,len);
    buildTree(0,len-1,1);
    addByOne(0,len-1-sa[0],1);
    int right = len-1-sa[0];
    long long ans = 2*(right+1);
    for (int i = 1;i < len;++i)
    {
        if (height[i] <= right)
        {
            setToZero(height[i],right,1);
            right = height[i] - 1;
        }
        addByOne(0,len-1-sa[i],1);
        if (len-1-sa[i] < right)
        {
            setToZero(len-1-sa[i]+1,right,1);
            right = len-1-sa[i];
        }
        right = max(right,len-1-sa[i]);
        ans += 2*tree[1].sum;
     //   cout<<ans<<endl;
    }
    cout<<ans/2<<endl;
    return 0;
}