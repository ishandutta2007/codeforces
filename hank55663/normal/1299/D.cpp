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
//#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define ld long double
//#define N 6000005
#define rank Rank
#define index Index
#define MXN 100005
vector<pii> v[100005];
//vector<int> cycle2;
int cycle2;
vector<pll> v1;
int vis[100005];
int vis2[100005][32];
ULL from[100005][32];
int go1=0,v2;
vector<int> stk;
vector<int> tmp;
int val[100005];
int instk[100005];
void dfs(int x,int f){
    vis[x]=1;
    stk.pb(x);
    instk[x]=1;
    for(auto it:v[x]){
        if(it.x!=f){
            if(it.x==1){
                go1=1;
                v2=x;
                cycle2=val[x]^it.y;
                continue;
            }
            if(!vis[it.x]){
                val[it.x]=val[x]^it.y;
                dfs(it.x,x);
            }
            else{
                if(instk[it.x]){
                    tmp.pb(val[it.x]^it.y^val[x]);
                    //printf("%d\n",tmp.back());
                }
            }
        }    
    }
    instk[x]=0;
}
int num[32][32][32][32][32];
int go[400][32];
int dp[2][400];
void build(){
    queue<pair<vector<int>,int> > q;
    q.push(mp(vector<int>{0,0,0,0,0},0));
    MEMS(num);
    num[0][0][0][0][0]=0;
    int now=1;
    while(!q.empty()){
        vector<int> v;
        int number;
        tie(v,number)=q.front();
        q.pop();
        while(!v.empty()&&v.back()==0)v.pop_back();
        for(int j =0;j<32;j++){
            vector<int> tmp=v;
            int add=j;
            for(auto &it:tmp){
                if(it<add)swap(it,add);
                add=min(add,add^it);
                //printf("%d %d\n",it,add);
            }
           // printf("?%d\n",add);
            if(add){
                tmp.pb(add);
                for(int i = 0;i<tmp.size();i++){
                    for(int j=i+1;j<tmp.size();j++){
                        tmp[i]=min(tmp[i],tmp[i]^tmp[j]);
                    }
                }
            }
            if(tmp.size()==v.size()){
                go[number][j]=-1;
            }
            else{
                while(tmp.size()<5)tmp.pb(0);
                if(num[tmp[0]][tmp[1]][tmp[2]][tmp[3]][tmp[4]]==-1){
                    num[tmp[0]][tmp[1]][tmp[2]][tmp[3]][tmp[4]]=now;
                   /* for(auto it:v)printf("%d ",it);
                    printf(" %d %d\n",j,add);
                    for(auto it:tmp)printf("%d ",it);
                    printf("%d\n",now);*/
                   // getchar();
                    q.push(mp(tmp,now++));
                }
                go[number][j]=num[tmp[0]][tmp[1]][tmp[2]][tmp[3]][tmp[4]];
            }
        }
    }
}
int mod=1e9+7;
int main(){
    srand(time(NULL));
    int n,m;
    scanf("%d %d",&n,&m);
    for(int i = 0;i<m;i++){
         int x,y,w;
         scanf("%d %d %d",&x,&y,&w);
         v[x].pb(mp(y,w));
         v[y].pb(mp(x,w));
    }
    for(auto it:v[1]){
        if(!vis[it.x]){
            val[it.x]=it.y;
            go1=0;
            dfs(it.x,1);
            vector<int> tmp2;
            for(auto it:tmp){
               // if(m==59)printf("%d ",it);
                for(auto &it2:tmp2){
                    if(it2<it)swap(it,it2);
                    it=min(it,it^it2);
                }
                for(auto &it2:tmp2){
                    it2=min(it2,it^it2);
                }
                if(it)
                tmp2.pb(it);
            }
            //if(m==59)printf("\n");
            if(tmp2.size()==tmp.size()){
                LL res=0;
                for(auto it:tmp2){
                    res+=(1ll<<it);
                }
                if(go1){
                    v1.pb(mp(res,cycle2));
                }
                else{
                    v1.pb(mp(res,-1));
                }
            }
            tmp.clear();
        }
    }
    build();
    dp[0][0]=1;
    int index=0;
    for(auto it:v1){
        index^=1;
        for(int i=0;i<374;i++){
            dp[index][i]+=dp[index^1][i];
            dp[index][i]%=mod;
            int now=i;
            for(int j=0;j<32;j++){
                if(it.x&(1<<j)){
                    now=go[now][j];
                }
                if(now==-1){
                    break;
                }
            }
            if(now!=-1){
                dp[index][now]+=dp[index^1][i];
                dp[index][now]%=mod;
                if(it.y!=-1){
                    dp[index][now]+=dp[index^1][i];
                    dp[index][now]%=mod;
                    now=go[now][it.y];
                    if(now!=-1){
                        dp[index][now]+=dp[index^1][i];
                        dp[index][now]%=mod;
                    }
                }
            }
        }
        MEM(dp[index^1]);
    }
    LL ans=0;
    for(int i=0;i<374;i++)ans+=dp[index][i];
    printf("%lld\n",ans%mod);
}
/*
7 8
1 3 1
2 3 9
2 4 3
2 5 4
4 5 7
3 6 6
3 7 7
6 7 8

*/