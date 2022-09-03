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
vector<int> prime;
int isprime[1000005];
void Find(){
     for(int i = 2;i<1000005;i++){
        if(isprime[i]==0){
          //  printf("%d\n",i);
             prime.pb(i);
             for(int j = i*2;j<1000005;j+=i)isprime[j]=1;
        }
     }
}   
vector<int> v[1000005];
int dis[1000005];
int from[1000005];
int main(){
    int n;
    scanf("%d",&n);
    vector<int> vv;
    for(int i = 2 ;i<=1000;i++){
        vv.pb(i*i);
    }
    vector<int> ok,ok2;
    Find();
    for(int i = 1;i<=n;i++){
        int x;
        scanf("%d",&x);
        for(auto it:vv){
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
             //      printf("%d %d\n",j,x/j);
                    break;
                }
            }
            ok2.pb(x);
        }
    }
    sort(ok.begin(),ok.end());
    for(int i = 1;i<ok.size();i++){
        if(ok[i]==ok[i-1]){
            printf("2\n");
            return 0;
        }
    }
    sort(ok2.begin(),ok2.end());
    for(int i = 1;i<ok.size();i++){
        if(ok[i]==ok[i-1]){
            printf("2\n");
            return 0;
        }
    }
    queue<int> q;
    MEMS(dis);
    for(auto it:ok){
        dis[it]=0;
        q.push(it);
    }
    int ans=1e9;
    while(!q.empty()){
        int x=q.front();
        q.pop();
        for(auto it:v[x]){
            if(dis[it]==-1){
                dis[it]=dis[x]+1;
                from[it]=x;
                q.push(it);
            }
            else{
                if(from[x]==it);
                else{
                    ans=min(ans,dis[it]+dis[x]+1+2);
                }
            }
        }
    }
    for(auto it:prime){
        if(it>1000)break;
        for(auto it2:prime)dis[it2]=-1;
        dis[it]=0;
        queue<int> q;
        q.push(it);
        while(!q.empty()){
            int x=q.front();
            q.pop();
            for(auto it2:v[x]){
                if(dis[it2]==-1){
                    dis[it2]=dis[x]+1;
                    from[it2]=x;
                    q.push(it2);
                }
                else{
                    if(from[x]==it2);
                    else{
                        ans=min(ans,dis[x]+dis[it2]+1);
                    }
                }
            }
        }
    }
    if(ans==1e9){
        printf("-1\n");
    }
    else{
        printf("%d\n",ans);
    }
}
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