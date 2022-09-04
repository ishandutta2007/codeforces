#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<algorithm>
#include<vector>
#include<map>
#include<utility>
#include<iostream>
#include<cmath>
#define LL long long
#define pll pair<LL,LL>
#define pii pair<int,int> 
#define pdd pair<double,double>
#define pb push_back
#define sqr(x) ((x)*(x))
#define mp make_pair
#define x first
#define y second
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
using namespace std;
//#define pii pair<int,int> 
#define N 100
bool isprime[N];
void Find(){
    fill(isprime,isprime+N,1);
    for(int i=2;i<N;i++){
        if(isprime[i]){
            for(int j=i*2;j<N;j+=i){
                isprime[j]=0;
            }
        }
    }
}
pll gcd(LL a, LL b){
    if(b == 0) return mp(1, 0);
    else{
        LL p = a / b;
        pll q = gcd(b, a % b);
        return make_pair(q.y, q.x - q.y * p);
    }
}
int mod=1000;
LL f_pow(int a,int b){
    LL res=1,temp=a;
    while(b){
        if(b&1)res=res*temp%mod;
        temp=temp*temp%mod;
        b>>=1;
    }
    return res;
}
int match[4005];
vector<int> vv[4005];
int vis[4005];
int vis2[4005];
bool dfs(int a){
    if(vis[a])
    return false;
    vis[a]=1;
    for(auto it:vv[a]){
        vis2[it]=1;
        if(match[it]==-1||dfs(match[it])){
            match[it]=a;
            return true;
        }
    }
    return false;
}
void Max_match(int n,int m){
    MEMS(match);
    vector<int> v;
    for(int i=0;i<n;i++){
        MEM(vis);
        if(dfs(i));
        else v.pb(i);
    }
    MEM(vis);
    MEM(vis2);
    for(auto it:v){
      //  printf("%d\n",it);
        dfs(it);
       // printf("%d",it);
    }/*
    for(int i=1;i<=n;i++){
        if(!vis[i])
        printf("%d ",i);
    }
    printf("\n");
    for(int i=1;i<=m;i++){
        if(vis2[i])
        printf("%d ",i);
    }
    printf("\n");*/
}
int f[4005];
int value[4005],ll[4005],rr[4005];
int Find(int a){
    if(f[a]==a)return a;
    return f[a]=Find(f[a]);
}
int main(){
    int n;
    scanf("%d",&n);
    map<int,vector<int> > h,v;
    vector<pair<pii,pii> > l,r;
    map<pii,int> index;
    pii p[1005];
    for(int i=0;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        h[y].pb(x);
        v[x].pb(y);
        index[mp(x,y)]=i;
        p[i]=mp(x,y);
    }
    for(auto it:h){
        sort(it.y.begin(),it.y.end());
        for(int i=1;i<it.y.size();i++){
            l.pb(mp(mp(it.y[i-1],it.x),mp(it.y[i],it.x)));
        }
    }
    for(auto it:v){
        sort(it.y.begin(),it.y.end());
        for(int i=1;i<it.y.size();i++){
            r.pb(mp(mp(it.x,it.y[i-1]),mp(it.x,it.y[i])));
        }
    }
    for(int i=0;i<l.size();i++){
        for(int j=0;j<r.size();j++){
            int x=r[j].x.x,y=l[i].y.y;
            if(y>=r[j].x.y&&y<=r[j].y.y&&x>=l[i].x.x&&x<=l[i].y.x){
                if((mp(x,y)!=r[j].x&&mp(x,y)!=r[j].y)||(mp(x,y)!=l[i].x&&mp(x,y)!=l[i].y))
                vv[i].pb(j);
            }
        }
    }
    Max_match(l.size(),r.size());
    for(int i=0;i<n;i++)
    f[i]=i;
    for(int i=0;i<l.size();i++){
        if(vis[i]){
           // printf("%d\n",i);
            int x=index[l[i].x];
            int y=index[l[i].y];
            int fx=Find(x);
            int fy=Find(y);
            f[fx]=fy;
        }
    }
    for(int i=0;i<n;i++){
        ll[i]=1e9+1;
        rr[i]=-1;
    }
    for(int i=0;i<n;i++){
        int fx=Find(i);
        value[fx]=p[i].y;
        ll[fx]=min(p[i].x,ll[fx]);
        rr[fx]=max(p[i].x,rr[fx]);
    }
    vector<pair<pii,pii> > ansh;
    for(int i=0;i<n;i++){
        if(Find(i)==i){
            ansh.pb(mp(mp(ll[i],value[i]),mp(rr[i],value[i])));
        }
    }
    for(int i=0;i<n;i++)
        f[i]=i;
    for(int i=0;i<r.size();i++){
        if(!vis2[i]){
            int x=index[r[i].x];
            int y=index[r[i].y];
            f[Find(x)]=Find(y);
        }
    }
    for(int i=0;i<n;i++){
        ll[i]=1e9+1;
        rr[i]=-1;
    }
    for(int i=0;i<n;i++){
        int fx=Find(i);
        value[fx]=p[i].x;
        ll[fx]=min(p[i].y,ll[fx]);
        rr[fx]=max(p[i].y,rr[fx]);
    }
    vector<pair<pii,pii> > ansv;
    for(int i=0;i<n;i++){
        if(Find(i)==i){
            ansv.pb(mp(mp(value[i],ll[i]),mp(value[i],rr[i])));
        }
    }
    printf("%d\n",ansh.size());
    for(auto it:ansh){
        printf("%d %d %d %d\n",it.x.x,it.x.y,it.y.x,it.y.y);
    }
    printf("%d\n",ansv.size());
    for(auto it:ansv){
        printf("%d %d %d %d\n",it.x.x,it.x.y,it.y.x,it.y.y);
    }
}