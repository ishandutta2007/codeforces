#include<bits/stdc++.h>
#pragma optimize(Ofast)
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
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
#define MXN 500005
vector<int> v[1005];
map<pii,int> m;
vector<int> q;
int need;
pii p;
void go(int x,int f){
    q.pb(x);
    if(need==0)return;
    for(auto it:v[x]){
        if(it!=f){
            need-=m[mp(x,it)];
            p=mp(x,it);
            go(it,x);
            if(need==0)return;
        }
    }
}
void solve(){
    int n;
    scanf("%d",&n);
    for(int i = 1;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(y);
        v[y].pb(x);
        m[mp(x,y)]=m[mp(y,x)]=1;
    }
    printf("? %d",n);
    for(int i = 1;i<=n;i++){
        printf(" %d",i);
    }
    printf("\n");
    fflush(stdout);
    int x;
    scanf("%d",&x);
    int tot=n-1;
    while(tot!=1){
        q.clear();
        need=tot/2;
        go(1,0);
        printf("? %d",q.size());
        for(auto it:q)printf(" %d",it);
        printf("\n");
        fflush(stdout);
        int y;
        scanf("%d",&y);
        if(x==y){
            tot=tot/2;
        }
        else{
            int vis[1005];
            MEM(vis);
            for(auto it:q){
                vis[it]=1;
            }
            tot=tot-tot/2;
            for(auto &it:m){
                if(vis[it.x.x]&&vis[it.x.y])it.y=0;
            }
        }
    }
    need=1;
    go(1,0);
    printf("! %d %d\n",p.x,p.y);
}
int main(){

    int t=1;0000;
   // scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        //cerr<<i<<endl;
        solve();
    }
    return 0;
}
/*
7
34 38 10
8 32 9
3 7 10
5 13 9
23 40 5
28 34 1
24 26 10
*/