#include<cstdio>
#include<cmath>
const int N=100005;
double x[N],y[N];
int n;
inline void chmin(double &a,const double &b){(a>b)&&(a=b);}
inline void chmax(double &a,const double &b){(a<b)&&(a=b);}
bool check(double r)
{
    double Y=r,L=-1e18,R=1e18,tmp;
    for(int i=1;i<=n;++i)
    {
        //sqrt((x[i]-X)^2 + (y[i]-Y)^2) <=r
        //(x[i]-X)^2 + (y[i]-Y)^2 <= r^2
        //X^2  -2x[i]*X + x[i]^2 +y[i]^2 +Y^2-2*y[i]*Y<=r^2
        //(X-x[i])^2 <= r^2  - y[i]^2 - Y^2 + 2*y[i]*Y
        //X <= sqrt (r^2  - y[i]^2 - Y^2 + 2*y[i]*Y )+x[i]
        if(r*2.0<y[i]) return 0;
        tmp=sqrt(y[i]*(2.0*Y-y[i]));
        chmax(L,-tmp+x[i]);
        chmin(R,tmp+x[i]);
    }
    return L<=R;
}
int main()
{
    scanf("%d",&n);
    bool flag1=0,flag2=0;
    for(int i=1;i<=n;++i)
    {
        scanf("%lf %lf",&x[i],&y[i]);
        flag1|=y[i]>0;
        flag2|=y[i]<0;
    }
    if(flag1&&flag2)
    {
        printf("-1\n");
        return 0;
    }
    if(flag2)
    {
        for(int i=1;i<=n;++i)
        {
            y[i]=-y[i];
        }
    }
    double l=0,r=1e18;
    for(int i=1;i<=n;++i)
    {
    	chmax(l,y[i]);
	}
	l/=2.0;
    for(int T=500;T;--T)
    {
        double mid=(l+r)/2.0;
        if(check(mid)) r=mid;
        else l=mid;
    }
    printf("%.12lf\n",l);
    return 0;
}