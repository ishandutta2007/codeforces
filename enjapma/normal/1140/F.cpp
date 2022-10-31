#include <bits/stdc++.h>
#include <unistd.h>
#include <sys/time.h>
#include <stdlib.h>
 
using namespace std;
 
typedef long long ll;
typedef pair<ll,ll> P;
typedef pair<P, ll> T;
 
long long int INF = 2e18;
const ll fact_table = 1200008;
double Pi = 3.1415926535897932384626;

priority_queue <ll> pql;
priority_queue <P> pqp;
priority_queue <P> bag;
//big priority queue
priority_queue <ll,vector<ll>,greater<ll> > pqls;
priority_queue <P,vector<P>,greater<P> > pqps;
//small priority queue
//top pop
 
ll dx[8]={1,0,-1,0,1,1,-1,-1};
ll dy[8]={0,1,0,-1,1,-1,-1,1};
char dir[] = "DRUL";
//,,,

#define endl "\n"
#ifdef ENJAPMA
    #undef endl
#endif
#define p(x) cout<<x<<endl;
#define el cout<<endl;
#define pe(x) cout<<x<<" ";
#define ps(x) cout<<fixed<<setprecision(25)<<x<<endl;
#define pu(x) cout<<(x);
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define CLEAR(a) a = decltype(a)(); 
#define pc(x) cout << x << ",";
 
const ll mod = 998244353ll;
// const ll mod = 1000000007ll;
  
ll mypow(ll number1,ll number2, ll mod){
    if(number2 == 0){
        return 1ll;
    }else{
        ll number3 = mypow(number1,number2 / 2, mod);
        number3 *= number3;
        number3 %= mod;
        if(number2%2==1){
            number3 *= number1;
            number3 %= mod;
        }
        return number3;
    }
}
void YES(bool condition){
    if(condition){
        p("YES");
    }else{
        p("NO");
    }
    return;
}
void Yes(bool condition){
    if(condition){
        p("Yes");
    }else{
        p("No");
    }
    return;
}
 

ll fact[fact_table + 5],rfact[fact_table + 5]; 
 
void c3_init(){
    fact[0] = rfact[0] = 1;
    for(ll i=1; i<=fact_table; i++){
        fact[i] = (fact[i-1]*i) % mod;
    }
    rfact[fact_table] = mypow(fact[fact_table],mod - 2, mod);
    for(ll i=fact_table; i>=1; i--){
       rfact[i-1] = rfact[i] * i;
       rfact[i-1] %= mod;
    }
    return;}
ll c3(ll n,ll r){
    return (((fact[n] * rfact[r]) % mod ) * rfact[n-r]) % mod;}

bool multicase = false;

ll n,m,num,a,b,c,d,e,h,q;
ll w, k;
ll x[200005];
string s;

