#include <bits/stdc++.h>
using namespace std;

#define N 100010
#define M 300010
#define INF 0x3f3f3f3f
int n, q, m, k, brr[M << 1];
struct qnode
{
    int l, r, p; 
    void scan() 
    {
        scanf("%d%d%d", &l, &r, &p);
        brr[++m] = r; 
    }
    bool operator < (const qnode &other) const
    {
        return r < other.r; 
    }
}qarr[M];

int GetHash(int x) { return lower_bound(brr + 1, brr + 1 + m, x) - brr; }
void Hash()
{
    sort(brr + 1, brr + 1 + m);
    m = unique(brr + 1, brr + 1 + m) - brr - 1;
    for (int i = 1; i <= k; ++i)
        qarr[i].r = GetHash(qarr[i].r);
}

namespace SEG
{
    int T[M << 1], cnt;
    struct node
    {
        int ls, rs, Min; 
    }a[M * 50];  
    void build(int &now, int l, int r)
    {
        now = ++cnt; 
        a[now].Min = 0;     
        if (l == r) return;
        int mid = (l + r) >> 1;
        build(a[now].ls, l, mid);
        build(a[now].rs, mid + 1, r);
    }
    void update(int &now, int pre, int l, int r, int pos, int val)
    {
        now = ++cnt; 
        a[now] = a[pre];
        if (l == r)
        {
            a[now].Min = max(a[now].Min, val);  
            return;
        }
        int mid = (l + r) >> 1;
        if (pos <= mid) update(a[now].ls, a[pre].ls, l, mid, pos, val);
        else update(a[now].rs, a[pre].rs, mid + 1, r, pos, val);
        a[now].Min = min(a[a[now].ls].Min, a[a[now].rs].Min);
    }
    int query(int now, int l, int r, int ql, int qr)
    {
        if (l >= ql && r <= qr) return a[now].Min;
        int mid = (l + r) >> 1;
        int res = INF; 
        if (ql <= mid) res = min(res, query(a[now].ls, l, mid, ql, qr));
        if (qr > mid) res = min(res, query(a[now].rs, mid + 1, r, ql, qr));      
        return res;
    }
}

int main()
{
    while (scanf("%d%d%d", &n, &q, &k) != EOF)
    {
        for (int i = 1; i <= k; ++i) qarr[i].scan(); Hash();
        sort(qarr + 1, qarr + 1 + k);
        SEG::build(SEG::T[0], 1, n);   
        for (int i = 1; i <= k; ++i) 
        {
            if (SEG::T[qarr[i].r] == 0) SEG::T[qarr[i].r] = SEG::T[qarr[i].r - 1];
            SEG::update(SEG::T[qarr[i].r], SEG::T[qarr[i].r], 1, n, qarr[i].p, qarr[i].l);    
        }
        for (int qq = 1, a, b, x, y; qq <= q; ++qq)
        {
            scanf("%d%d%d%d", &a, &b, &x, &y);
            y = upper_bound(brr + 1, brr + 1 + m, y) - brr - 1; 
            int tmp = SEG::query(SEG::T[y], 1, n, a, b);
            if (tmp >= x) puts("yes"); 
            else puts("no");
            if (qq == q) return 0;
            fflush(stdout);  
        }
    }
    return 0;
}