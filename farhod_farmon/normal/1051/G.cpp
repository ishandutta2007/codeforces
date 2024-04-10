#include <bits/stdc++.h>

#define fi first
#define se second
#define fin(s) freopen( s, "r", stdin );
#define fout(s) freopen( s, "w", stdout );

const long long N = 400400;
const long long Q = 10100;
const long long mod = 998244353;
const long long block = sqrt(N);

using namespace std;

struct treap
{
        treap *l, *r;
        int x, y, c;
        long long s;
        treap(int _x)
        {
                l = r = NULL;
                y = rand();
                x = _x;
                s = _x;
                c = 1;
        }
};
typedef treap* tree;

void upd(tree v)
{
        v->s = v->x;
        v->c = 1;
        if(v->l){
                v->s += v->l->s;
                v->c += v->l->c;
        }
        if(v->r){
                v->s += v->r->s;
                v->c += v->r->c;
        }
}

void split(tree v, tree &l, tree &r, int x)
{
        if(v == NULL)
        {
                l = r = NULL;
                return;
        }
        if(v->x <= x)
        {
                split(v->r, v->r, r, x);
                l = v;
                upd(l);
        }
        else
        {
                split(v->l, l, v->l, x);
                r = v;
                upd(r);
        }
}

tree merg(tree l, tree r)
{
        if(l == NULL || r == NULL)
        {
                return l == NULL ? r : l;
        }
        if(l->y > r->y)
        {
                l->r = merg(l->r, r);
                upd(l);
                return l;
        }
        else
        {
                r->l = merg(l, r->l);
                upd(r);
                return r;
        }
}

void chs(tree x)
{
        if(x == NULL){
                return;
        }
        chs(x->l);
        chs(x->r);
        x = NULL;
}

void prnt(tree v)
{
        if(v == NULL)
        {
                return;
        }
        prnt(v->l);
        cout << v->x << " ";
        prnt(v->r);
}

tree f[N];

int n;
int a[N];
int b[N];
int p[N];
int lst[N];
bool used[N];
long long ans;
long long ans2[N];
vector < int > v[N];

int get(int x)
{
        return p[x] == x ? x : p[x] = get(p[x]);
}

void clr(int x)
{
        v[x].clear();
        chs(f[x]);
}

void go1(tree x, int y)
{
        if(x == NULL){
                return;
        }
        go1(x->l, y);
        int g = x->x;
        tree a, b;
        //cout << g << " -> " << y << " " << ans << endl;
        split(f[y], a, b, g);
        if(b){
                ans += 1ll * b->c * g - b->s;
        }
        a = merg(a, new treap(g));
        f[y] = merg(a, b);
        v[y].push_back(g);
        go1(x->r, y);
}

void go2(tree x, int y)
{
        if(x == NULL){
                return;
        }
        go2(x->r, y);
        int g = x->x;
        tree a, b;
        split(f[y], a, b, g);
        //cout << g << " -> " << x << " " << ans << " ";
        if(a){
                //cout << a->s << " ";
                ans += a->s - 1ll * a->c * g;
        }
        //cout << ans << endl;
        a = merg(a, new treap(g));
        f[y] = merg(a, b);
        v[y].push_back(g);
        go2(x->l, y);
}

void heh(int x, int y)
{
        x = get(x);
        y = get(y);
        if(v[x].size() < v[y].size()){
                p[x] = y;
                go1(f[x], y);
                clr(x);
        }
        else{
                p[y] = x;
                go2(f[y], x);
                clr(y);
        }
}

void solve()
{
        cin >> n;
        for(int i = 1; i < N; i++){
                lst[i] = i;
        }
        for(int i = 1; i <= n; i++){
                cin >> a[i] >> b[i];
                vector < int > v;
                int cur = a[i];
                while(used[a[i]]){
                        v.push_back(a[i]);
                        a[i] = lst[a[i]] + 1;
                }
                ans2[i] = 1ll * (a[i] - cur) * b[i];
                used[a[i]] = 1;
                for(int x: v){
                        lst[x] = a[i];
                }
                ::v[a[i]].push_back(b[i]);
                f[a[i]] = new treap(b[i]);
                p[a[i]] = a[i];
        }
        for(int i = 0; i < N; i++){
                used[i] = 0;
        }
        for(int i = 1; i <= n; i++){
                int x = a[i];
                used[x] = 1;
                if(used[x - 1]){
                        heh(x - 1, x);
                }
                if(used[x + 1]){
                        heh(x, x + 1);
                }
                ans += ans2[i];
                cout << ans << "\n";
        }
}

bool mtest = false; int main()
{
        //fin("input.txt");
        //fout("output.txt");
        //fin("substr3.in");
        //fout("substr3.out");
        ios_base::sync_with_stdio(0);
        int TE = 1;
        if(mtest)
                cin >> TE;
        while(TE--)
                solve();
        return 0;
}