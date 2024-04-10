#include <bits/stdc++.h>

#define fi first
#define se second
#define sc scanf
#define pr printf
#define pb push_back
#define ll long long
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 1000300;
const long long MX = 200200;
const long long MAGIC = sqrt(N);
const long long mod = 1e9 + 7;

using namespace std;

struct treap
{
        int x, y, delta, in, a;
        treap *l, *r;
        treap(int _x)
        {
                l = r = NULL;
                delta = a = 0;
                in = x = _x;
                y = rand();
        }
};
typedef treap* tree;

void push(tree v)
{
        if(!v) return;
        if(v->delta != 0)
        {
                if(v->l)
                {
                        v->l->x += v->delta;
                        v->l->delta += v->delta;
                }
                if(v->r)
                {
                        v->r->x += v->delta;
                        v->r->delta += v->delta;
                }
                v->delta = 0;
        }
}

void split(tree v, tree &l, tree &r, int x)
{
        if(!v)
        {
                l = r = NULL;
                return;
        }
        push(v);
        if(v->x <= x)
        {
                split(v->r, v->r, r, x);
                l = v;
        }
        else
        {
                split(v->l, l, v->l, x);
                r = v;
        }
}

tree merg(tree l, tree r)
{
        push(l);
        push(r);
        if(!l || !r)
        {
                return !l ? r : l;
        }
        if(l->y > r->y)
        {
                l->r = merg(l->r, r);
                return l;
        }
        else
        {
                r->l = merg(l, r->l);
                return r;
        }
}

tree root = NULL;

int n;
int m;
int ans[N];
bool used[N];

void solve()
{
        sc("%d%d", &n, &m);
        for(int i = 1; i <= n; i++)
        {
                root = merg(root, new treap(i));
        }
        for(int i = 1; i <= m; i++)
        {
                int x, y;
                sc("%d%d", &x, &y);
                swap(x, y);
                tree a, b, c;
                split(root, a, c, x);
                split(a, a, b, x - 1);
                if(used[y] && y != b->a || b->a && b->a != y)
                {
                        pr("-1");
                        return;
                }
                ans[b->in] = y;
                used[y] = true;
                b->x = 1;
                b->a = y;
                if(a)
                {
                        a->delta += 1;
                        a->x += 1;
                }
                a = merg(b, a);
                root = merg(a, c);
        }
        int x = 1;
        for(int i = 1; i <= n; i++)
        {
                if(ans[i] == 0)
                {
                        while(used[x])
                        {
                                x++;
                        }
                        ans[i] = x;
                        used[x] = true;
                }
                pr("%d ", ans[i]);
        }
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("rmq.in");
        //fout("rmq.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}