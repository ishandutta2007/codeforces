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
pii gcd(int a,int b){
    if(b==0) return mp(1,0);
    int p=a/b;
    pii q=gcd(b,a%b);
    return mp(q.y,q.x-q.y*p);
}
LL f_pro(LL a,LL b,LL mod){
    LL res=0,temp=a;
    while(b){
        if(b&1)res=(res+temp)%mod;
        temp=(temp+temp)%mod;
        b>>=1;
    }
    return res;
}
int main(){
    LL n,m,x,y,vx,vy;
    scanf("%lld %lld %lld %lld %lld %lld",&n,&m,&x,&y,&vx,&vy);
    if(vx==0){
        if(x!=0&&x!=n){
            printf("-1\n");
        }
        else if(vy>0){
            printf("%lld %lld\n",x,m);
        }
        else {
            printf("%lld 0\n",x);
        }
        return 0;
    }
    if(vy==0){
        if(y!=0&&y!=m){
            printf("-1\n");
        }
        else if(vx>0){
            printf("%lld %lld\n",n,y);
        }
        else {
            printf("0 %lld\n",y);
        }
        return 0;
    }
    if(vx>0)
    x=-x;
    if(vy>0)
    y=-y;
    LL step;
    if(y>x){
        if((y-x)%__gcd(n,m)!=0){
            printf("-1\n");
            return 0;
        }
        int need=(y-x)/__gcd(n,m);
        pll p=gcd(n/__gcd(n,m),m/__gcd(n,m));
        LL nn=n/__gcd(n,m);
        LL mm=m/__gcd(n,m);
        p.y=-p.y;
        p.x*=need;
        p.y*=need;
        if(p.x<0){
            LL add=((-p.x)+mm-1)/mm;
            p.x+=add*mm;
            p.y+=add*nn;
        }
        if(p.y<0){
            LL add=((-p.y)+nn-1)/nn;
            p.x+=add*mm;
            p.y+=add*nn;
        }
       // printf("%lld %lld\n",p.x,p.y);
        //step=p.x*n+x;
        LL mod=n*m/__gcd(n,m);
        step=f_pro(p.x,n,mod)+x;
        //if(step<0)
        step=(step%(mod)+mod)%(mod);
    }
    else{
        if((x-y)%__gcd(n,m)!=0){
            printf("-1\n");
            return 0;
        }
        int need=(x-y)/__gcd(n,m);
        pll p=gcd(n/__gcd(n,m),m/__gcd(n,m));
        LL nn=n/__gcd(n,m);
        LL mm=m/__gcd(n,m);
        p.x=-p.x;
        p.x*=need;
        p.y*=need;
        if(p.x<0){
            LL add=((-p.x)+mm-1)/mm;
            p.x+=add*mm;
            p.y+=add*nn;
        }
        if(p.y<0){
            LL add=((-p.y)+nn-1)/nn;
            p.x+=add*mm;
            p.y+=add*nn;
        }
        //step=p.x*n+x;
         LL mod=n*m/__gcd(n,m);
        // if(step<0)
         step=f_pro(p.x,n,mod)+x;
        step=(step%(mod)+mod)%(mod);
    }
   // printf("%lld\n",step);
    if(vx>0)
    x=-x;
    if(vy>0)
    y=-y;
    LL ansx=vx*step+x,ansy=vy*step+y;
   //printf("%lld %lld\n",ansx,ansy);
    assert(ansx%n==0);
    assert(ansy%m==0);
    if(ansx/n%2==0){
        printf("0");
    }
    else{
        printf("%lld",n);
    }
    if(ansy/m%2==0){
        printf(" 0\n");
    }
    else{
        printf(" %lld\n",m);
    }
}