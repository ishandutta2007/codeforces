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
#define N 200005
#define less Less
int a[100005];
int sum[100005][2];
int val[100005];
vector<int> v[100005];
LL tot=0;
void dfs(int x,int f){
    for(auto it:v[x]){
        if(it!=f){
            dfs(it,x);
            sum[x][0]+=sum[it][0];
            sum[x][1]+=sum[it][1];
        }
    }
    sum[x][0]++;
    if(val[x])swap(sum[x][0],sum[x][1]);
    tot+=sum[x][1];
 //   printf("%d %d %d %d\n",x,sum[x][0],sum[x][1],val[x]);
}
void dfs2(int x,int f,int sum0,int sum1){
   // printf("%d %d %d\n",x,sum0,sum1);
    if(val[x])swap(sum0,sum1);
    tot+=sum1;
    sum0+=sum[x][0];
    sum1+=sum[x][1];
    for(auto it:v[x]){
        if(it!=f){
            if(val[x]){
                dfs2(it,x,sum0-sum[it][1],sum1-sum[it][0]);
            }
            else{
                dfs2(it,x,sum0-sum[it][0],sum1-sum[it][1]);
            }
        }
    }
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i = 1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i = 1;i<n;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        v[x].pb(y);
        v[y].pb(x);
    }
    LL res=0;
    for(int i = 0;i<20;i++){
        tot=0;
        MEM(sum);
        for(int j = 1;j<=n;j++){
            if(a[j]&(1<<i))val[j]=1,tot++;
            else val[j]=0;
        }
        dfs(1,0);
        dfs2(1,0,0,0);
        res+=(tot/2)*(1<<i);
       // printf("%d\n",tot/2);
    }
    printf("%lld\n",res);
}