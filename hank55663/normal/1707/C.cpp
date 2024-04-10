#include<bits/stdc++.h>
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
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define double long double
using namespace std;
vector<int> v[100005];
int f[100005];
int Find(int x){
    if(f[x]==x)return x;
    return f[x]=Find(f[x]);
}
int in[100005],out[100005];
int now=0;
void dfs(int x,int f){
    in[x]=++now;
    for(auto &it:v[x]){
        if(it!=f){
            dfs(it,x);
        }
        else{
            swap(it,v[x].back());
            if(it!=f)dfs(it,x);
        }
    }
    if(v[x].size()&&v[x].back()==f)
    v[x].pop_back();
    out[x]=now;
}
int S[100005];
int ok[100005];
void solve(){  
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i=1;i<=n;i++)f[i]=i;
    vector<pii> edge;
    for(int i = 1;i<=m;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        if(Find(x)!=Find(y)){
            f[Find(x)]=Find(y);
            v[x].pb(y);
            v[y].pb(x);
        }
        else{
            edge.pb(mp(x,y));
        }
    }
    dfs(1,0);
    for(auto it:edge){
        if(in[it.x]>in[it.y])swap(it.x,it.y);
        if(in[it.x]<=in[it.y]&&out[it.x]>=in[it.y]){
            S[1]++;
            //S[in[it.x]+1]--;
           // S[out[it.x]+1]++;
            int Min=0,Max=v[it.x].size();
            while(Min+1<Max){
                int mid=(Max+Min)/2;
                if(in[v[it.x][mid]]<=in[it.y])Min=mid;
                else Max=mid;
            }
         //   assert(in[v[it.x][Min]]>=)
            S[in[v[it.x][Min]]]--;
            S[out[v[it.x][Min]]+1]++;
            S[in[it.y]]++;
            S[out[it.y]+1]--;
        }
        else{
            S[in[it.x]]++;
            S[out[it.x]+1]--;
            S[in[it.y]]++;
            S[out[it.y]+1]--;
        }
    }
    int now=0;
    for(int i = 1;i<=n;i++){
        now+=S[i];
        if(now==edge.size())ok[i]=1;
        else ok[i]=0;
    }
    for(int i = 1;i<=n;i++){
        printf("%d",ok[in[i]]);
    }
    printf("\n");
}
int main(){
    int t=1;
    //scanf("%d",&t);
    //printf("\"");
    while(t--){
        // cerr<<t<<endl;
        solve();
     //   cerr<<t<<endl;
    }
    
   // cerr<<cnt<<endl;
}
/*
*/