#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define x first
#define LL long long 
#define y second
#define sqr(x) ((x)*(x))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<long double,long double>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acosl(-1)
//#define N 524288
#define ld long double
using namespace std;
int main(){
    int t;
    scanf("%d",&t);
    while(t--){
        int n;
        scanf("%d",&n);
        LL Max=-1e9-7,ans=0;
        for(int i = 0;i<n;i++){
            LL a;
            scanf("%lld",&a);
            ans=max(ans,Max-a);
            Max=max(Max,a);
        }
        if(ans==0){
            printf("0\n");
        }
        else{
            for(int i = 0;;i++){
                if((1ll<<i)>ans){
                    printf("%d\n",i);
                    break;
                }
            }
        }
    }
}