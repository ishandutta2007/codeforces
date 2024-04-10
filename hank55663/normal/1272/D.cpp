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
#define KK 500
#define N 100005
int main(){
    int n;
    scanf("%d",&n);
    int a[200005];
    for(int i = 1;i<=n;i++){
        scanf("%d",&a[i]);
    }
    LL pre[200005];
    LL precnt[200005];
    precnt[1]=1;
    LL suf[200005];
    LL sufcnt[200005];
    sufcnt[n]=1;
    LL cnt=1;
    pre[1]=1;
    LL ans=1;
    for(int i = 2;i<=n;i++){
        if(a[i]>a[i-1])cnt++;
        else cnt=1;
        pre[i]=pre[i-1]+cnt;
        precnt[i]=cnt;
        ans=max(ans,cnt);
    }
    suf[n]=1;
    cnt=1;
    for(int i=n-1;i>=1;i--){
        if(a[i]<a[i+1])cnt++;
        else cnt=1;
        suf[i]=suf[i+1]+cnt;
        sufcnt[i]=cnt;
    }
    for(int i = 2;i<n;i++){
        if(a[i-1]<a[i+1]){
            ans=max(ans,precnt[i-1]+sufcnt[i+1]);
        }
    }
    printf("%lld\n",ans);
}