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
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MXN 1500
int pool[1000005];
int main(){
    int n,m;
    scanf("%d %d",&n,&m);
    int a[100005];
    int *cnt=pool+500000;
    for(int i = 0;i<m;i++){
       //a[i]=1;
        scanf("%d",&a[i]);
    }
    if(n==1){
        printf("0\n");
        return 0;
    }
    LL ans=n;
    for(int i = 1;i<=n;i++){
        cnt[i]=1; 
    }
    for(int i = 0;i<m;i++){
        ans+=n;
        ans-=cnt[n-i];
        cnt[n-i-1]+=cnt[n-i];
        cnt[n-i]=0;
        ans-=cnt[a[i]-i-1];
        cnt[a[i]-i-2]+=cnt[a[i]-i-1];   
        cnt[a[i]-i-1]=0;
       // printf("%lld\n",ans);
    }
    ans+=n;
    ans-=cnt[n-m];
    //printf("%lld\n",ans);
    MEM(pool);
    for(int i = 1;i<=n;i++){
        cnt[i]=1;
    }
    for(int i = 0;i<m;i++){
        ans+=n;
        ans-=cnt[i+1];
        cnt[i+2]+=cnt[i+1];
        cnt[i+1]=0;
        ans-=cnt[a[i]+i+1];
        cnt[a[i]+i+2]+=cnt[a[i]+i+1];
        cnt[a[i]+i+1]=0;
    }
    ans+=n;
    ans-=cnt[m+1];
    printf("%lld\n",ans);
}