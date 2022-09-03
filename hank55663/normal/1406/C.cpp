#include<bits/stdc++.h>

/*#pragma GCC optimize("Ofast")
#pragma GCC optimize ("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")*/
#define mp make_pair
#define pb push_back
#define pll pair<LL,LL>
#define pii pair<int,int>
#define y second
#define x first
#define LL long long 
#define ULL unsigned long long 
#define sqr(x) ((x)*(x))
#define pi acos(-1)
#define pdd pair<double,double>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
vector<int> v[100005];
int Size[100005];
vector<pii> stk;
int in[100005],out[100005];
int t;
void dfs(int x,int f){
    Size[x]=1;
    in[x]=++t;
    for(auto it:v[x]){
        if(it!=f){
            dfs(it,x);
            Size[x]+=Size[it];
        }
    }
    out[x]=t;
    stk.pb(mp(Size[x],x));
}
void solve(){
    int n;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)v[i].clear();
    for(int i = 1;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(y);
        v[y].pb(x);
    }
    stk.clear();
    dfs(1,0);
    sort(stk.begin(),stk.end());
    int a,b;
    for(int i = 1;i<=n;i++){
        if(v[i].size()==1){
            a=i,b=v[i][0];
        }
    }
    for(int i = 0;i<stk.size();i++){
        auto it=stk[i];
        if(it.x*2>=n){
            if(it.x*2>n){
                printf("%d %d\n",a,b);
                printf("%d %d\n",a,it.y);
            }
            else{
                printf("%d %d\n",a,b);
                //printf("%d %d %d\n",in[a],in[it.y],out[it.y]);
                if(in[a]>=in[it.y]&&in[a]<=out[it.y]){
                    printf("%d %d\n",a,stk[i+1].y);
                }
                else{
                    printf("%d %d\n",a,it.y);
                }
                
            }
            return;
        }
    }
}

int main(){
    int t=1;
    scanf("%d",&t);
    int n;
    while(t--){
        solve();
    }
}
/*
32 16 15 20 13 2 1
16 8 25 30 10 0 0
5 6 30 24 16 1 1
18 21 39 12 30 1 1
10 8 29 13 36 1 1
24 25 30 31 3 0 0
21 22 10 27 33 0 0
*/