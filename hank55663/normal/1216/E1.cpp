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
LL sum2[10000005];
LL sum[10000005];
LL num[10000005];
int main(){
    int now=1;
    for(int i=1;i<=10000000;i*=10){
        num[i]=now;
        now++;
    }
    for(int i=1;i<=10000000;i++){
        num[i]=max(num[i],num[i-1]);
        sum[i]=sum[i-1]+num[i];
        sum2[i]=sum2[i-1]+sum[i];
        //if(i<=10)printf("%lld %lld %lld\n",num[i],sum[i],sum2[i]);
    }
    int q;
    scanf("%d",&q);
    while(q--){
        int k;
        scanf("%d",&k);
        int x=lower_bound(sum2,sum2+10000000,k)-sum2-1;
        k-=sum2[x];
        int y=lower_bound(sum,sum+x+1,k)-sum-1;
        k-=sum[y];
        y++;
        vector<int> v;
        while(y){
            v.pb(y%10);
            y/=10;
        }
        reverse(v.begin(),v.end());
        printf("%d\n",v[k-1]);
       // printf("%d %d %d\n",x,y,k);
    }
}