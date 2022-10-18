#include<iostream>
#include<cstdio>
#include<cmath>
using namespace std;
int t;
double c,m,p,v,ans;
void dfs(int k,double f,double c,double m,double p)
{
    ans+=k*f*p;
    if(fabs(c)>1e-6)
    {
        if(c<v)
        {
            if(fabs(m)>1e-6)
                dfs(k+1,f*c,0.000000,m+c/2.0,p+c/2.0);
            else
                dfs(k+1,f*c,0.000000,0.000000,p+c);
        }
        else
            if(fabs(m)>1e-6)
                dfs(k+1,f*c,c-v,m+v/2.0,p+v/2.0);
            else
                dfs(k+1,f*c,c-v,0.000000,p+v);
    }
    if(fabs(m)>1e-6)
    {
        if(m<v)
        {
            if(fabs(c)>1e-6)
                dfs(k+1,f*m,c+m/2.0,0.000000,p+m/2.0);
            else
                dfs(k+1,f*m,0.000000,0.000000,p+m);
        }
        else
            if(fabs(c)>1e-6)
                dfs(k+1,f*m,c+v/2.0,m-v,p+v/2.0);
            else
                dfs(k+1,f*m,0.000000,m-v,p+v);
    }
}
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lf%lf%lf%lf",&c,&m,&p,&v);
        ans=0.000000;
        dfs(1,1.0000,c,m,p);
        printf("%lf\n",ans);
    }
    return 0;
}