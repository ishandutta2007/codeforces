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
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
#define Point pdd
#define Polygon vector<Point>
#define Line pair<Point,Point>
#define N 1000000
struct LiChao_min{
    struct line{
        LL m,c;
        line(LL _m=0,LL _c=0){m=_m;c=_c;}
        LL eval(LL x){return m*x+c;}
    };
    struct node{
        node *l,*r;line f;
        node(line v){f=v;l=r=NULL;}
    };
    typedef node* pnode;
    pnode root;int sz;
    #define mid ((l+r)>>1)
    void insert(line &v,int l,int r,pnode &nd){
        if(!nd){nd=new node(v);return ;}
        LL trl=nd->f.eval(l),trr=nd->f.eval(r);
        LL vl=v.eval(l),vr=v.eval(r);
        if(trl<=vl&&trr<=vr)return;
        if(trl>vl&&trr>vr){nd->f=v;return ;}
        if(trl>vl)swap(nd->f,v);
        if(nd->f.eval(mid)<v.eval(mid))insert(v,mid+1,r,nd->r);
        else swap(nd->f,v),insert(v,l,mid,nd->l);
    }
    LL query(int x,int l,int r,pnode &nd){
        if(!nd)return LLONG_MAX;
        if(l==r)return nd->f.eval(x);
        if(mid>=x)return min(nd->f.eval(x),query(x,l,mid,nd->l));
        return min(nd->f.eval(x),query(x,mid+1,r,nd->r));
    }
    void init(int _sz){sz=_sz+1;root=NULL;}
    void add_line(LL m,LL c){line v(m,c);insert(v,-sz,sz,root);}
    LL query(LL x){return query(x,-sz,sz,root);}
}t;
bool solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    vector<pii> v;
    t.init(1000000000);
    t.add_line(0,0);
    int a[200005];
    LL pre=0;
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
        pre+=a[i];
        LL l=0,r=1e9;
        while(r>l+1){
            if(t.query(mid)>=pre-mid*i)r=mid;
            else l=mid;
        }
        if(i!=n)
        v.pb(mp(r,i));
        t.add_line(-i,pre);
    }
    sort(v.begin(),v.end());
    set<int> s;
    s.insert(0);
    s.insert(n);
    multiset<int> s2;
    s2.insert(n);
    int now=0;
    while(m--){
        int k;
        scanf("%d",&k);
        while(now<v.size()&&v[now].x<=k){
            int x=v[now].y;
            now++;
            s.insert(x);
            auto it=next(s.find(x));
            auto it2=prev(s.find(x));
            s2.erase(s2.find(*it-*it2));
            s2.insert(*it-x);
            s2.insert(x-*it2);
        }
        printf("%d ",*s2.rbegin()-1);
    }
    printf("\n");
    return true;
}
int main(){
    int t=1;00000;
    //scanf("%d",&t);
    while(t--)solve();
}
/*
1 4 10100
1 6 1010100
1 8 101010100
1 y 10100  (y+1)  y/2
2 5 1100100
2 6 11001100
2 7 110011000
2 8 1100110000
2 9 11001100100
*/