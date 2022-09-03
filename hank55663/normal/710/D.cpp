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
#define pi acos(-1)
#define sqr(x) ((x)*(x))
#define pdd pair<double,double>
#define MEMS(x) memset(x,-1,sizeof(x))
#define MEM(x) memset(x,0,sizeof(x))
#define EPS 1e-4
#define arg ARG
#define cpdd const pdd
#define rank Rank
//#define MXN 300000
#define N 100005
pll gcd(LL a, LL b){
    if(b == 0) return mp(1, 0);
    else{
        LL p = a / b;
        pll q = gcd(b, a % b);
        return make_pair(q.y, q.x - q.y * p);
    }
}
LL f_pro(LL a, LL b, LL mod){
    LL flag=1;
    if(b<0)flag=-1,b=-b;
    LL res=0,temp=a;
    while(b){
        if(b&1)res=(res+temp)%mod;
        temp=(temp<<1)%mod;
        b>>=1;
    }
    return res*flag;
}
LL solve(LL x1, LL m1, LL x2, LL m2){
    LL g = __gcd(m1, m2);
    if((x2 - x1) % g)return -1;
    m1 /= g; m2 /= g;
    pll p = gcd(m1, m2);
    LL lcm = m1 * m2 * g;
    LL res = f_pro(f_pro(p.x,x2-x1,lcm),m1,lcm) +x1;
    //LL res = p.x * (x2 - x1)%lcm * m1%lcm + x1;
   // printf("%lld %lld\n",res,lcm);
    return (res % lcm + lcm) % lcm;
}
int main(){
    LL a1,b1,a2,b2,l,r;
    scanf("%lld %lld %lld %lld %lld %lld",&a1,&b1,&a2,&b2,&l,&r);
    LL x=solve((b1%a1+a1)%a1,a1,(b2%a2+a2)%a2,a2);
    if(x==-1){
        printf("0\n");
    }
    else{
       // printf("%d\n",x);
        l=max(l,max(b1,b2));
        if(l>r){
            printf("0\n");
            return 0;
        }
        l-=x;
        r-=x;
        if(l<=0&&r<=0){
            l=-l;
            r=-r;
            swap(l,r);
        }
        //printf("%lld %lld %lld\n",x,l,r);
        LL ans=0;
        LL lcm=a1*a2/__gcd(a1,a2);
        ans+=r/lcm+1;
        if(l<0){
            ans+=-l/lcm;
        }
        else if(l>0){
            l--;
            ans-=l/lcm+1;
        }
        printf("%lld\n",ans);
    }
}
/*
2 -2000000000 2 -20000000000 1 1
*/