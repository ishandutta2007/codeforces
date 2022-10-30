//by jghs1328
#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;
typedef long long ll;

#define N 100004

int seq[N], a[N];
inline int bit (int x, int k){return (x>>k)&1;}

struct BSP
{
    int v[N*4];bool f[N*4];    
    inline int L (int k){return k*2;}
    inline int R (int k){return k*2+1;}
    inline int mid (int x){return x/2;}
    inline int len (int l, int r){return r-l+1;}
    inline int init (int k, int l, int r, int *a)
    {
        f[k] = 0;
        if (l==r)return v[k]=a[l], 0;
        int m=mid (l+r);
        init (L (k), l, m, a);
        init (R (k), m+1, r, a);
        return v[k]=v[L (k)]+v[R (k)], 0;
    }
    inline int get (int k, int l, int r)
    {
        if (!f[k])return v[k];
        return len (l, r)-v[k];
    }
    inline void pull (int k, int l, int r)
    {
        int m=mid (l+r);
        v[k] = get (L (k), l, m)+get (R (k), m+1, r); 
    }
    inline void push (int k)
    {
        if (f[k])
        {
            f[L (k)] ^= 1;
            f[R (k)] ^= 1;
            f[k] = 0;
        }
    }
    inline void add (int k, int l, int r, int ql, int qr)
    {
        if (qr<l || ql>r)return;
        if (l>=ql && r<=qr){f[k]^=1;return;}
        push (k);
        int m=mid(l+r);
        add (L (k), l, m, ql, qr);
        add (R (k), m+1, r, ql, qr);
        pull (k, l, r);
    }
    inline int sum (int k, int l, int r, int ql, int qr)
    {
        if (qr<l || ql>r)return 0;
        if (l>=ql && r<=qr)return get (k, l, r);
        push (k);
        int m=mid (l+r), rt=0;
        rt += sum (L (k), l, m, ql, qr);
        rt += sum (R (k), m+1, r, ql, qr);
        pull (k, l, r);
        return rt;
    }
}bsp[24];

int n;
void sol1 ()
{
    int l, r;scanf ("%d%d", &l, &r);
    ll sum=0;
    for (int i=0 ; i < 20 ; i ++)
        sum += bsp[i].sum (1, 1, n, l, r)*(1ll<<i);
    printf ("%I64d\n", sum);
}
void sol2 ()
{
    int l, r, x;scanf ("%d%d%d", &l, &r, &x);
    for (int i=0 ; i < 20 ; i ++)
        if (bit (x, i))
            bsp[i].add (1, 1, n, l, r);
}
int main ()
{
    scanf ("%d", &n); 
    for (int i=1 ; i <= n ; i ++)scanf ("%d", seq+i);
    for (int i=0 ; i < 20 ; i ++)
    {
        for (int j=1 ; j <= n ; j ++)a[j]=bit (seq[j], i);
        bsp[i].init (1, 1, n, a);
    }
    int q;scanf ("%d", &q);
    while (q --)
    {
        int t;scanf ("%d", &t);
        if (t==1)sol1 ();
        else sol2();
    }
}