#include <cstdio>
#include <iostream>
#include <vector>
#include <memory.h>
#include <cmath>

using namespace std;

int n;
double x[101],y[101],z[101];

inline double dist(double x1,double y1,double z1,double x2,double y2,double z2)
{
    return sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2)+(z1-z2)*(z1-z2));
}

double solve(double X,double Y,double Z)
{
    double res=dist(X,Y,Z,x[0],y[0],z[0]),r;
    for(int i=1;i<n;i++)
    {
        r=dist(X,Y,Z,x[i],y[i],z[i]);
        if (res<r) res=r;
    }
    return res;
}

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    cin >> n;
    for(int i=0;i<n;i++)
        cin >> x[i] >> y[i] >> z[i];
    double lx=x[0],rx=x[0],ly=y[0],ry=y[0],lz=z[0],rz=z[0];
    for(int i=0;i<n;i++)
    {
        lx=min(lx,x[i]);
        rx=max(rx,x[i]);
        ly=min(ly,y[i]);
        ry=max(ry,y[i]);
        lz=min(lz,z[i]);
        rz=max(rz,z[i]);
    }
    double Lx=lx,Rx=rx,Ly=ly,Ry=ry,Lz=lz,Rz=rz;
    int it=40;
    for(int t1=0;t1<it;t1++)
    {
        double mx1=lx+(rx-lx)/3,mx2=rx-(rx-lx)/3,x1,x2;
        ly=Ly; ry=Ry;
        for(int t2=0;t2<it;t2++)
        {
            double my1=ly+(ry-ly)/3,my2=ry-(ry-ly)/3,y1,y2;
            lz=Lz; rz=Rz;
            for(int t3=0;t3<it;t3++)
            {
                double mz1=lz+(rz-lz)/3,mz2=rz-(rz-lz)/3,z1=solve(mx1,my1,mz1),z2=solve(mx1,my1,mz2);
                if (z1<z2) rz=mz2;
                else lz=mz1;
            }
            y1=solve(mx1,my1,lz);
            lz=Lz; rz=Rz;
            for(int t3=0;t3<it;t3++)
            {
                double mz1=lz+(rz-lz)/3,mz2=rz-(rz-lz)/3,z1=solve(mx1,my2,mz1),z2=solve(mx1,my2,mz2);
                if (z1<z2) rz=mz2;
                else lz=mz1;
            }
            y2=solve(mx1,my2,lz);
            if (y1<y2) ry=my2;
            else ly=my1;
        }
        x1=solve(mx1,ly,lz);
        ly=Ly; ry=Ry;
        for(int t2=0;t2<it;t2++)
        {
            double my1=ly+(ry-ly)/3,my2=ry-(ry-ly)/3,y1,y2;
            lz=Lz; rz=Rz;
            for(int t3=0;t3<it;t3++)
            {
                double mz1=lz+(rz-lz)/3,mz2=rz-(rz-lz)/3,z1=solve(mx2,my1,mz1),z2=solve(mx2,my1,mz2);
                if (z1<z2) rz=mz2;
                else lz=mz1;
            }
            y1=solve(mx2,my1,lz);
            lz=Lz; rz=Rz;
            for(int t3=0;t3<it;t3++)
            {
                double mz1=lz+(rz-lz)/3,mz2=rz-(rz-lz)/3,z1=solve(mx2,my2,mz1),z2=solve(mx2,my2,mz2);
                if (z1<z2) rz=mz2;
                else lz=mz1;
            }
            y2=solve(mx2,my2,lz);
            if (y1<y2) ry=my2;
            else ly=my1;
        }
        x2=solve(mx2,ly,lz);
        if (x1<x2) rx=mx2;
        else lx=mx1;
    }
    printf("%.7lf %.7lf %.7lf\n",lx,ly,lz);
//  cout << solve(0,0,0) << endl;
    return 0;
}