#include<bits/stdc++.h>
using namespace std;
#define LL long long
#define mp make_pair
#define pb push_back
#define pii pair<int,int>
#define pll pair<LL,LL>
#define x first
#define y second
#define N 131072
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        LL d[305];
        for(int i = 0;i<n;i++){
            scanf("%lld",&d[i]);
        }
        sort(d,d+n);
        LL ans=d[0]*d[n-1];
        int tot=0;
        for(LL i = 2;i*i<=ans;i++){
            if(ans%i==0){
                tot++;
                if(ans/i!=i)
                    tot++;
            }
        }
        if(tot!=n){
            printf("-1\n");
        }
        else{
            int ok=1;
            for(int i = 0;i<n;i++){
                if(ans%d[i]!=0){
                    printf("-1\n");
                    ok=0;
                    break;
                }
            }
            if(ok)
            printf("%lld\n",ans);
        }
    }
}