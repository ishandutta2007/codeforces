/**
 *    author:  gary
 *    created: 15.10.2022 22:25:54
**/
#include<bits/stdc++.h>
// #include<ext/pb_ds/assoc_container.hpp>
// #include<ext/pb_ds/hash_policy.hpp>
#define rb(a,b,c) for(int a=(b);a<=(c);++a)
#define rl(a,b,c) for(int a=(b);a>=(c);--a)
#define rep(a,b) for(int a=0;a<(b);++a)
#define LL long long
#define II(a,b) make_pair(a,b)
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
// using namespace __gnu_pbds;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
const int MAXN=300000+20;
struct BIT{
    LL tree[MAXN];
    void clear(){memset(tree,0,sizeof(tree));}
    void add(int pos,LL val){
        while(pos<MAXN){tree[pos]+=val;pos+=pos&-pos;}
    }
    LL query(int pos){
        LL s=0;
        while(pos){
            s+=tree[pos];
            pos-=pos&-pos;
        }
        return s;
    }
    LL query(LL l,LL r){
        return query(r)-query(l-1);
    }
    BIT(){clear();}
}ds;
SRAND;
/**/ 

const int SIZE=(1<<23)-1;
struct Hash_Table{
    int tp[SIZE+1];
    vector<int> keys;
    vector<long long> vals;
    vector<int> nex;
    Hash_Table(){rb(i,0,SIZE) tp[i]=-1;}
    void insert_edge(int X,long long Y){
        auto Has=X^(X>>7);
        Has&=SIZE;
        nex.push_back(tp[Has]);
        keys.push_back(X);
        vals.push_back(Y);
        tp[Has]=nex.size()-1;
    }
    long long query_edge(int X){
        auto Has=X^(X>>7);
        Has&=SIZE;
        for(int now=tp[Has];now!=-1;now=nex[now]) if(keys[now]==X) return vals[now];
        return -1;
    }
};
long long RNG(){
    unsigned long long x=0;
    x^=rng();
    x^=x<<15;
    x^=rng();
    x^=x<<15;
    x^=rng();
    return x%(long long)(1e12);
}
int a[MAXN],b[MAXN];LL ha[MAXN];
bool ans[MAXN];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,q;
    cin>>n>>q;
    rb(i,1,n){
        cin>>a[i];
        b[i]=a[i];
    }
    vector<tuple<int,int,int,int> > v;
    rb(i,1,q){
        ans[i-1]=1;
        int t;
        cin>>t;
        if(t==2){
            int l,r,k;
            cin>>l>>r>>k;
            v.emplace_back(t,l,r,k);
            if((r-l+1)%k) ans[i-1]=0;
        }
        else{
            int i,x;
            cin>>i>>x;
            v.emplace_back(t,i,x,0);
        }
    }
    rep(T,30){
        Hash_Table A;
        ds.clear();
        rb(i,1,n) {a[i]=b[i];if(A.query_edge(a[i])==-1) A.insert_edge(a[i],RNG());ha[i]=A.query_edge(a[i]);ds.add(i,ha[i]);}
        rep(j,q){
            if(get<0>(v[j])==2){
                if(!ans[j]) continue;
                int l=get<1>(v[j]),r=get<2>(v[j]),k=get<3>(v[j]);
                ans[j]=ds.query(l,r)%k==0;
            }
            else{
                int i=get<1>(v[j]),x=get<2>(v[j]);
                a[i]=x;
                if(A.query_edge(a[i])==-1) A.insert_edge(a[i],RNG());
                auto pre=ha[i];
                ha[i]=A.query_edge(a[i]);
                ds.add(i,ha[i]-pre);
            }
        }
    }
    rep(i,q){
        if(get<0>(v[i])==2){
            cout<<(ans[i]? "YES":"NO")<<'\n';
        }
    }
    return 0;
}