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
#define MEM(x) memset(x,0,sizeof(x)
vector<int> v[500005];
int Size[500005];
LL dp[500005][2];
int n;
bool cmp(const int &a,const int &b){
    if(Size[a]!=Size[b])
    return Size[a]>Size[b];
    else
    return dp[a][1]>dp[b][1];
}
LL inf = 1e18;
void dfs(int x,int f){
    Size[x]=1;
    dp[x][0]=dp[x][1]=1e18;
    for(auto it:v[x]){
        if(it!=f){
            dfs(it,x);
            Size[x]+=Size[it];
        }
    }
    dp[x][1]=(LL)Size[x]*Size[x];
    vector<int> tmp;
    for(auto it:v[x]){
        if(it!=f){
            LL val=Size[x]-Size[it];
            dp[x][1]=min(dp[x][1],dp[it][1]+val*val);
           // printf("%lld %lld %lld\n",val,dp[x][1],dp[it][1]);
            dp[x][0]=min(dp[x][0],dp[it][0]); 
            tmp.pb(it);
        }
    }
    sort(tmp.begin(),tmp.end(),cmp);
    vector<pair<LL,pll> > v;
    v.pb(mp(1e18,mp(1e9,1e18)));
    for(auto it:tmp){
        int a=Size[it]*2;
        LL b=dp[it][1]+(LL)Size[it]*Size[it] - (LL)Size[it]*n*2;
        LL add = b+(LL)n*n;
        pair<LL,pll> p=*lower_bound(v.begin(),v.end(),mp((LL)a,mp(-inf,-inf)));
       // printf("!%lld %lld %lld\n",p.y.x,p.y.y,add);
        dp[x][0]=min(dp[x][0],Size[it]*p.y.x+p.y.y+add);
        while(true){
            auto it=v.back();
            v.pop_back();
            if(it.y.x==a){
                continue;
            }
            LL x=(b-it.y.y)/(it.y.x-a);
            if(!v.empty()&&x<=v.back().x){
                continue;
            }
            v.pb(mp(x,it.y));
            break;
        }
        v.pb(mp(1e18,mp(a,b)));
    }
    //printf("%d %lld %lld\n",x,dp[x][0],dp[x][1]);
}
int main(){
    scanf("%d",&n);
    for(int i =1;i<n;i++){
        int x=1,y=i+1;
        scanf("%d %d",&x,&y);

        v[x].pb(y);
        v[y].pb(x);
    }
    dfs(1,0);
    printf("%lld\n",((LL)n*n*2-min(dp[1][0],dp[1][1])-n)/2);
}
/*
m3->m2->m->m4
0 1 2 3 453*
0 1 3 2 4 4 2
0 1 4 2 3 3 2
0 2 1 3 4
0 2 3 1 4 4 1
0 2 4 1 3 3 1
0 3 1 2 4 4 2
0 3 2 1 4 4 1
0 4 1 
0 4 2
0 4 3

*/