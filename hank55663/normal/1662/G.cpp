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
//#define sqr(x) ((x)*(x))
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
vector<int> v[1000005];
int Size[1000005];
LL val[1000005];
void dfs(int x,int f){
    Size[x]=1;
    for(auto it:v[x]){
        if(it!=f){
            dfs(it,x);
            Size[x]+=Size[it];
            val[x]+=val[it];
        }
    }
    val[x]+=Size[x];
}
LL ans=0;
int n;
int dp[1000005];
void dfs2(int x,int f,LL av){
 
    for(auto it:v[x]){
        if(it!=f){
            dfs2(it,x,av+val[x]-Size[x]-val[it]+n-Size[it]+1+Size[x]-Size[it]-1);
        }
    }
       val[x]+=av;
    //printf("%d %d %d\n",x,val[x],av);
    //vector<int> v;
    //v.pb(n-Size[x]);
    LL Max=n-Size[x];
    for(auto it:v[x]){
        if(it!=f)
        Max=max(Max,Size[it]*1ll);
    }
  //  printf("%d %d\n",x,Max);
    if(n-Max-1<=Max){
        ans=max(ans,val[x]+Max*(n-Max-1));
    }
    else{
        vector<int> vv;
        vv.pb(n-Size[x]);
        for(auto it:v[x]){
            if(it!=f)
            vv.pb(Size[it]);
        }
        sort(vv.begin(),vv.end());
        LL Max=0;
        dp[0]=1;
        int cnt=0;
        for(int i = 0;i<vv.size();i++){
            cnt++;
            if(i==vv.size()-1||vv[i]!=vv[i+1]){
                Max+=vv[i]*cnt;
                for(int j = 0;j<vv[i];j++){
                    int tot=0;
                    for(int k = j;k<=Max;k+=vv[i]){
                        if(dp[k])tot=cnt;
                        else{
                            if(tot)dp[k]=1,tot--;
                        }
                    }
                }
                cnt=0;
            }
        }
        for(LL i = 0;i<n;i++){
            if(dp[i]){
           //    printf("%d\n",i);
                ans=max(ans,val[x]+i*(n-i-1));
            }
        }
    //    printf("%d\n",x);
    }
}
void solve(){
    scanf("%d",&n);
    for(int i = 2;i<=n;i++){
        int x;
        scanf("%d",&x);
        v[x].pb(i);
        v[i].pb(x);
    }
    dfs(1,0);
    dfs2(1,0,0);
    printf("%lld\n",ans);
}
int main(){
  //  srand(time(NULL));
    int t=1;0000;
    //scanf("%d",&t);

    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}
/*
1101011?0 5 1
001101?00 3 1
101000110 4 0
001011010 4 0
0101?01?? 3 3
00?1000?0 1 2
223413320
  1 1 131
*/