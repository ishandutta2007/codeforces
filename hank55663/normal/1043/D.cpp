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
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MXN 200005
const int mod=1e9+7;
LL base[100005];
int Hash[15][100005];
LL getHash(int l,int r,int *h){
    return ((h[r]-h[l-1]*base[r-l+1])%mod+mod)%mod;
}
int a[15][100005];
int loc[15][100005];
int main(){
    base[0]=1;
    for(int i = 1;i<100005;i++){
        base[i]=base[i-1]*1234567%mod;
    }
    int n,m;
    scanf("%d %d",&n,&m);
 
    for(int i =  0;i<m;i++){
        for(int j=1;j<=n;j++){
            scanf("%d",&a[i][j]);
            Hash[i][j]=(Hash[i][j-1]*1234567ll+a[i][j])%mod;
            loc[i][a[i][j]]=j;
        }
    }
    LL ans=0;
    for(int i=  1;i<=n;i++){
        int Max=n,Min=0;
        while(Max>Min+1){
            int mid=(Max+Min)/2;
            int ok=1;
           // vector<LL> val;
            LL thash=-1;
            for(int j = 0;j<m;j++){
                if(loc[j][i]+mid>n){
                    ok=0;
                    break;
                }
                LL Ha=getHash(loc[j][i],loc[j][i]+mid,Hash[j]);
                if(thash<0)thash=Ha;
                if(thash!=Ha)ok=0;
                //val.pb(getHash(loc[j][i],loc[j][i]+mid,Hash[j]));
            }
            //for(auto it:val){
            //    if(it!=val[0])ok=0;
           // }
            if(ok)Min=mid;
            else Max=mid;
        }
       /* printf("%d\n",Max);
        for(int j=0;j<m;j++){
            if(loc[j][i]+Max<=n){
                printf("%lld %d %d\n",getHash(loc[j][i],loc[j][i]+Max,Hash[j]),loc[j][i],loc[j][i]+Max);
            }
        }
        printf("\n");*/
        ans+=Max;
    }
    printf("%lld\n",ans);
}