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
#define pi acosl(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MAXN 205
//#define N 262144
#define ULL unsigned long long
#define ll long long
vector<int> v[100005];
vector<int> a[2];
int vis[100005];
int instk[100005];
vector<int> stk;
int k;
int ans=1e9;
void dfs(int x,int y,int d){
    a[d&1].pb(x);
    vis[x]=1;
    instk[x]=stk.size()+1;
    stk.pb(x);
    for(auto it:v[x]){
        if(it!=y){
            if(vis[it]&&instk[it]){
                ans=min(ans,instk[x]-instk[it]+1);
                continue;
            }
            if(!vis[it])
            dfs(it,x,d+1);
        }
    }
    stk.pop_back();
    instk[x]=0;
}
void dfs2(int x,int y){
    vis[x]=1;
    instk[x]=stk.size()+1;
    stk.pb(x);
    for(auto it:v[x]){
        if(it!=y){
            if(vis[it]&&instk[it]){
                if(instk[x]-instk[it]+1==ans){
                    vector<int> vv;
                    while(stk.back()!=it)vv.pb(stk.back()),stk.pop_back();
                    vv.pb(it);
                    
                    if(vv.size()<=k){
                        printf("2\n%d\n",vv.size());
                        for(auto it:vv){
                            printf("%d ",it);
                        }
                        printf("\n");
                        exit(0);
                    }
                    else{
                        printf("1\n");
                        k=(k+1)/2;
                        for(int i = 0;k;i+=2,k--){
                            printf("%d ",vv[i]);
                        }
                        printf("\n");
                        exit(0);
                    }
                }
            }
            if(!vis[it])
            dfs2(it,x);
        }
    }
    stk.pop_back();
    instk[x]=0;
}
int main(){
    int n,m;
    scanf("%d %d %d",&n,&m,&k);
    for(int i = 0;i<m;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(y);
        v[y].pb(x);
    }
    if(m==n-1){
        dfs(1,0,0);
        printf("1\n");
        int kk=1;;
        k++;
        if(a[0].size()>=k/2){
            kk=0;
        }
        for(int i = 0;i<k/2;i++){
            printf("%d ",a[kk][i]);
        }
    }
    else{
        dfs(1,0,0);
        MEM(vis);
        MEM(instk);
        stk.clear();
        dfs2(1,0);
    }
}