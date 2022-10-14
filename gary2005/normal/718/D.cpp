/*
{
######################
#       Author       #
#        Gary        #
#        2021        #
######################
*/
#include<bits/stdc++.h>
#define rb(a,b,c) for(int a=b;a<=c;++a)
#define rl(a,b,c) for(int a=b;a>=c;--a)
#define LL long long
#define IT iterator
#define PB push_back
#define II(a,b) make_pair(a,b)
#define FIR first
#define SEC second
#define FREO freopen("check.out","w",stdout)
#define rep(a,b) for(int a=0;a<b;++a)
#define SRAND mt19937 rng(time(0))
#define random(a) rng()%a
#define ALL(a) a.begin(),a.end()
#define POB pop_back
#define ff fflush(stdout)
#define fastio ios::sync_with_stdio(false)
#define check_min(a,b) a=min(a,b)
#define check_max(a,b) a=max(a,b)
using namespace std;
//inline int read(){
//    int x=0;
//    char ch=getchar();
//    while(ch<'0'||ch>'9'){
//        ch=getchar();
//    }
//    while(ch>='0'&&ch<='9'){
//        x=(x<<1)+(x<<3)+(ch^48);
//        ch=getchar();
//    }
//    return x;
//}
const int INF=0x3f3f3f3f;
typedef pair<int,int> mp;
/*}
*/
const int MAXN=1e5+1;
int n;
vector<int> g[MAXN];
map<unsigned LL ,int> ans;
unsigned LL ky[MAXN];
int siz[MAXN];
unsigned LL ran[MAXN];
void trans(int now,int pre,int sz){
    ky[now]=1;
    vector<pair<unsigned LL,int> > v;
    for(auto it:g[now]) if(it!=pre) v.PB(II(ky[it],siz[it]));
    sort(ALL(v));
    rep(i,v.size()){
        ky[now]+=v[i].FIR*ran[v[i].SEC];
    }
}
void dfs(int now,int pre){
    siz[now]=1;
    for(auto it:g[now]) if(it!=pre) dfs(it,now),siz[now]+=siz[it];
    trans(now,pre,siz[now]);
}
void mv(int now,int pre){
    if(g[now].size()<4)
    ans[ky[now]]=1;
    for(auto it:g[now]) if(it!=pre){
        unsigned LL mem1,mem2;
        mem1=ky[now];
        mem2=ky[it];
        int A,B;
        A=siz[now];
        B=siz[it];
        siz[now]=n-B;
        siz[it]=n;
        trans(now,it,A-B);
        trans(it,0,n);
        mv(it,now);
        siz[now]=A;
        siz[it]=B;
        ky[now]=mem1;
        ky[it]=mem2;
    }
}
bool check(int x){
    for(int i=2;i*i<=x;i++){
        if(x%i==0) return 0;
    }
    return 1;
}
int main(){
    vector<int> pr;
    int now=2;
    while(pr.size()<1e5){
        if(check(now)) pr.PB(now);
        now++;
    }
    rb(i,1,1e5) ran[i]=pr[i-1];
    scanf("%d",&n);
    rb(i,1,n-1){
        int u,v;
        scanf("%d%d",&u,&v);
        g[u].PB(v);
        g[v].PB(u);
    }
    dfs(1,0);
    mv(1,0);
    cout<<ans.size()<<endl;
    return 0;
}