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
#define pi acos(-1)
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
void solve(){
    int n;
    scanf("%d",&n);
    LL b[40005];
    LL tot=0;
    for(int i = 0;i<n;i++)scanf("%lld",&b[i]),tot+=b[i];
    if(tot%((n+1)*n/2))printf("NO\n");
    else{
        tot/=(n+1)*n/2;
        LL ans[40005];
        int ok=1;
        for(int i = 0;i<n;i++){
            LL tmp=b[(i+n-1)%n]+tot-b[i];
            if(tmp%n==0&&tmp>0)ans[i]=tmp/n;
            else ok=0;
        }
        if(ok){
            printf("YES\n");
            for(int i = 0;i<n;i++)printf("%lld ",ans[i]);
            printf("\n");
        }
        else{
            printf("NO\n");
        }

    }
}
int main(){
    int t=1;0000;
    scanf("%d",&t);
    for(int i = 1;i<=t;i++){
        solve();
    }
    return 0;
}
/*
ACBABC
ACBCAB
ACABCB
*/