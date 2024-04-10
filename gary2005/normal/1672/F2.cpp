/**
 *    author:  gary
 *    created: 24.04.2022 12:47:36
**/
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
int n,a[200000+20],b[200000+20],cnt[200000+20],fa[200000+20],mxdeg[200000+20],deg[200000+20],era[200000+20];
vector<int> g[200000+20];
int root(int x){
    return fa[x]=(fa[x]==x? x:root(fa[x]));
}
vector<mp> edges;
void connect(int u,int v){
    deg[u]++;
    fa[root(u)]=root(v);
    edges.PB(II(u,v));
}
void solve(){
    edges.clear();
    cin>>n;
    rb(i,1,n) fa[i]=i,cnt[i]=0,mxdeg[i]=0,deg[i]=0,g[i].clear(),era[i]=0;
    rb(i,1,n) cin>>a[i],cnt[a[i]]++;
    rb(i,1,n) cin>>b[i],connect(a[i],b[i]);
    rb(i,1,n) check_max(mxdeg[root(i)],deg[i]);
    int s=0;
    rb(i,1,n) s+=mxdeg[i];
    s-=*max_element(cnt+1,cnt+1+n);
    rb(i,1,n) if(deg[i]==mxdeg[root(i)]){
        mxdeg[root(i)]=-1;
        era[i]=1;
    }
    int cnt2=0;
    rb(i,1,n) deg[i]=0;
    for(auto it:edges){
        int u,v;
        tie(u,v)=it;
        if(era[u]||era[v]) continue;
        deg[v]++;
        g[u].PB(v);
    }
    queue<int> q;
    rb(i,1,n) if(!deg[i]) q.push(i);
    while (!q.empty()){
        cnt2++;
        int now=q.front();
        q.pop();
        for(auto it:g[now]){
            deg[it]--;
            if(!deg[it]) q.push(it);
        }
    }
    if(s==0&&cnt2==n) cout<<"AC\n";
    else cout<<"WA\n";
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        solve();
    }
    
    return 0;
}