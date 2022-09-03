#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define less Less
#define EPS 1e-4
#define arg ARG
#define pdd pair<double,double>
#define cpdd const pdd
#define MXN 1500005
#define XXX 2520
vector<int> v[1005];
map<pii,int> m;
int Size[1005];
void dfs(int x,int f){
    Size[x]=1;
    for(auto it:v[x]){
        if(it!=f){
            dfs(it,x);
            Size[x]+=Size[it];
        }
    }
}
int now;
int dis[1005];
void dfs2(int x,int f,int pro){
 //   printf("%d\n",x);
    m[mp(x,f)]=min((now-dis[f])*pro,1000000);
    dis[x]=now;
    now++;
    for(auto it:v[x]){
        if(it!=f)
        dfs2(it,x,pro);
    }
}
int main(){
    int n;
    scanf("%d",&n);
    if(n==1){
        return 0;
    }
    for(int i = 0;i<n-1;i++){
        int a,b;
        scanf("%d %d",&a,&b);
        v[a].pb(b);
        v[b].pb(a);
    }
    int mid=-1;
    vector<int> l,r;
    for(int i = 1;i<=n;i++){
        dfs(i,0);
        int ok=1;
        for(auto it:v[i]){
            if(Size[it]>n/2){
                ok=0;
            }
        }
        vector<pii> tmp;
        if(ok){
          //  printf("%d\n",i);
            mid=i;
            for(auto it:v[i]){
                tmp.pb(mp(Size[it],it));
            }
            sort(tmp.begin(),tmp.end());
            reverse(tmp.begin(),tmp.end());
            int now=tmp[0].x;
            l.pb(tmp[0].y);
            while(now<(n-1)/3){
                now+=tmp.back().x;
                l.pb(tmp.back().y);
                tmp.pop_back();
            }
            while(tmp.size()!=1){
                r.pb(tmp.back().y);
                tmp.pop_back();
            }
            break;
        }
    }
   // printf("?\n");
    assert(mid!=-1);
    now=1;
    for(auto it:l){
        dfs2(it,mid,1);
    }
  //  printf("?\n");
    int pro=now;
    now=1;
    for(auto it:r){
        dfs2(it,mid,pro);
    }
    for(auto it:m){
        printf("%d %d %d\n",it.x.x,it.x.y,it.y);
    }
}
/*
1 4  2  3

*/