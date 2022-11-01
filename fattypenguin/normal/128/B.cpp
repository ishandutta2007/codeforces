#include <algorithm>
#include <stdio.h>
#include <string.h>
#include <iostream>
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

const int maxn = 330000 + 1024;

char str2[maxn];

int sa[maxn],height[maxn],rank[maxn];
int wa[maxn],wb[maxn],wc[maxn],wd[maxn];
int str[maxn];

bool cmp(int *r,int a,int b,int l,int n)
{
    int la = r[a],lb = r[b],ra,rb;
    ra = a+l < n?r[a+l] : -1;
    rb = b+l < n?r[b+l] : -1;
    return (la == lb)&&(ra == rb);
}

void makesa(int *r,int *sa,int n,int m)
{
    int *x = wa,*y = wb;
    for (int i = 0;i < m;++i)
        wc[i] = 0;
    for (int i = 0;i < n;++i)
        ++wc[x[i] = r[i]];
    for (int i = 1;i < m;++i)
        wc[i] += wc[i-1];
    for (int i = n-1;i >= 0;--i)
        sa[--wc[x[i]]] = i;
    for (int tot = 0,p = 1;tot+1<n;p <<= 1,m=tot+1)
    {
        tot = 0;
        for (int i = n-p;i < n;++i)
            y[tot++] = i;
        for (int i = 0;i < n;++i)
            if (sa[i] >= p)
                y[tot++] = sa[i] - p;
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

int beg[maxn],end[maxn];
int N,n;

struct Node
{
    int maxi;
} tree[maxn*4];

void buildTree(int l,int r,int p)
{
   // tree[p].l = l;
   // tree[p].r = r;
    tree[p].maxi = 0;
    int mid = (l+r)>>1;
    if (l < r)
    {
        buildTree(l,mid,p*2);
        buildTree(mid+1,r,p*2+1);
    }
}

void cover(int L,int R,int x,int p,int maxi)
{
    if (L==R)
    {
        tree[p].maxi = maxi;
        return;
    }
    int mid = (L+R)>>1;
    if (x <= mid) cover(L,mid,x,p*2,maxi); else cover(mid+1,R,x,p*2+1,maxi);
    tree[p].maxi = max(tree[p*2].maxi,tree[p*2+1].maxi);
}

void get(int L,int R,int l,int r,int p,int &maxi)
{
    if (L >= l && R <= r)
    {
        maxi = max(maxi,tree[p].maxi);
        return;
    }
    int mid = (L+R)>>1;
    if (l <= mid) get(L,mid,l,r,p*2,maxi);
    if (r > mid) get(mid+1,R,l,r,p*2+1,maxi);
}
/*
void _buildSA(int l,int r,int p)
{
  //  satree[p].l = l;
 //   satree[p].r = r;
    int mid = (l+r)>>1;
    if (l < r)
    {
        buildSA(l,mid,p*2);
        buildSA(mid+1,r,p*2+1);
        satree[p].maxi = min(satree[p*2].maxi,satree[p*2+1].maxi);
    } else satree[p].maxi = height[l];
}

void _lcp(int L,int R,int l,int r,int p,int &v)
{
  //  cout<<"l = "<<satree[p].l<<" r = "<<satree[p].r<<endl;
    if (l <= L && r >= R)
    {
        v = min(satree[p].maxi,v);
        return;
    }
    int mid = (L+R) >> 1;
    if (l <= mid) lcp(L,mid,l,r,p*2,v);
    if (r > mid) lcp(mid+1,R,l,r,p*2+1,v);
}
*/
int g[maxn];
int LOG[maxn];
int DA[20][maxn];

int lcp(int l,int r)
{
    int len = r-l+1,lg = LOG[len];
    int v = min(DA[lg][l],DA[lg][r-(1<<lg)+1]);
    return v;
}

void makeSADA()
{
    REP(i,n) DA[0][i] = height[i];
    for (int i = 1;i < 20;++i)
    {
        int step = 1<<i;
        for (int j = 0;j < n;++j)
        {
            DA[i][j] = DA[i-1][j];
            if (j+step/2 < n)
                DA[i][j] = min(DA[i][j],DA[i-1][j+step/2]);
        }
    }
}

int main()
{
    int Cases,nowCase = 0;
    LOG[1] = 0;
    for (int i = 2;i < maxn;++i)
    {
        int x = 1;
        LOG[i] = 0;
        while (x*2 <= i)
        {
            x<<=1;
            ++LOG[i];
        }
    }
    int k;
    scanf("%s%d",str2,&k);
    n = strlen(str2);
    for (int i = 0;i < n;++i)
        str[i] = str2[i];
    makesa(str,sa,n,n+3000);
    makeheight(str,sa,height,n);
    makeSADA();
    if (k > (1+n)*(long long)n/2)
    {
        cout<<"No such line."<<endl;
        return 0;
    }
    for (int i = 0;i < n;++i)
    {
        for (int j = height[i]; j <= n-1-sa[i];++j)
        {
            int left = i+1,right = n-1;
            while (left < right)
            {
                int mid = ((left + right) >> 1)+1;
                if (lcp(i+1,mid) > j)
                    left = mid;
                else right = mid-1;
            }
            int cas = 0;
            cas = 1;
            if (i < n-1 && lcp(i+1,left) > j)
                cas = (left-i+1);
            if (k>cas)
                k -= cas;
            else
            {
                for (int t = 0;t <= j;++t)
                    printf("%c",str2[sa[i]+t]);
                cout<<endl;
                return 0;
            }
        }

    }
    return 0;
}