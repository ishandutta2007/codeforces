#include <stdio.h>
#include <string.h>
#include <iostream>
#include <map>

using namespace std;

typedef long long LL;

const int maxn = 100000 * 2 + 1023;

struct SegTree
{
    int l,r,lc,rc;
    int ele;
    LL sum[5];
} tree[maxn];

int last = 0;

void buildTree(int l,int r,int &p)
{
    p = last++;
    tree[p].l = l;
    tree[p].r = r;
    tree[p].lc = tree[p].rc = 0;
    memset(tree[p].sum,0,sizeof(tree[p].sum));
    tree[p].ele = 0;
    int mid = (l+r)>>1;
    if (l < r)
    {
        buildTree(l,mid,tree[p].lc);
        buildTree(mid+1,r,tree[p].rc);
    }
}

map<int,int> has;

int opt[700007];
int val[700007],n,inv[700007];
char buf[256];

void update(int p)
{
    tree[p].ele = tree[tree[p].lc].ele;
    for (int i = 0;i < 5;++i)
        tree[p].sum[i] = tree[tree[p].lc].sum[i];
    if (tree[p].rc == -1)
        return;
    tree[p].ele += tree[tree[p].rc].ele;
    for (int i = 0;i < 5;++i)
        tree[p].sum[i] += tree[tree[p].rc].sum[(i-(tree[tree[p].lc].ele%5)+5)%5];
}

void insert(int x,int p)
{
    if (tree[p].l == tree[p].r)
    {
        ++tree[p].ele;
        tree[p].sum[tree[p].ele%5] += inv[x];
        return;
    }
    int mid = (tree[p].l + tree[p].r) >> 1;
    if (x < mid)
        insert(x,tree[p].lc);
    else
        insert(x,tree[p].rc);
    update(p);
}

void dele(int x,int p)
{
    if (tree[p].l == tree[p].r)
    {
        tree[p].sum[tree[p].ele%5] -= inv[x];
        --tree[p].ele;
        return;
    }
    int mid = (tree[p].l + tree[p].r) >> 1;
    if (x < mid)
        dele(x,tree[p].lc);
    else
        dele(x,tree[p].rc);
    update(p);
}

int main()
{
    cin >> n;
    has.clear();
    for (int i = 0;i < n;++i)
    {
        cin >> buf;
        if (buf[0] == 'a')
        {
            opt[i] = 0;
            cin >> val[i];
            has[val[i]] = 1;
        }
        if (buf[0] == 'd')
        {
            opt[i] = 1;
            cin >> val[i];
            has[val[i]] = 1;
        }
        if (buf[0] == 's')
        {
            opt[i] = 2;
        }
    }
    int count = 0;
    for (map<int,int>::iterator i = has.begin();i != has.end();++i)
    {
        inv[count] = i->first;
        i->second = count++;
    }
    int root = -1;
    last = 0;
    buildTree(0,count,root);
    for (int i = 0;i < n;++i)
    {
        if (opt[i] == 0)
        {
            insert(has[val[i]],root);
        }
        if (opt[i] == 1)
        {
            dele(has[val[i]],root);
        }
        if (opt[i] == 2)
            cout << tree[root].sum[3] << endl;
    }
    return 0;
}