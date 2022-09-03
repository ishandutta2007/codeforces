#include <bits/stdc++.h>
#define pb push_back
#define mp make_pair
#define x first
#define LL long long 
#define y second
#define sqr(x) ((x)*(x))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<double,double>
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
using namespace std;
LL matrix[2][2];
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
LL res[2][2];
void f_pow(LL b){
    res[0][0]=res[1][1]=1;
    LL temp[2][2]={matrix[0][0],matrix[0][1],matrix[1][0],matrix[1][1]};
    while(b){
        if(b&1){
            LL tmp[2][2];
            MEM(tmp);
            for(int i = 0;i<2;i++){
                for(int j = 0;j<2;j++){
                    for(int k=0;k<2;k++){
                        tmp[i][j]+=res[i][k]*temp[k][j]%mod;
                        tmp[i][j]%=mod;
                    }
                }
            }
            for(int i = 0;i<2;i++){
                for(int j =0;j<2;j++)res[i][j]=tmp[i][j];
            }
        }
        {
            LL tmp[2][2];
            MEM(tmp);
            for(int i = 0;i<2;i++){
                for(int j = 0;j<2;j++){
                    for(int k=0;k<2;k++){
                        tmp[i][j]+=temp[i][k]*temp[k][j]%mod;
                        tmp[i][j]%=mod;
                    }
                }
            }
            for(int i = 0;i<2;i++){
                for(int j =0;j<2;j++)temp[i][j]=tmp[i][j];
            }
        }
        b>>=1;
    }
    
}
int main(){
    LL n,m,l,r;
    scanf("%lld %lld %lld %lld",&n,&m,&l,&r);
    if(n*m%2){
        printf("%lld\n",f_pow(r-l+1,n*m));
        return 0;
    }
    LL even=r/2-(l-1)/2;
    LL odd=r-l+1-even;
    matrix[0][0]=matrix[1][1]=even;
    matrix[0][1]=matrix[1][0]=odd;
    f_pow(n*m);    
    printf("%lld\n",res[0][0]);
}