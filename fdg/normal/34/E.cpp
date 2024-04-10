#include <cstdio>
#include <iostream>
#include <set>
#include <vector>
#include <algorithm>
#include <cmath>

#define ll long long

using namespace std;

struct ball{
    ball(int a,int b,int c) : x(a), v(b), m(c) {};
    double x,v,m;
};

double time(ball a,ball b)
{
    if (a.x>b.x) swap(a,b);
    if (a.v<=0)
    {
        if (a.v<=b.v) return 2000.0;
        return fabs(a.x-b.x)/fabs(fabs(a.v)-fabs(b.v));
    }
    if (b.v<=0) return fabs(a.x-b.x)/fabs(fabs(a.v)+fabs(b.v));
    if (b.v>=a.v) return 2000.0;
    return fabs(a.x-b.x)/fabs(fabs(a.v)-fabs(b.v));
}

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,t,a,b,c;
    scanf("%d%d",&n,&t);
    vector <ball> v;
    for(int i=0;i<n;i++)
    {
        scanf("%d%d%d",&a,&b,&c);
        v.push_back(ball(a,b,c));
    }
    double curt=0;
    while(true)
    {
        double tm=2000;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
            {
                if (i==j) continue;
                if (v[i].x==v[j].x) continue;
                tm=min(time(v[i],v[j]),tm);
            }
        }
        if (curt+tm>=t) break;
        bool used[12]={0};
        for(int i=0;i<n;i++)
        {
            for(int j=i+1;j<n;j++)
            {
                if (fabs(time(v[i],v[j])-tm)<1e-7)
                {
                    double v1=((v[i].m-v[j].m)*v[i].v+2*v[j].m*v[j].v)/(v[i].m+v[j].m),v2=((v[j].m-v[i].m)*v[j].v+2*v[i].m*v[i].v)/(v[i].m+v[j].m);
                    double x=v[i].x+v[i].v*tm;
                    v[i].x=x; v[j].x=x;
                    v[i].v=v1; v[j].v=v2;
                    used[i]=true; used[j]=true;
                }
            }
        }
        for(int i=0;i<n;i++)
            if (!used[i])
            {
                v[i].x=v[i].x+v[i].v*tm;
            }
            curt+=tm;
    }
    if (curt<=t)
    {
        for(int i=0;i<n;i++)
            v[i].x=v[i].x+v[i].v*(t-curt);
    }
    for(int i=0;i<n;i++)
        printf("%.9lf\n",v[i].x);
    return 0;
}