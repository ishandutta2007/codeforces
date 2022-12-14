#include<iostream>
#include<cstring>
#include<cstdio>
#include<cmath>
#define MN 100000
using namespace std;
inline int read()
{
    int x=0,f=1;char ch=getchar();
    while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x*f;
}
int n;
double a[MN+5],b[MN+5],mx[MN+5],mn[MN+5];

double Solve(double a,double b,double c,double A,double B,double C)
{
    double s=sqrt(max((double)0,b*b-4*a*c));
   // cout<<"Solve"<<a<<" "<<b<<" "<<c<<" "<<(b*b-4*a*c)<<endl;
    double x1=(-b+s)/(2*a),x2=(-b-s)/(2*a);
    if(x1>=0&&x1<=C&&A*x1+x1*(B-x1)==B) return x1;
    else return x2;
}

int main()
{
    n=read();
    for(int i=1;i<=n;++i) scanf("%lf",&mx[i]);
    for(int i=1;i<=n;++i) scanf("%lf",&mn[i]);
    double A=0,B=0;
    for(int i=1;i<=n;++i)
    {
        a[i]=Solve(1,-(mn[i]+mx[i]+B-A),-(A*(mn[i]+mx[i])-mx[i]),A+B,mx[i],mx[i]+mn[i]);
        b[i]=mx[i]+mn[i]-a[i];
        A+=a[i];B+=b[i];
    }
    for(int i=1;i<=n;++i) printf("%.10lf ",b[i]);puts("");
    for(int i=1;i<=n;++i) printf("%.10lf ",a[i]);
    return 0;
}