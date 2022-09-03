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
#define hash Hash;
#define MXN 100005
struct matrix{
    int n;
    LL a[105][105];
    matrix(){
        MEM(a);
    }
    matrix(int x,int _n){
        MEM(a);
        n=_n;
        for(int i=0;i<n;i++)
            a[i][i]=x;
    }
};
int mod=998244353;
matrix operator*(const matrix &a,const matrix &b){
    mod--;
    matrix c;
    c.n=a.n;
    for(int i=0;i<c.n;i++){
        for(int j=0;j<c.n;j++){
            for(int k=0;k<c.n;k++){
                c.a[i][j]+=a.a[i][k]*b.a[k][j]%mod;
                c.a[i][j]%=mod;
            }
        }
    }
    mod++;
    return c;
}
matrix f_pow(matrix a,LL b){
    matrix res(1,a.n);
    matrix temp=a;
    while(b){
        if(b&1) res = res*temp;
        temp = temp * temp;
        b>>=1;
    }
    return res;
}
LL f_pow_n(LL a,LL b){
    LL res=1,temp=a;
    while(b){
        if(b&1)res=res*temp%mod;
        temp=temp*temp%mod;
        b>>=1;
    }
    return res;
}
pll gcd(LL a,LL b){
    if(b==0) return mp(1,0);
    else{
        LL p=a/b;
        pll q=gcd(b,a%b);
        return mp(q.y,q.x-q.y*p);
    }
}
LL cal(LL x,LL y){
   // printf("%lld %lld\n",x,y);
    if(__gcd(x,y)!=1){
        printf("-1\n");
        exit(0);
    }
    pll p=gcd(x,y);
    //printf("%lld %lld\n",p.x,p.y);
    //printf("%lld\n",((((p.y%x+x)%x)*(x-1))%x*y+1));
    return ((((p.y%x+x)%x)*(x-1))%x*y+1)/x;
}
LL dlog(LL x,LL y){
    LL inv=f_pow_n(x,mod-2);
    inv=f_pow_n(inv,40000);
    map<LL, LL> m;
    LL temp=1;
    for(int i=0;i<40000;i++){
        m[temp]=i;
        temp=temp*x%mod;
    }
    temp=y;
    for(int i=0;i<40000;i++){
        if(m.find(temp)!=m.end())
            return m[temp]+i*40000;
        temp=temp*inv%mod;
    }
}
int main(){
    int k;
    scanf("%d",&k);
    int b[105];
    map<LL,pii> ma;
    for(int i=100000;i>=2;i--){
        LL temp=i;
        for(int j=2;j<100;j++){
            temp=temp*i;
            if(temp>1e9)
            break;
            ma[temp]=mp(i,j);   
        }
    }
    for(int i=0;i<k;i++)
    scanf("%d",&b[i]);
    int n,m;
    scanf("%d %d",&n,&m);
    if(m==1){
        printf("1\n");
        return 0;
    }
    matrix a;
    a.n=k;
    for(int i=0;i<k-1;i++)
        a.a[i][i+1]=1;
    for(int i=0;i<k;i++)
    a.a[k-1][i]=b[k-i-1];
    a=f_pow(a,n-k);
    LL x=a.a[k-1][k-1];
    LL exponent= dlog(3,m);
   // printf("%lld %lld\n",x,exponent);
    //printf("%lld\n",f_pow_n(3,exponent));
    LL tgcd=__gcd(x,exponent);
    x/=tgcd;
    exponent/=tgcd;
    if(__gcd(x,(LL)mod-1)!=1){
        printf("-1\n");
    }
    else{
        pll p=gcd(mod-1,x);
        LL w=p.y;
        mod--;
        w=(w%mod+mod)%mod;
        mod++;
        LL res;
        //printf("%lld %lld\n",w*exponent,x);
        printf("%lld\n",res=f_pow_n(3,w*exponent));
      //  printf("%lld\n",f_pow_n(res,x));
        //printf("%lld\n",res=f_pow_n(m,cal(x,mod-1)));
    }
   // printf("%lld\n",f_pow_n(res,x));
}