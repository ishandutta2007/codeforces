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
#define index Index
const int mod=998244353;
LL C[5005][5005];
void build(){
    for(int i = 0;i<5005;i++){
        C[i][0]=C[i][i]=1;
        for(int j  =1;j<i;j++){
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
        }
    }
}
void solve(){
    build();
    int n,k;
    scanf("%d %d",&n,&k);
    char c[5005];
    scanf("%s",c);
    int tot=0;
    for(int i = 0;c[i]!=0;i++){
        tot+=c[i]=='1';
    }
    if(tot<k){
        printf("1\n");
        return;
    }
    LL ans=1;
    for(int i = max(k,1);i<=k;i++){
        int r=0;
        int tot=0;
        queue<int> q;
        for(int j = 0;j<n;j++){
            while(r<n&&tot+(c[r]=='1')<=i){
                if(c[r]=='1')q.push(r),tot++;
                r++;
            }
            if((j==0||c[j-1]=='1')&&tot){
                ans+=C[r-j][tot]-C[r-q.front()-1][tot-1];
                ans%=mod;
                ans+=mod;
                ans%=mod;
               // printf("%d %lld %d %d\n",j,C[r-j][tot]-C[r-q.front()-1][tot-1],r,tot);
            }
            if(c[j]=='1')q.pop(),tot--;
        }
    }
    printf("%lld\n",ans);
}
int main(){
    int t=1;0000;
   // scanf("%d",&t);
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