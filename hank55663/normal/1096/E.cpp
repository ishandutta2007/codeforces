
#pragma GCC optimize("Ofast") 
#include<bits/stdc++.h>
#include<bits/extc++.h>
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> set_t;
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<double,double>
#define pb push_back
#define x first
#define y second
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define index Index
#define Line pll
typedef long long LL;
int mod=998244353;
LL f_pow(LL a,LL b){
    LL res=1,temp=a;
    while(b){
        if(b&1)res=res*temp%mod;
        temp=temp*temp%mod;
        b>>=1;
    }
    return res;
}
int C[6005][6005];
void build(){
    for(int i=0;i<6005;i++){
        C[i][0]=C[i][i]=1;
        for(int j=1;j<=i;j++){
            C[i][j]=(C[i-1][j-1]+C[i-1][j])%mod;
        }
    }
}
LL H(int a,int b){
    if(a<0)
    return 0;
    if(a==0&&b==0)
    return 1;
    if(b<=0)
    return 0;
    return C[a+b-1][b-1];
}
int main(){
    int p,s,r;
    scanf("%d %d %d",&p,&s,&r);
    LL ans=0;
    build();
    for(int i=r;i<=s;i++){
        for(int j=0;j<p;j++){
            int tot=s-i*(j+1);
            int sum[5005];
            for(int k=0;k+j+1<=p;k++){

                sum[k]=H(tot-k*i,p-j-1)*C[p-j-1][k]%mod;
            }
            LL res=0;
            for(int k=p-j-1;k>=0;k--){
                res=sum[k]-res;
            }
            res=(res%mod+mod)%mod;
          //  printf("%d %d %d\n",i,j,res);
            ans+=f_pow(j+1,mod-2)*res%mod*C[p-1][j]%mod;
            ans%=mod;
        }
    }
    printf("%lld\n",ans*f_pow(H(s-r,p),mod-2)%mod);
}