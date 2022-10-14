/**
 *    author:  gary
 *    created: 09.04.2022 23:14:46
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
const int M=877;
map<vector<int>,int> id;
vector<vector<int> > a;
const int N=1<<19;
void dfs(vector<int> v,int tmp=0){
    if(v.size()==6){
        id[v]=a.size();
        a.PB(v);
        return;
    }
    rb(i,0,tmp){
        v.PB(i);
        dfs(v,tmp+(i==tmp));
        v.pop_back();
    }
    v.PB(6);
    dfs(v,tmp);
    v.pop_back();
}
int to[M][M],cont[M][M];
int fa[14];
int root(int x){return fa[x]=(fa[x]==x? x:root(fa[x]));}
int tree[N+N],sum[N+N];
void pu(int x){
    // cerr<<tree[x<<1]<<' '<<tree[x<<1|1]<<endl;
    tree[x]=to[tree[x<<1]][tree[x<<1|1]];
    sum[x]=sum[x<<1]+sum[x<<1|1]+cont[tree[x<<1]][tree[x<<1|1]];
}
char c[3][N];
mp query(int a,int b,int now=1,int l=1,int r=N+1){
    if(r<=b&&l>=a) return {tree[now],sum[now]};
    int mid=(l+r)>>1;
    if(mid>=b) return query(a,b,now<<1,l,mid);
    if(mid<=a) return query(a,b,now<<1|1,mid,r);
    auto L=query(a,b,now<<1,l,mid),R=query(a,b,now<<1|1,mid,r);
    return II(to[L.first][R.first],L.second+R.second+cont[L.first][R.first]);
}
void debug(vector<int> A,vector<int> B){
    for(auto it:a[to[id[A]][id[B]]]){
        cout<<it<<' ';
    }
    cout<<endl;
}
int main(){
    dfs({});
    // cout<<a.size()<<endl;
    rep(i,M) rep(j,M){
        rep(k,14) fa[k]=k;
        auto L=a[i];
        auto R=a[j];
        for(auto &it:R) it+=7;
        if(L[3]!=6&&R[0]!=13)
        fa[root(L[3])]=root(R[0]);
        if(L[4]!=6&&R[1]!=13)
        fa[root(L[4])]=root(R[1]);
        if(L[5]!=6&&R[2]!=13)
        fa[root(L[5])]=root(R[2]);
        vector<int> nw(6);
        vector<int> tmp(6);
        tmp[0]=L[0],tmp[1]=L[1],tmp[2]=L[2];
        tmp[3]=R[3],tmp[4]=R[4],tmp[5]=R[5];
        int cnt=0;
        rep(k,6){
            if(tmp[k]==6||tmp[k]==13) nw[k]=6;
            else{
                int ok=-1;
                rep(l,k) if(root(tmp[l])==root(tmp[k])) ok=nw[l];
                if(ok==-1) ok=cnt++;
                nw[k]=ok;
            }
        }
        to[i][j]=id[nw];
        vector<int> drop(6);
        drop[0]=R[0],drop[1]=R[1],drop[2]=R[2];
        drop[3]=L[3],drop[4]=L[4],drop[5]=L[5];
        rep(k,6){
            if(drop[k]==6||drop[k]==13);
            else{
                bool ok=1;
                rep(l,k) if(root(drop[l])==root(drop[k])) ok=0;
                if(ok){
                    rep(z,6) if(root(tmp[z])==root(drop[k])) ok=0;
                    if(ok) cont[i][j]++;
                }
            }
        }
    }
    int n;
    scanf("%d",&n);
    rep(i,3) scanf("%s",c[i]+1);
    rb(i,1,n){
        int cnt=0;
        vector<int> tmp;
        if(c[0][i]=='1') tmp.PB(cnt++);
        else tmp.PB(6);
        if(c[1][i]=='1'){
            if(tmp.back()!=6) tmp.PB(cnt-1);
            else tmp.PB(cnt++);
        }
        else tmp.PB(6);
        if(c[2][i]=='1'){
            if(tmp.back()!=6) tmp.PB(cnt-1);
            else tmp.PB(cnt++);
        }
        else tmp.PB(6);
        // cerr<<tmp.size()<<endl;
        vector<int> is=tmp;
        is.PB(tmp[0]);
        is.PB(tmp[1]);
        is.PB(tmp[2]);
        // cout<<id[is]<<endl;
        tree[i+N-1]=id[is];
    }
    // debug({0,0,6,0,0,6},{6,0,0,6,0,0});
    rl(i,N-1,1) pu(i);
    int q;
    scanf("%d",&q);
    while (q--){
        int l,r;
        scanf("%d%d",&l,&r);
        r++;
        auto rest=query(l,r);
        set<int> se;
        for(auto it:a[rest.first]){
            // cout<<it<<' ';
            if(it!=6) se.insert(it);
        }
        // cout<<endl;
        printf("%d\n",(int)(rest.second+se.size()));
    }
    return 0;
}