template<typename T>
class dynamic_connectivity{
    class euler_tour_tree{
        public:
        struct node;
        using np=node*;
        using lint=long long;
        struct node{
            np ch[2]={nullptr,nullptr};
            np p=nullptr;
            int l,r,sz;
            T val=et,sum=et;
            bool exact;
            bool child_exact;
            bool edge_connected=0;
            bool child_edge_connected=0;
            node(){}
            node(int l,int r):l(l),r(r),sz(l==r),exact(l<r),child_exact(l<r){}
            bool is_root() {
                return !p;
            }
        };
        vector<unordered_map<int,np>>ptr;
        np get_node(int l,int r){
            if(ptr[l].find(r)==ptr[l].end())ptr[l][r]=new node(l,r);
            return ptr[l][r];
        }
        np root(np t){
            if(!t)return t;
            while(t->p)t=t->p;
            return t;
        }
        bool same(np s,np t){
            if(s)splay(s);
            if(t)splay(t);
            return root(s)==root(t);
        }
        np reroot(np t){
            auto s=split(t);
            return merge(s.second,s.first);
        }
        pair<np,np> split(np s){
            splay(s);
            np t=s->ch[0];
            if(t)t->p=nullptr;
            s->ch[0]=nullptr;
            return {t,update(s)};
        }
        pair<np,np> split2(np s){
            splay(s);
            np t=s->ch[0];
            np u=s->ch[1];
            if(t)t->p=nullptr;
            s->ch[0]=nullptr;
            if(u)u->p=nullptr;
            s->ch[1]=nullptr;
            return {t,u};
        }
        tuple<np,np,np> split(np s,np t){
            auto u=split2(s);
            if(same(u.first,t)){
                auto r=split2(t);
                return make_tuple(r.first,r.second,u.second);
            }else{
                auto r=split2(t);
                return make_tuple(u.first,r.first,r.second);
            }
        }
        template<typename First, typename... Rest>
        np merge(First s,Rest... t){
            return merge(s,merge(t...));
        }
        np merge(np s,np t){
            if(!s)return t;
            if(!t)return s;
            while(s->ch[1])s=s->ch[1];
            splay(s);
            s->ch[1]=t;
            if(t)t->p=s;
            return update(s);
        }
        int size(np t){return t?t->sz:0;}
        np update(np t){
            t->sum=et;
            if(t->ch[0])t->sum=fn(t->sum,t->ch[0]->sum);
            if(t->l==t->r)t->sum=fn(t->sum,t->val);
            if(t->ch[1])t->sum=fn(t->sum,t->ch[1]->sum);
            t->sz=size(t->ch[0])+(t->l==t->r)+size(t->ch[1]);
            t->child_edge_connected=(t->ch[0]?t->ch[0]->child_edge_connected:0)|(t->edge_connected)|(t->ch[1]?t->ch[1]->child_edge_connected:0);
            t->child_exact=(t->ch[0]?t->ch[0]->child_exact:0)|(t->exact)|(t->ch[1]?t->ch[1]->child_exact:0);
            return t;
        }
        void push(np t){
            //
        }
        void rot(np t,bool b){
            np x=t->p,y=x->p;
            if((x->ch[1-b]=t->ch[b]))t->ch[b]->p=x;
            t->ch[b]=x,x->p=t;
            update(x);update(t);
            if((t->p=y)){
                if(y->ch[0]==x)y->ch[0]=t;
                if(y->ch[1]==x)y->ch[1]=t;
                update(y);
            }
        }
        void splay(np t){
            push(t);
            while(!t->is_root()){
                np q=t->p;
                if(q->is_root()){
                    push(q), push(t);
                    rot(t,q->ch[0]==t);
                }else{
                    np r=q->p;
                    push(r), push(q), push(t);
                    bool b=r->ch[0]==q;
                    if(q->ch[1-b]==t)rot(q,b),rot(t,b);
                    else rot(t,1-b),rot(t,b);
                }
            }
        }
        void debug(np t){
            if(!t)return;
            debug(t->ch[0]);
            cerr<<t->l<<"-"<<t->r<<" ";
            debug(t->ch[1]);
        }
        public:
        euler_tour_tree(){}
        euler_tour_tree(int sz){
            ptr.resize(sz);
            for(int i=0;i<sz;i++)ptr[i][i]=new node(i,i);
        }
        int size(int s){
            np t=get_node(s,s);
            splay(t);
            return t->sz;
        }
        bool same(int s,int t){
            return same(get_node(s,s),get_node(t,t));
        }
        void set_size(int sz){
            ptr.resize(sz);
            for(int i=0;i<sz;i++)ptr[i][i]=new node(i,i);
        }
        void update(int s,T x){
            np t=get_node(s,s);
            splay(t);
            t->val=fn(t->val,x);
            update(t);
        }
        void edge_update(int s,auto g){
            np t=get_node(s,s);
            splay(t);
            function<void(np)>dfs=[&](np t){
                assert(t);
                if(t->l<t->r&&t->exact){
                    splay(t);
                    t->exact=0;
                    update(t);
                    g(t->l,t->r);
                    return;
                }
                if(t->ch[0]&&t->ch[0]->child_exact)dfs(t->ch[0]);
                else dfs(t->ch[1]);
            };
            while(t&&t->child_exact){
                dfs(t);
                splay(t);
            }
        }
        bool try_reconnect(int s,auto f){
            np t=get_node(s,s);
            splay(t);
            function<bool(np)>dfs=[&](np t)->bool{
                assert(t);
                if(t->edge_connected){
                    splay(t);
                    return f(t->l);
                }
                if(t->ch[0]&&t->ch[0]->child_edge_connected)return dfs(t->ch[0]);
                else return dfs(t->ch[1]);
            };
            while(t->child_edge_connected){
                if(dfs(t))return 1;
                splay(t);
            }
            return 0;
        }
        void edge_connected_update(int s,bool b){
            np t=get_node(s,s);
            splay(t);
            t->edge_connected=b;
            update(t);
        }
        bool link(int l,int r){
            if(same(l,r))return 0;
            merge(reroot(get_node(l,l)),get_node(l,r),reroot(get_node(r,r)),get_node(r,l));
            return 1;
        }
        bool cut(int l,int r){
            if(ptr[l].find(r)==ptr[l].end())return 0;
            np s,t,u;
            tie(s,t,u)=split(get_node(l,r),get_node(r,l));
            merge(s,u);
            np p=ptr[l][r];
            np q=ptr[r][l];
            ptr[l].erase(r);
            ptr[r].erase(l);
            delete p;delete q;
            return 1;
        }
        T get_sum(int p,int v){
            cut(p,v);
            np t=get_node(v,v);
            splay(t);
            T res=t->sum;
            link(p,v);
            return res;
        }
        T get_sum(int s){
            np t=get_node(s,s);
            splay(t);
            return t->sum;
        }
    };
    int dep=1;
    vector<euler_tour_tree> ett;
    vector<vector<unordered_set<int>>>edges;
    int sz;
    public:
    dynamic_connectivity(int sz):sz(sz){
        ett.emplace_back(sz);
        edges.emplace_back(sz);
    }
    bool link(int s,int t){
        if(s==t)return 0;
        if(ett[0].link(s,t))return 1;
        edges[0][s].insert(t);
        edges[0][t].insert(s);
        if(edges[0][s].size()==1)ett[0].edge_connected_update(s,1);
        if(edges[0][t].size()==1)ett[0].edge_connected_update(t,1);
        return 0;
    }
    bool same(int s,int t){
        return ett[0].same(s,t);
    }
    int size(int s){
        return ett[0].size(s);
    }
    vector<int>get_vertex(int s){
        return ett[0].vertex_list(s);
    }
    void update(int s,T x){
        ett[0].update(s,x);
    }
    T get_sum(int s){
        return ett[0].get_sum(s);
    }
    bool cut(int s,int t){
        if(s==t)return 0;
        for(int i=0;i<dep;i++){
            edges[i][s].erase(t);
            edges[i][t].erase(s);
            if(edges[i][s].size()==0)ett[i].edge_connected_update(s,0);
            if(edges[i][t].size()==0)ett[i].edge_connected_update(t,0);
        }
        for(int i=dep-1;i>=0;i--){
            if(ett[i].cut(s,t)){
                if(dep-1==i){
                    dep++;
                    ett.emplace_back(sz);
                    edges.emplace_back(sz);
                }
                return !try_reconnect(s,t,i);
            }
        }
        return 0;
    }
    bool try_reconnect(int s,int t,int k){
        for(int i=0;i<k;i++){
            ett[i].cut(s,t);
        }
        for(int i=k;i>=0;i--){
            if(ett[i].size(s)>ett[i].size(t))swap(s,t);
            auto g=[&](int s,int t){ett[i+1].link(s,t);};
            ett[i].edge_update(s,g);
            auto f=[&](int x)->bool{
                for(auto itr=edges[i][x].begin();itr!=edges[i][x].end();){
                    auto y=*itr;
                    itr=edges[i][x].erase(itr);
                    edges[i][y].erase(x);
                    if(edges[i][x].size()==0)ett[i].edge_connected_update(x,0);
                    if(edges[i][y].size()==0)ett[i].edge_connected_update(y,0);
                    if(ett[i].same(x,y)){
                        edges[i+1][x].insert(y);
                        edges[i+1][y].insert(x);
                        if(edges[i+1][x].size()==1)ett[i+1].edge_connected_update(x,1);
                        if(edges[i+1][y].size()==1)ett[i+1].edge_connected_update(y,1);
                    }else{
                        for(int j=0;j<=i;j++){
                            ett[j].link(x,y);
                        }
                        return 1;
                    }
                }
                return 0;
            };
            if(ett[i].try_reconnect(s,f))return 1;
        }
        return 0;
    }
    constexpr static T et=T();
    constexpr static T fn(T s,T t){
        return s+t;
    }
};

