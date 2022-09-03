#include<bits/stdc++.h>
#define pb push_back
#define x first
#define y second
#define pdd pair<double,double>
#define pii pair<int,int>
#define pll pair<LL,LL>
#define mp make_pair
#define LL long long
#define ULL unsigned long long
#define sqr(x) ((x)*(x))
#define pi acosl(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
#define index Index
void solve(){
    int n;
    scanf("%d",&n);
    int p[1005],ans[1005];
    for(int i = 1;i<=n;i++){
        scanf("%d",&p[i]);
        ans[i]=i;
    }
    if(n==1){
        printf("-1\n");
        return;
    }
    for(int i = 1;i<=n;i++){
        
        if(p[i]==ans[i]){
            if(i==n){
                swap(ans[i],ans[i-1]);
            }
            else
            swap(ans[i],ans[i+1]);
        }
    }
    for(int i = 1;i<=n;i++)printf("%d ",ans[i]);
    printf("\n");
}

int main(){
 //   srand(time(NULL));
    int t=1;0000;
    scanf("%d",&t);

    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}