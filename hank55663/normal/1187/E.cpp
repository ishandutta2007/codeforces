#include<bits/stdc++.h>
using namespace std;
#define LL long long
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
#define MXN 10005
#define less Less
#define N (1<<20)
typedef complex<double> C;
vector<int> v[200005];
int Size[200005];
LL ans;
int n;
void dfs(int x,int f){
    Size[x]=1;
    for(auto it:v[x]){
        if(it!=f){
            dfs(it,x);
            Size[x]+=Size[it];
        }
    }
}
void dfs2(int x,int f,LL sum){
    ans=max(ans,sum);
    for(auto it:v[x]){
        if(it!=f){
            dfs2(it,x,sum-Size[it]-Size[it]+n);
        }
    }
}
int main(){
    scanf("%d",&n);
    for(int i = 1;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(y);
        v[y].pb(x);
    }
    dfs(1,0);
    LL sum=0;
    for(int i = 1;i<=n;i++){
        sum+=Size[i];
    }
    //printf("%lld\n",sum);
    dfs2(1,0,sum);
    printf("%lld\n",ans);
}
/*
1 
2 6 
3 5 
4
*/