/**
 *    author:  gary
 *    created: 18.01.2022 13:30:36
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
int n,m,q;
int get(int x,int y){
    return x*m*2-m*2+y;
}
const int MAXN=2*3001*3000+1;
int walk[8][2]={{0,1},{0,-1},{1,0},{-1,0},{1,-1},{1,1},{-1,1},{-1,-1}};
int fa[MAXN],id[MAXN],cnt=0;
bool land[3003][6003];
bitset<6003> bs[6003];
int root(int x){
    return fa[x]=(fa[x]==x? x:root(fa[x]));
}
void merge(int u,int v){
    u=root(u);
    v=root(v);
    fa[u]=v;
    if(id[v]&&id[u]) bs[id[v]]|=bs[id[u]];
    else if(id[u]) id[v]=id[u];
}
bool check(int u,int v){
    if(!id[u]||!id[v]) return true;
    return ((bs[id[u]]>>n)&bs[id[v]]).count()==0&&((bs[id[v]]>>n)&bs[id[u]]).count()==0;
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>q;
    rb(i,1,2*n*m) fa[i]=i;
    rb(i,1,n) id[get(i,1)]=++cnt,bs[cnt].set(i);
    rb(i,1,n) id[get(i,m+1)]=++cnt,bs[cnt].set(i+n);
    if(m==1){
        cout<<0<<endl;
        return 0;
    }
    rb(T,1,q){
        int r,c;
        cin>>r>>c;
        (c+=33)%=m;
        c++;
        set<int> r1,r2;
        r1.insert(get(r,c));
        r2.insert(get(r,c+m));
        rep(k,8){
            int nx,ny;
            tie(nx,ny)=II(r+walk[k][0],c+walk[k][1]);
            if(ny==0) ny=2*m;
            if(ny==2*m+1) ny=1;
            if(land[nx][ny]) r1.insert(root(get(nx,ny)));
            tie(nx,ny)=II(r+walk[k][0],c+m+walk[k][1]);
            if(ny==0) ny=2*m;
            if(ny==2*m+1) ny=1;
            if(land[nx][ny]) r2.insert(root(get(nx,ny)));
        }
        bool con=false;
        for(auto ite=r1.begin();ite!=r1.end();ite++) for(auto ite2=r2.begin();ite2!=r2.end();ite2++) con|=*ite==*ite2;
        if(con){
            for(auto ite=r2.begin();ite!=r2.end();ite++) r1.insert(*ite);
            r2.clear();
        }
        vector<int> v1,v2;
        for(auto ite=r1.begin();ite!=r1.end();ite++) v1.PB(*ite);
        for(auto ite=r2.begin();ite!=r2.end();ite++) v2.PB(*ite);
        bool can=true;
        rep(i,v1.size()) rep(j,i) can&=check(v1[i],v1[j]);
        rep(i,v2.size()) rep(j,i) can&=check(v2[i],v2[j]);
        if(can){
            rep(i,v1.size()) if(i) merge(v1[i-1],v1[i]);
            rep(i,v2.size()) if(i) merge(v2[i-1],v2[i]);
            land[r][c]=land[r][c+m]=1;
        }
    }
    int answer=0;
    rb(i,1,n) rb(j,1,m) answer+=land[i][j];
    cout<<answer<<endl;
    return 0;
}