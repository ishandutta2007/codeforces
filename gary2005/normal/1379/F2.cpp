/**
 *    author:  gary
 *    created: 13.03.2022 17:25:55
**/
#pragma GCC target("avx,sse2,sse3,sse4,mmx")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define rep(a,b) for(int a=0;a<b;++a)
#define LL long long
#define PB push_back
#define POB pop_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define SRAND mt19937 rng(chrono::steady_clock::now().time_since_epoch().count())
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
const int N=1<<18;
struct node
{
    bool bad;int maxr,minl;
    node(){
        bad=false;
        maxr=INF;
        minl=-INF;
    }
    node(bool x,int y,int z){
        bad=x;
        maxr=y;
        minl=z;
    }
};
struct segmenttree{
    node tree[N+N];
    set<int> keepl[N+1],keepr[N+1];
    node merge(node A,node B){
        return node(A.bad|B.bad|(A.maxr<=B.minl),min(A.maxr,B.maxr),max(A.minl,B.minl));
    }
    void work(int x,int y){
        int xx,yy;
        bool ty;
        ty=x&1;
        xx=(x+1)/2;
        yy=(y+1)/2;
        // cout<<"----------"<<ty<<" "<<xx<<' '<<yy<<endl;
        if(ty){
            if(keepr[xx].find(yy)==keepr[xx].end()) keepr[xx].insert(yy);
            else keepr[xx].erase(yy);
        }
        else{
            if(keepl[xx].find(yy)==keepl[xx].end()) keepl[xx].insert(yy);
            else keepl[xx].erase(yy);
        }
        int pos=xx+N-1;
        tree[pos].maxr=(keepr[xx].empty()? INF:*keepr[xx].begin());
        tree[pos].minl=(keepl[xx].empty()? -INF:*keepl[xx].rbegin());
        tree[pos].bad=tree[pos].maxr<=tree[pos].minl;
        // cout<<tree[pos].maxr<<endl;
        pos>>=1;
        while (pos)
        {
            tree[pos]=merge(tree[pos<<1],tree[pos<<1|1]);
            pos>>=1;
        }
    }
}sgt;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m,q;
    cin>>n>>m>>q;
    set<mp> se;
    while (q--)
    {
        int x,y;
        cin>>x>>y;
        sgt.work(x,y);
        // cout<<sgt.tree[1].maxr<<" "<<sgt.tree[1].minl<<endl;
        if(!sgt.tree[1].bad) cout<<"YES\n";
        else cout<<"NO\n";
    }
    return 0;
}