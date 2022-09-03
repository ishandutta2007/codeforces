#include<bits/stdc++.h>
//#include<bits/extc++.h>
using namespace std;
//using namespace __gnu_pbds;
//typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> set_t;
#define mp(a,b) make_pair((a),(b))
#define pii pair<int,int>
#define pll pair<LL,LL>
#define pdd pair<double,double>
#define pb push_back
#define x first
#define y second
//#define sqr(x) ((x)*(x))
#define EPS 1e-7
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define Line pair<pii,pii> 
typedef long long LL;
#define hash Hash
struct mat{
    LL a[2][2];
    mat(){
        MEM(a);
    }
};
int mod=1e9+7;
mat operator*(const mat &a,const mat &b){
    mat res;
    for(int i=0;i<2;i++){
        for(int j=0;j<2;j++){
            for(int k=0;k<2;k++){
                res.a[i][j]+=a.a[i][k]*b.a[k][j];
                res.a[i][j]%=mod;
            }
        }
    }
    return res;
}
mat f_pow(mat a,LL b){
    mat res,temp=a;
    for(int i=0;i<2;i++)res.a[i][i]=1;
    while(b){
        if(b&1)res=res*temp;
        temp=temp*temp;
        b>>=1;
    }
    return res;
}
int main(){
    LL x,k;
    scanf("%lld %lld",&x,&k);
    if(x==0){
        printf("0\n");
        return 0;
    }
    mat temp;
    temp.a[0][0]=2;
    temp.a[0][1]=mod-1;
    temp.a[1][1]=1;
    mat res=f_pow(temp,k);
    x=x*2%mod;
    printf("%lld\n",(res.a[0][0]*x+res.a[0][1])%mod);
}