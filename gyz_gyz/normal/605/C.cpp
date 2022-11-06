#include<cstdio>
#define rep(i,x,y) for(int i=(x);i<=(y);i++)
#define N 100001
using namespace std;
int n;double a[N],b[N],l,r,mi,m,k;
inline double f(double x){double y=1;
    rep(i,1,n)if((1-x*a[i])/b[i]<y)y=(1-x*a[i])/b[i];
    return x*m+y*k;
}
int main(){
    scanf("%d%lf%lf",&n,&m,&k);
    rep(i,1,n)scanf("%lf%lf",&a[i],&b[i]);
    l=0;r=1;rep(i,1,n)if(r>1/a[i])r=1/a[i];
    for(mi=(r-l)/3;r-l>1e-12;mi=(r-l)/3)
        if(f(l+mi)>f(r-mi))r-=mi;else l+=mi;
    printf("%.10lf\n",f(l));
}