map<P, ll> mp;

void solve(){
    cin >> q;
    n = 300000;
    dynamic_connectivity<ll>dc(2*n+10);

    for(ll i=1;i<=300000;i++){
        dc.update(i, 300001ll);
    }
    for(ll i=300001;i<=600000;i++){
        dc.update(i, 1);
    }
    ll sum = 0;
    for(ll i=0;i<q;i++){
        cin >> a >> b;
        if(mp[P(a, b)] == 0){
            // unite
            if(dc.same(300000 + a, b)){
                dc.link(300000 + a, b);
                pe(sum);
                mp[P(a, b)] = 1;
                continue;
            }
            ll size1 = dc.get_sum(300000 + a);
            ll size2 = dc.get_sum(b);
            ll before1 = (size1 / 300001ll) * (size1 % 300001ll);
            ll before2 = (size2 / 300001ll) * (size2 % 300001ll);
            dc.link(300000 + a, b);
            ll size3 = dc.get_sum(b);
            ll after = (size3 / 300001ll) * (size3 % 300001ll);
            sum += (after - before1 - before2);
            mp[P(a, b)] = 1;
        }else{
            ll size1 = dc.get_sum(b);
            ll before = (size1 / 300001ll) * (size1 % 300001ll);
            dc.cut(300000 + a, b);
            if(dc.same(300000 + a, b)){
                mp[P(a, b)] = 0;
                pe(sum);
                continue;
            }
            ll size2 = dc.get_sum(300000 + a), size3 = dc.get_sum(b);
            ll after1 = (size2 / 300001ll) * (size2 % 300001ll);
            ll after2 = (size3 / 300001ll) * (size3 % 300001ll);
            sum += (after1 + after2 - before);
            mp[P(a, b)] = 0;
        }
        pe(sum);
    }
    el;
    return;
}


int main(){
    // init();
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    ll q, testcase = 1;
    if(multicase){
        cin >> q;
    }else{
        q = 1; 
    }
    while(q--){
        // pu("Case ");pu("#");pu(testcase);pu(": ");
        solve();
        testcase++;
    }
    // solve();
    return 0;
}