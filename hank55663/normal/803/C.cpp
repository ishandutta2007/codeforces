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
int main(){
    LL n,k;
    scanf("%lld %lld",&n,&k);
    if(k>=1e8||(1+k)*k/2>n){
        printf("-1\n");
    }
    else{
        LL ans[200005];
        LL Max=0;
        for(LL i =1;i*i<=n;i++){
            if(n%i==0){
                LL tmp=n/i;
                if(k*(k+1)/2<=tmp){
                    Max=max(Max,i);
                }
                tmp = i;
                if(k*(k+1)/2<=tmp){
                    Max=max(Max,n/i);
                }
            }
        }
        n/=Max;
        for(int i = 1;i<=k;i++){
            ans[i]=i;
            n-=i;
        }
        ans[k]+=n;
        for(int i = 1;i<=k;i++){
            printf("%lld ",ans[i]*Max);
        }
        printf("\n");
    }
}