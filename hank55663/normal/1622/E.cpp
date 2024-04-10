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
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
#define index Index
const int mod=998244353;
  pll sum[10005];
void solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    int x[15];
    for(int i = 0;i<n;i++)scanf("%d",&x[i]);
    char s[10][10005];
    for(int i = 0;i<n;i++){
        scanf("%s",s[i]);
    }
    LL res=-100;
    LL aans[10005];
    for(int i = 0;i<(1<<n);i++){
      
        fill(sum,sum+m,mp(0,0));
        for(int j = 0;j<m;j++){
            sum[j].y=j;
        }
        LL ans=0;
        for(int j = 0;j<n;j++){
            for(int k=0;k<m;k++){
                if(s[j][k]=='0')continue;
                if(i&(1<<j))sum[k].x++;
                else sum[k].x--;
            }
            if(i&(1<<j))ans-=x[j];
            else ans+=x[j];
        }
        sort(sum,sum+m);
        //printf("! %lld\n",ans);
        for(int i = 0;i<m;i++){
           // printf("%d ",sum[i].x);
            ans+=sum[i].x*(i+1);
        }
       // printf("\n");
        if(res<ans){
           // printf("%d\n",i);
            for(int i = 0;i<m;i++){
                aans[sum[i].y]=i+1;
            }
        }
        res=max(res,ans);

    }
    for(int i=0;i<m;i++)printf("%lld ",aans[i]);
    printf("\n");
    //printf("%lld\n",res);
}
int main(){
    int t=1;0000;
    scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}
/*
ACBABC
ACBCAB
ACABCB
*/