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
#define last Last
#define MXN 200005
const int mod=998244353;
void solve(){
    int n,a,b;
    scanf("%d %d %d",&n,&a,&b);
    if(a==1){
        if((n-1)%b==0)printf("Yes\n");
        else printf("No\n");
    }
    else{
        for(LL i =1;i<=n;i*=a){
            if((n-i)%b==0){
                printf("Yes\n");
                return ;
            }
        }
        printf("No\n");
    }
}
int main(){
    int t=1;
    scanf("%d",&t);
    while(t--){
        solve();
    }
    return 0;
}/**/