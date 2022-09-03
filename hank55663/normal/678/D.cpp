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
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
#define MXN 205
/*
A 1  x
0 1  B

*/
int mod=1e9+7;
void f_pow(LL a[2][2],LL b){
    LL res[2][2]={1,0,0,1},tmp[2][2]={a[0][0],a[0][1],a[1][0],a[1][1]};
    while(b){
        if(b&1){
            LL t[2][2]={0,0,0,0};
            for(int i = 0;i<2;i++){
                for(int j=0;j<2;j++){
                    for(int k = 0;k<2;k++){
                        t[i][j]+=res[i][k]*tmp[k][j]%mod;
                        t[i][j]%=mod;
                    }
                }
            }
            for(int i = 0;i<2;i++){
                for(int j=0;j<2;j++){
                    res[i][j]=t[i][j];
                }
            }
        }
        {
            LL t[2][2]={0,0,0,0};
            for(int i = 0;i<2;i++){
                for(int j=0;j<2;j++){
                    for(int k = 0;k<2;k++){
                        t[i][j]+=tmp[i][k]*tmp[k][j]%mod;
                        t[i][j]%=mod;
                    }
                }
            }
            for(int i = 0;i<2;i++){
                for(int j=0;j<2;j++){
                    tmp[i][j]=t[i][j];
                }
            }
        }
        b>>=1;
    }
    for(int i = 0;i<2;i++){
        for(int j=0;j<2;j++){
            a[i][j]=res[i][j];
        }
    }
}
int main(){
    LL a,b,n,x;
    scanf("%lld %lld %lld %lld",&a,&b,&n,&x);
    LL tmp[2][2]={a,1,0,1};
    f_pow(tmp,n);
    printf("%lld\n",(tmp[0][0]*x+tmp[0][1]*b)%mod);
}
/*

*/