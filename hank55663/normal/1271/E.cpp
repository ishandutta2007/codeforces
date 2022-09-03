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
#define MXN 200005
int val[100005];
void dfs(int x){
    val[x]++;
    if(x==1)return;
    if(x&1)dfs(x-1);
    else dfs(x/2);
}
LL cal(LL l,LL r,LL n){
    LL res=max(min(r,n)-l+1,0ll);
    if(r>=n)return res;
    return res+cal(l<<1,r*2+1,n);
}
int main(){
    LL n,k;
    scanf("%lld %lld",&n,&k);
    if(k==n){
        printf("1\n");
        return 0;
    }
    LL Max=n+2,Min=1;
    if(Max%2==0)Max--;
    while(Max>Min+2){
        LL mid=(Max+Min)/2;
        if(mid%2==0)mid++;
        if(cal(mid,mid,n)>=k){
            Min=mid;
        }
        else{
            Max=mid;
        }
    }
    LL ans=Min;
    Max=n+2,Min=2;
    if(Max%2==0)Max--;
    while(Max>Min+2){
        LL mid=(Max+Min)/2;
        if(mid%2)mid++;
        if(cal(mid,mid+1,n)>=k){
            Min=mid;
        }
        else{
            Max=mid;
        }
    }
    printf("%lld\n",max(ans,Min));
}