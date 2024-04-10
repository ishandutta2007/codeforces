#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <cstdio>

#define ll long long

using namespace std;

long double x[10002]={0},y[10002]={0},z[10002]={0};

long double dist(long double x1,long double y1,long double z1,long double x2,long double y2,long double z2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2));
}

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n;
    cin >> n;
    for(int i=0;i<=n;i++)
        cin >> x[i] >> y[i] >> z[i];
    long double vp,vs,px,py,pz;
    cin >> vp >> vs >> px >> py >> pz;
    long double lt=0.0;
    for(int i=0;i<n;i++)
    {
        if (i>0)
        {
            lt+=dist(x[i],y[i],z[i],x[i-1],y[i-1],z[i-1])/vs;
        }
        long double l=lt,r=lt+dist(x[i],y[i],z[i],x[i+1],y[i+1],z[i+1])/vs;
        long double rt=r;
        for(int t=0;t<200;t++)
        {
            long double m=(l+r)/2.0;
            long double s=(m-lt)*vs,all=dist(x[i],y[i],z[i],x[i+1],y[i+1],z[i+1]);
            s/=all;
            long double d=dist(px,py,pz,x[i]+(x[i+1]-x[i])*s,y[i]+(y[i+1]-y[i])*s,z[i]+(z[i+1]-z[i])*s);
            if (m*vp>=d-1e-12) r=m;
            else l=m;
        }
        l=(r+l)/2;
        long double s1=(l-lt)*vs,all=dist(x[i],y[i],z[i],x[i+1],y[i+1],z[i+1]);
        s1/=all;
        long double d1=dist(px,py,pz,x[i+1],y[i+1],z[i+1]);
        bool poss=false;
        if (d1-1e-12<=rt*vp) poss=true;
        if (poss)
        {
            cout << "YES\n";
            printf("%.7lf\n",l);
            printf("%.7lf %.7lf %.7lf\n",x[i]+(x[i+1]-x[i])*s1,y[i]+(y[i+1]-y[i])*s1,z[i]+(z[i+1]-z[i])*s1);
            return 0;
        }
    }
    cout << "NO\n";
    lt+=dist(x[n-1],y[n-1],z[n-1],x[n],y[n],z[n])/vs;
    long double d1=dist(px,py,pz,x[n],y[n],z[n]);
    bool poss=false;
    if (d1<=lt*vp) poss=true;
    if (poss) return -1;
    return 0;
}