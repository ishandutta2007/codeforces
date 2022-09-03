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
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
//#define MXN 300000
#define N 100005
    int cnt[2000005];
    LL ans[2000005];
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        fill(cnt,cnt+n+1,0);
        fill(ans,ans+n+1,0);
        for(int i = 0;i<n;i++){
            int x;
            scanf("%d",&x);
            cnt[x]++;
        }
        int Min=1e9;
        for(int i = 1;i<=n;i++){
            if(cnt[i]==0)continue;
            Min=min(Min,cnt[i]);
            for(int j=1;j<=cnt[i];j++){
                if(cnt[i]%j>cnt[i]/j){
                    ans[j]+=1e9;
                }
                else{
                    int Max=cnt[i]/j,Min=(cnt[i]-1)/(j+1);
                    while(Max>Min+1){
                        int mid=(Max+Min)/2;
                        if(cnt[i]-mid*j<=mid){
                            Max=mid;
                        }
                        else{
                            Min=mid;
                        }
                    }
                    ans[j]+=Max;
                }
            }
        }
        int res=1e9;
        for(int i = 1;i<=Min;i++)
            res=min((LL)res,ans[i]);
        printf("%d\n",res);
    }
}
/*
2 -2000000000 2 -20000000000 1 1
*/