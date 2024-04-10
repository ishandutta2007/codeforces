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
#define less Less
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define ld long double
struct matrix{
    int n;
    LL a[55][55];
    matrix(){
        MEM(a);
    }
};
const int mod=998244353;
matrix operator*(const matrix &a,const matrix &b){
    matrix c;
    c.n=a.n;
    for(int i = 0;i<a.n;i++){
        for(int j=0;j<a.n;j++){
            for(int k=0;k<a.n;k++){
                c.a[i][j]+=a.a[i][k]*b.a[k][j]%mod;
//                c.a[i][j]%=mod;
            }
            c.a[i][j]%=mod;
        }
    }
    return c;
}
matrix f_pow(matrix a,LL b){
    matrix tmp=a;
    matrix res;
    res.n=a.n;
    for(int i=0;i<res.n;i++){
        res.a[i][i]=1;
    }
    while(b){
        if(b&1)res=res*tmp;
        tmp=tmp*tmp;
        b>>=1;
    }
    /*printf("!%d\n",b);
    for(int i = 0;i<res.n;i++){
        for(int j=0;j<res.n;j++)
        printf("%d ",res.a[i][j]);
        printf("\n");
    }*/
    return res;
}
LL f_pow(LL a,LL b){
    LL res=1,temp=a;
    while(b){
        if(b&1)res=res*temp%mod;
        temp=temp*temp%mod;
        b>>=1;
    }
    return res;
}
int main(){
    int n;
    scanf("%d",&n);
    matrix a;
    a.n=n+1;
    for(int i=0;i<=n;i++)a.a[i][i]=1;
    map<int,vector<int> > v;
    LL tot=1;
    for(int i = 1;i<=n;i++){
        int l,r;
        scanf("%d %d",&l,&r);
        v[-r].pb(i);
        v[-l+1].pb(i);
        tot=tot*(r-l+1)%mod;
    }
   // LL aaa=0;
   // for(int i=2;i<=4;i++){
   //     for(int j=1;j<=3;j++){
    //        if(j<=i)aaa++;
    //    }
   // }
   // printf("%lld\n",aaa);
    matrix res=a;
    int last=-1e9;
    int ok[55];
    MEM(ok);
    for(auto it:v){
     //   printf("%d\n",it.x-last);
        res=f_pow(a,it.x-last)*res;
        last=it.x;
        for(auto it2:it.y){
            ok[it2]^=1;
        }
        for(int i = 1;i<=n;i++){
            //if(ok[i])
            for(int j=0;j<i;j++){
                if(ok[i])
                a.a[i][j]=a.a[i-1][j];
                else
                a.a[i][j]=0;
            }   
        }
       /* for(int i = 0;i<=n;i++){
            for(int j=0;j<=n;j++){
                printf("%d ",a.a[i][j]);
            }
            printf("\n");
        }
        for(int i = 0;i<=n;i++){
            for(int j=0;j<=n;j++){
                printf("%d ",res.a[i][j]);
            }
            printf("\n");
        }*/
    
    }
    //printf("%lld\n",res.a[n][0]);
    printf("%lld\n",res.a[n][0]*f_pow(tot,mod-2)%mod);
    
}