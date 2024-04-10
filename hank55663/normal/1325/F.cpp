#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define x first
#define LL long long
#define ULL unsigned long long 
#define y second
#define sqr(x) ((x)*(x))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<double,double>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
vector<int> stk;
int val[100005];
int need;
int vis[100005];
vector<int> inde;
int ok[100005];
vector<int> v[100005];
void dfs(int x,int f){
    //int ok=0;
    vis[x]=1;
    val[x]=stk.size();
    stk.pb(x);
    for(auto it:v[x]){
        if(it!=f){
            if(vis[it]&&val[it]!=-1){
                if(val[x]-val[it]+1>=need){
                    printf("2\n");
                    printf("%d\n",val[x]-val[it]+1);
                    for(int j = val[it];j<=val[x];j++){
                        printf("%d ",stk[j]);
                    }
                    printf("\n");
                    exit(0);
                }
            }
            else{
                if(!vis[it])
                dfs(it,x);
                //ok=1;
            }
        }
    }
    if(ok[x]){
        inde.pb(x);
        for(auto it:v[x]){
            ok[it]=0;
        }
    }
    stk.pop_back();
    val[x]=-1;
}
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    fill(ok,ok+n+1,1);
    for(int i = 1;;i++){
        if(i*i>=n){
            need=i;
            break;
        }
    }
    for(int i = 0;i<m;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(y);
        v[y].pb(x);
    }
    dfs(1,0);
    printf("1\n");
    for(int i=0;i<need;i++){
        printf("%d ",inde[i]);
    }
    printf("\n");
}
/*vector<int> prime;
int isprime[1000005];
void Find(){
     for(int i = 2;i<1000005;i++){
        if(isprime[i]==0){
             prime.pb(i);
             for(int j = i*2;j<1000005;j+=i)isprime[i]=1;
        }
     }
}   
vector<int> v[1000005];
int main(){
    int n;
    scanf("%d",&n);
    vector<int> v;
    for(int i = 2 ;i<=1000;i++){
        v.pb(i*i);
    }
    vector<int> ok;
    for(int i = 1;i<=n;i++){
        int x;
        scanf("%d",&x);
        for(auto it:v){
            while(x%it==0)x/=it;
        }
        if(x==1){
            printf("1\n");
            return 0;
        }
        if(isprime[x]==0)ok.pb(x);
        else{
            for(int j =2;j<1000;j++){
                if(x%j==0){
                    v[x/j].pb(j);
                    v[j].pb(x/j);
                    break;
                }
            }
        }
    }
    sort(ok.begin(),ok.end());
    for(int i = 1;i<ok.size();i++){
        if(ok[i]==ok[i-1]){
            printf("2\n");
            return 0;
        }
    }
}*/
/*
5
0 9 7 1 100
-1 0 -1 -1 91
-1 5 0 -1 96
-1 8 9 0 99
-1 -1 -1 -1 0
3 4
3 5
5 6
5 7
3 or 4
3 or 5
5 or 6
5 or 7

dp[x]=max(dp[x-w_i*j]+j*t_i-delta t_i*j*(j-1)/2)
dp[x]=max(dp[j]+x*t_i-j*t_i-delta t_i*(x-j)*(x-j-1)/2)
dp[x]=max(dp[j]-j*t_i-delta t_i *(j^2/2+j/2) - 
        delta t_i * xj + x*t_i + delta t_i * (x^2/2-x/2))
dp[x]=max(dp[j] + g(j) - delta t_i *xj + w(i) )
g(j)= dp[j]-j*t_i-delta t_i *(j^2/2+j/2)
w(i)=  x*t_i + delta t_i * (x^2/2-x/2)
x^2/2 -xj -x/2  +j^2/2 +j/2
*/