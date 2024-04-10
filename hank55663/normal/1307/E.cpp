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
int pre[5005][5005];
int mod=1e9+7;
vector<int> v[5005];
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int s[5005];
    for(int i = 1;i<=n;i++){
        scanf("%d",&s[i]);
        for(int j=1;j<=n;j++){
            pre[i][j]=pre[i-1][j];
        }
        pre[i][s[i]]++;
    }
    pii p[5005];
    int l[5005],r[5005],ok[5005];
    for(int i = 0;i<m;i++){
        int x,y;
        scanf("%d %d",&x,&y);
        p[i]=mp(x,y);
        v[x].pb(y);
        if(pre[n][x]<y){
            ok[i]=0;
        }
        else{
            ok[i]=1;
            int sum=0;
            for(int j=1;j<=n;j++){
                if(s[j]==x)sum++;
                if(sum==y){
                    l[i]=j;
                    break;
                }
            }
            sum=0;
            for(int j=n;j>=1;j--){
                if(s[j]==x)sum++;
                if(sum==y){
                    r[i]=j;
                    break;
                }
            }
           // printf("%d %d\n",l[i],r[i]);
        }
    }
    LL ans=0,anssum=2;
    for(int i = 0;i<m;i++){
        if(!ok[i])continue;
        //l[i]-1,l[i]+1;
        LL res=0,sum=1,sumnr=1;
        int ok;
        for(int j=1;j<=n;j++){
            int ll=pre[l[i]-1][j],rr=pre[n][j]-pre[l[i]][j];
            if(j==p[i].x)ll=0;
            int numl=0,numr=0;
            for(auto it:v[j]){
                if(j==p[i].x&&it==p[i].y)continue;
                if(it<=ll)numl++;
                if(it<=rr)numr++;
            }
            if(j==p[i].x){
                if(numr)ok=0;
                else ok=1;
            }
            if(numr==0&&numl)sumnr*=numl,sumnr%=mod;
            if(numl==0&&numr)sumnr=0;
            if(numl==0&&numr==0);
            else if(max(numl,numr)==1){
                res++;
                if(numl&&numr)sum*=2;
            }
            else if(min(numl,numr)==0){
                res++;
                sum*=max(numl,numr);
            }
            else{
                sumnr=0;
                res+=2;
                sum*=min(numl,numr)*(max(numl,numr)-1);
            }
            sum%=mod;
        }
        res++;
        sum+=sumnr;
      //  printf("%lld %lld\n",sum,sumnr);
        if(res>ans)ans=res,anssum=sum;
        else if(res==ans)anssum+=sum,anssum%=mod;
        {
            LL res=0,sum=1,sumnol=1;
            for(int j=1;j<=n;j++){
                int ll=pre[r[i]-1][j],rr=pre[n][j]-pre[r[i]][j];
                if(j==p[i].x)rr=0;
                int numl=0,numr=0;
                for(auto it:v[j]){
                    if(j==p[i].x&&it==p[i].y)continue;
                    if(it<=ll)numl++;
                    if(it<=rr)numr++;
                }
                if(numl==0&&numr)sumnol*=numr,sumnol%=mod;
                if(numr==0&&numl)sumnol=0;
                if(numl==0&&numr==0);
                else if(max(numl,numr)==1){
                    res++;
                    if(numl&&numr)sum*=2;
                }
                else if(min(numl,numr)==0){
                    res++;
                    sum*=max(numl,numr);
                }
                else{
                    sumnol=0;
                    res+=2;
                    sum*=min(numl,numr)*(max(numl,numr)-1);
                }
                sum%=mod;
            }
            res++;
            sum+=sumnol;
         //   printf("%d %d\n",sum,sumnol);
            if(res>ans)ans=res,anssum=sum;
            else if(res==ans)anssum+=sum,anssum%=mod;
        }
    }
    printf("%lld %lld\n",ans,anssum*(mod+1)/2%mod);
}
/*
dis2[i]+dis[j]<=dis2[j]+dis[i];
dis2[i]-dis[i]<=dis2[j]-dis[j];
*/