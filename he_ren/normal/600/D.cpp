#include<cstdio>
#include<cmath>
typedef long double db;
typedef long long ll;
const db eps = 1e-7;
const db pi = acosl(-1);

inline ll read()
{
    ll x=0; bool f=0;
    char c=getchar();
    while(c<'0' || c>'9') f|=c=='-', c=getchar();
    while(c>='0' && c<='9') x=x*10+c-'0', c=getchar();
    return f?-x:x;
}

inline db Fabs(db x){ return x<0? -x: x;}
inline bool eq(db x,db y){ return Fabs(x-y) <= eps;}

inline db calc(db r1,db r2,db dis)
{
    db d = acosl((r1*r1+dis*dis-r2*r2)/(2*r1*dis))*2;
    return r1*r1*(d-sinl(d))/2;
}

int main(void)
{
    db x1=read(),y1=read(),r1=read();
    db x2=read(),y2=read(),r2=read();

    db dis = sqrtl((x1-x2)*(x1-x2) + (y1-y2)*(y1-y2));

    if(dis > r1+r2 || eq(dis,r1+r2)){ printf("0.0"); return 0;}
    if(dis+r1 < r2 || eq(dis+r1,r2)){ printf("%.20lf",(double)(pi*r1*r1)); return 0;}
    if(dis+r2 < r1 || eq(dis+r2,r1)){ printf("%.20lf",(double)(pi*r2*r2)); return 0;}

    printf("%.20lf\n",(double)(calc(r1,r2,dis)+calc(r2,r1,dis)));
    return 0;
}