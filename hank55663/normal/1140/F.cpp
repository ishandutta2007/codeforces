#include<bits/stdc++.h>
//#include<bits/extc++.h>
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<double,null_type,less<double>,rb_tree_tag,tree_order_statistics_node_update> set_t;
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<double,double>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define index Index
#define Line pll
typedef long long LL;
#define MXN 3000
int mod=998244353;
int f[300005];
LL cnt[300005];
set<int> s[300005];
vector<int> v[300005];
LL now;
int Find(int x){
    if(f[x]==x)return x;
    return Find(f[x]);
}
vector<vector<int> > rmstk;
vector<pii> rmstate;
void ad(const pii &p){
    if(v[p.x].size()){
        int x=Find(v[p.x][0]);
        int y=Find(p.y);
        if(x==y){
            rmstate.pb(mp(0,0));
            vector<int> temp;
            now-=s[y].size()*cnt[y];
            if(s[y].find(p.x)==s[y].end()){
                s[y].insert(p.x);
                temp.pb(p.x);
            }
            now+=s[y].size()*cnt[y];
            rmstk.pb(temp);
        }
        else{
            if(s[x].size()>s[y].size())
                swap(x,y);
            now-=s[x].size()*cnt[x];
            now-=s[y].size()*cnt[y];
            f[x]=y;
            rmstate.pb(mp(x,y));
            cnt[y]+=cnt[x];
            vector<int> temp;
            for(auto it:s[x]){
                if(s[y].find(it)==s[y].end()){
                    s[y].insert(it);
                    temp.pb(it);
                }
            }
            if(s[y].find(p.x)==s[y].end()){
                s[y].insert(p.x);
                temp.pb(p.x);
            }
            rmstk.pb(temp);
            now+=s[y].size()*cnt[y];
        }
    }
    else{
        int y=Find(p.y);
        now-=s[y].size()*cnt[y];
        rmstate.pb(mp(0,0));
        vector<int> temp;
        if(s[y].find(p.x)==s[y].end()){
            s[y].insert(p.x);
            temp.pb(p.x);
        }
        now+=s[y].size()*cnt[y];
        rmstk.pb(temp);
    }
    v[p.x].pb(p.y);
}
void rm(const pii &p){
    v[p.x].pop_back();
    if(v[p.x].size()){
        pii st = rmstate.back();
        rmstate.pop_back();
        if(st.x==st.y){
            int y=Find(p.y);
            now-=s[y].size()*cnt[y];
            for(auto it:rmstk.back()){
                s[y].erase(it);
            }
            rmstk.pop_back();
            now+=s[y].size()*cnt[y];
        }
        else{
            int x=st.x;
            int y=st.y;
            
            now-=s[y].size()*cnt[y];
            f[x]=x;
            cnt[y]-=cnt[x];
            for(auto it:rmstk.back()){
                s[y].erase(it);
            }
            rmstk.pop_back();
            now+=s[x].size()*cnt[x];
            now+=s[y].size()*cnt[y];
        }
    }
    else{
        int y=Find(p.y);
        rmstate.pop_back();
        now-=s[y].size()*cnt[y];
        for(auto it:rmstk.back()){
            s[y].erase(it);
        }
        rmstk.pop_back();
        now+=s[y].size()*cnt[y];
    }
}
struct node{
    node *l,*r;
    int a,b;
    vector<pii> v;
    node(int _a,int _b):l(NULL),r(NULL),a(_a),b(_b){
        v.clear();
    }
}*root;
void build(node *n){
    if(n->a==n->b)return;
    int mid=(n->a+n->b)/2;
    n->l=new node(n->a,mid);
    n->r=new node(mid+1,n->b);
    build(n->l);
    build(n->r);
}
void add(node *n,int l,int r,pii p){
    if(n->a>=l&&n->b<=r){
        n->v.pb(p);
        return;
    }
    if(n->b<l||n->a>r)return;
    add(n->l,l,r,p);
    add(n->r,l,r,p);
}
LL ans[300005];
void travel(node *n){
    for(auto it:n->v){
        ad(it);
    }
    reverse(n->v.begin(),n->v.end());
    if(n->a==n->b){
        ans[n->a]=now;
        for(auto it:n->v)
            rm(it);
        return ;
    }
    travel(n->l);
    travel(n->r);
    for(auto it:n->v)
    rm(it);
}
int main(){
    int n;
    scanf("%d",&n);
    root = new node(1,n);
    build(root);
    map<pii,int> m;
    for(int i = 1;i<=n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        pii p=mp(x,y);
        if(m.find(p)==m.end())
        m[p]=i;
        else{
            add(root,m[p],i-1,p);
            m.erase(p);
        }
    }
    for(auto it:m){
        add(root,it.y,n,it.x);
    }
    for(int i =1;i<=300000;i++)
    cnt[i]=1,f[i]=i;
    now=0;
    travel(root);
    for(int i = 1;i<=n;i++)
    printf("%lld ",ans[i]);
}