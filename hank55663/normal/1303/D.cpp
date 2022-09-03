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
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        LL n,m;
        scanf("%lld %lld",&n,&m);
        int a[100005];
        LL sum=0;
        int cnt[100];
        MEM(cnt);
        for(int i = 0;i<m;i++){
            scanf("%d",&a[i]);
            sum+=a[i];
            cnt[__builtin_popcount(a[i]-1)]++;
        }
        if(sum<n){
            printf("-1\n");
        }
        else{
            int ans=0;
            for(int i = 0;(1ll<<i)<=n;i++){
                if(n&(1ll<<i)){
                    if(cnt[i]==0){
                        for(int j = i+1;;j++){
                            ans++;
                            if(cnt[j]){
                                cnt[j]--;
                                for(int k=i;k<j;k++)cnt[k]++;
                                break;
                            }
                        }
                    }
                    else{
                        cnt[i]--;
                        cnt[i+1]+=cnt[i]/2;
                    }
                }
                else{
                    cnt[i+1]+=cnt[i]/2;
                }
            }
            printf("%d\n",ans);
        }
    }
}