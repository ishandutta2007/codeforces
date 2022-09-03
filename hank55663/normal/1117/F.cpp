#include<bits/stdc++.h>
//#include<bits/extc++.h>
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> set_t;
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<double,double>
#define pb push_back
#define x first
#define y second
//#define sqr(x) ((x)*(x))
#define EPS 1e-7
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define Line pair<pii,pii> 
typedef long long LL;
#define hash Hash;
#define MXN 100005
//#define assert(x) while(!(x))
int pre[100005][20];
int suf[100005][20];
int cnt[20];
int ok[1<<17][17][17];
int grid[20][20];
int dp[1<<17];
int OK(int x,int a,int b,int p){
    if(ok[x][a][b]!=-1)return ok[x][a][b];
    ok[x][a][b]=1;
    for(int i=0;i<p;i++){
        if(i!=a&&i!=b&&(x&(1<<i))==0){
            if(!OK(x^(1<<i),a,b,p)){
                ok[x][a][b]=0;
                return ok[x][a][b];
            }
        }
    }
  //  bitset<3> bb(x);
   // cout<<bb<<" "<<a<<" "<<b<<endl;
    return ok[x][a][b];
}
int DP(int x,int p){
    if(dp[x]!=-1)return dp[x];
    dp[x]=0;
    for(int i=0;i<p;i++){
        for(int j=0;j<p;j++){
            if((x&(1<<i))&&(x&(1<<j))&&!OK(x,i,j,p)){
                dp[x]=0;
                return dp[x];
            }
        }
    }
    for(int i=0;i<p;i++){
        if((x&(1<<i))==0){
            if(DP(x^(1<<i),p)){
                dp[x]=1;
                return dp[x];
            }
        }
    }
    return dp[x];
}
int main(){
    int n,p;
    scanf("%d %d",&n,&p);
    char c[100005];
    scanf("%s",c+1);
    for(int i=1;c[i]!=0;i++)
    cnt[c[i]-'a']++;
    MEMS(pre);
    for(int i=1;c[i]!=0;i++){
        for(int j=0;j<p;j++)
        pre[i][j]=pre[i-1][j];
        pre[i][c[i]-'a']=i;
    }
    MEMS(suf);
    for(int i=strlen(c+1);i>=1;i--){
        for(int j=0;j<p;j++)
        suf[i][j]=suf[i+1][j];
        suf[i][c[i]-'a']=i;
    }
    for(int i=0;i<p;i++){
        for(int j=0;j<p;j++)
            scanf("%d",&grid[i][j]);
    }
    MEMS(ok);
    for(int i=1;i<=n;i++){
        vector<pii> prefix,suffix;
        for(int j=0;j<p;j++){
            if(pre[i][j]!=-1)
            prefix.pb(mp(pre[i][j],j));
            if(suf[i][j]!=-1)
            suffix.pb(mp(-suf[i][j],j));
        }
        sort(prefix.begin(),prefix.end());
        reverse(prefix.begin(),prefix.end());
        sort(suffix.begin(),suffix.end());
        reverse(suffix.begin(),suffix.end());
       /* printf("%d\n",i);
        for(auto it:prefix)
        printf("%d ",it.y);
        printf("\n");
        for(auto it:suffix)
        printf("%d ",it.y);
        printf("\n");*/
        int x=(1<<p)-1;
        x-=(1<<(c[i]-'a'));
        for(int j=1;j<prefix.size();j++){
            int temp=x;
            for(int k=1;k<suffix.size();k++){
                if(!grid[prefix[j].y][suffix[k].y]&&(temp&(1<<suffix[k].y))){
                    ok[temp][prefix[j].y][suffix[k].y]=0;
                    ok[temp][suffix[k].y][prefix[j].y]=0;
                  //  bitset<3> bb(x);
                  //  cout<<x<<" "<<prefix[j].y<<" "<<suffix[k].y<<endl;
                  //  printf("!\n");
                }
                if(temp&(1<<suffix[k].y))
                temp^=(1<<suffix[k].y);
            }
            x-=(1<<prefix[j].y);
        }
    }
    MEMS(dp);
    dp[(1<<p)-1]=1;
    int ans=n;
    for(int i=0;i<(1<<p);i++){
        if(DP(i,p)){
            int tot=0;
            for(int j=0;j<p;j++){
                if(i&(1<<j)){
                    tot+=cnt[j];
                }
            }
            ans=min(ans,tot);
        }
    }
    printf("%d\n",ans);
}