#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
using namespace std;
#define N 1000000
#define Point pdd
#define Polygon vector<Point>
#define Line pair<Point,Point>
struct LiChao_min{
  struct line{
    LL m, c;
    line(LL _m=1e9, LL _c=1e18) { m = _m; c = _c; }
    LL eval(LL x) { return m * x + c; }
  };
  struct node{
    node *l, *r; line f;
    node(line v) { f = v; l = r = NULL; }
  };
  typedef node* pnode;
  pnode root; int sz;
#define mid ((l+r)>>1)
  void insert(line &v, int l, int r, pnode &nd){
    if(!nd) { nd = new node(v); return; }
    LL trl = nd->f.eval(l), trr = nd->f.eval(r);
    LL vl = v.eval(l), vr = v.eval(r);
    if(trl <= vl && trr <= vr) return;
    if(trl > vl && trr > vr) { nd->f = v; return; }
    if(trl > vl) swap(nd->f, v);
    if(nd->f.eval(mid) < v.eval(mid)) insert(v, mid + 1, r, nd->r);
    else swap(nd->f, v), insert(v, l, mid, nd->l);
  }
  LL query(int x, int l, int r, pnode &nd){
    if(!nd) return LLONG_MAX;
    if(l == r) return nd->f.eval(x);
    if(mid >= x) return min(nd->f.eval(x), query(x, l, mid, nd->l));
    return min(nd->f.eval(x), query(x, mid + 1, r, nd->r));
  }
  /* -sz <= query_x <= sz */
  void init(int _sz){ sz = _sz + 1; root = NULL; }
  void add_line(LL m, LL c){ line v(m, c); insert(v, -sz, sz, root); }
  LL query(LL x) { return query(x, -sz, sz, root); }
}tree;
bool solve(){
    int n;
    scanf("%d",&n);
    tree.init(2000000);
    LL a[200005];
    LL sum=0;
    for(int i = 1;i<=n;i++){
        scanf("%lld",&a[i]);
        sum+=a[i]*1ll*i;
    }
    LL pre[200005];
    pre[0]=0;
    tree.add_line(0,0);
    for(int i = 1;i<=n;i++){
        pre[i]=pre[i-1]+a[i];
        tree.add_line(-i,pre[i]);
    }
    LL ans=sum;
    for(int i = 1;i<=n;i++){
        LL q=tree.query(a[i]);
        ans=max(ans,sum-q+pre[i]-i*1ll*a[i]);
    }
    printf("%lld\n",ans);
    return true;
}
int main(){
    int t=1;
    while(t--)solve();
}