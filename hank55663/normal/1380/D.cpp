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
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MAXN 205
//#define N 262144
#define ULL unsigned long long
#define ll long long
int loc[200005];
void solve(){
    int n,m;
    scanf("%d %d",&n,&m);
    LL X,Y,K;
    scanf("%lld %lld %lld",&X,&K,&Y);
    LL a[200005];
    LL b[200005];
    for(int i = 1;i<=n;i++){
        int x;
        scanf("%d",&x);
        loc[x]=i;
        a[i]=x;
    }
    
    int last=0;
    LL ans=0;
    for(int i = 1;i<=m;i++){
        int x;
        scanf("%d",&x);
        b[i]=x;
    }
    b[0]=0;
    for(int i = 1;i<=m;i++){
        int x=b[i];
        int dis=loc[x]-last-1;
        if(dis<0){
            printf("-1\n");
            return ;
        }
        LL Max=0;
        for(int j=last+1;j<loc[x];j++)Max=max(Max,a[j]);
     //   printf("%d\n",dis);
        if(Max>max(b[i],b[i-1])){
            if(dis==0);
            else if(dis<K){
                printf("-1\n");
                return ;
            }
            else if(Y*K<X){
                ans+=(dis-K)*Y+X;
            }
            else{
                ans+=dis/K*X+dis%K*Y;
            }
        }
        else{
            if(dis==0);
            else if(Y*K<X){
                ans+=dis*Y;
               // printf("!\n");
            }
            else{
                //printf("?\n");
                ans+=dis/K*X+dis%K*Y;
            }
        }
        last=loc[x];
    }
    int dis=n-last;
    if(dis<0){
        printf("-1\n");
        return ;
    }
    LL Max=0;
    for(int j=last+1;j<=n;j++)Max=max(Max,a[j]);
    if(Max>b[m]){
        if(dis==0);
        else if(dis<K){
            printf("-1\n");
            return ;
        }
        else if(Y*K<X){
            ans+=(dis-K)*Y+X;
        }
        else{
            ans+=dis/K*X+dis%K*Y;
        }
    }
    else{
        if(dis==0);
        else if(Y*K<X){
            ans+=dis*Y;
        }
        else{
            ans+=dis/K*X+dis%K*Y;
        }
    }
    printf("%lld\n",ans);
}
int main(){
    int t=1;
   // scanf("%d",&t);
    while(t--){
        solve();
    }
}