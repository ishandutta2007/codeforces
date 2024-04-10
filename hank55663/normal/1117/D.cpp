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
#define sqr(x) ((x)*(x))
#define EPS 1e-6
#define MEM(x) memset(x,0,sizeof(x))
#define MEMS(x) memset(x,-1,sizeof(x))
#define pi acos(-1)
#define index Index
#define Line pll
typedef long long LL;
struct matrix{
    LL a[105][105];
    int n;
    matrix(){
        MEM(a);
    }
    matrix(int x,int _n){
        MEM(a);
        n=_n;
        for(int i=0;i<n;i++){
            a[i][i]=x;
        }
    }
};
int mod=1e9+7;
matrix operator*(const matrix &a,const matrix &b){
    matrix c;
    c.n=a.n;
    for(int i=0;i<c.n;i++){
        for(int j=0;j<c.n;j++){
            for(int k=0;k<c.n;k++){
                c.a[i][j]=(c.a[i][j]+a.a[i][k]*b.a[k][j])%mod;
            }
        }
    }
    return c;
}
matrix f_pow(matrix a,LL b){
    matrix temp=a,res(1,a.n);
    while(b){
        if(b&1)res=res*temp;
        temp=temp*temp;
        b>>=1;
    }
    return res;
}
int main(){
    LL n,m;
    scanf("%lld %lld",&n,&m);
    matrix a;
    a.n=m;
    for(int i=1;i<m;i++)
    a.a[i-1][i]=1;
    a.a[m-1][0]=1;
    a.a[m-1][m-1]=1;
    matrix res=f_pow(a,n);
    printf("%lld\n",res.a[m-1][m-1]);
}
/*

i f f x f l b
*/