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
#define rank Rank
#define MXN 200005
const int mod=1e9+7;
struct matrix{
    LL a[105][105];
    int n;
    matrix(){
        MEM(a);
    }
};
matrix operator*(const matrix &a,const matrix &b){
    matrix c;
    c.n=a.n;
    for(int i = 0;i<a.n;i++){
        for(int j=0;j<a.n;j++){
            for(int k=0;k<a.n;k++){
                c.a[i][j]+=a.a[i][k]*b.a[k][j];
                c.a[i][j]%=mod;
            }
        }
    }
    return c;
}
matrix f_pow(matrix a,LL k){
    matrix temp=a,res;
    res.n=a.n;
    for(int i = 0;i<res.n;i++)
        res.a[i][i]=1;
    while(k){
        if(k&1)res=res*temp;
        temp=temp*temp;
        k>>=1;
    }
    return res;
}
int main(){
    LL n,k;
    scanf("%lld %lld",&n,&k);
    LL a[105];
    for(int i = 0;i<n;i++){
        scanf("%lld",&a[i]);
    }
    matrix tmp;
    tmp.n=n;
    for(int i = 0;i<n;++i){
        for(int j=0;j<n;j++){
            if(__builtin_popcountll(a[i]^a[j])%3==0){
                tmp.a[i][j]=1;
            }
            //printf("%d ",tmp.a[i][j]);
        }
      //  printf("\n");
    }
    tmp=f_pow(tmp,k-1);
    LL ans=0;
    for(int i = 0;i<n;i++){
        for(int j=0;j<n;j++){
            ans+=tmp.a[i][j];
        //    printf("%d ",tmp.a[i][j]);
        }
      //  printf("\n");
    }
    printf("%lld\n",ans%mod);
}
/*

23847657 
23458792534

102334155
111111111 
111111111
*/