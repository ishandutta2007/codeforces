#include <bits/stdc++.h>

using namespace std;

struct pt
{
    double x, y;
    pt operator+ (const pt& o) const
    {
        return (pt){x+o.x, y+o.y};
    }
    pt operator- (const pt& o) const
    {
        return (pt){x-o.x, y-o.y};
    }
    double operator^ (const pt& o) const
    {
        return x*o.y-y*o.x;
    }
    double dot (const pt& o) const
    {
        return x*o.x+y*o.y;
    }
    double magsq() const
    {
        return x*x+y*y;
    }
};

bool cpointOnSeg(pt a, pt d, pt p)
{
    return (p-a).magsq()<d.magsq() && (p-a).dot(d)>0;
}

int side(pt a, pt d, pt p)
{
    double s=d^(p-a);
    if(s<0)
        return -1;
    if(s>0)
        return 1;
    return 0;
}

bool intersects(pt a0, pt d0, pt a1, pt d1)
{
    if((d0^d1)==0)
    {
        if((d0^(a1-a0))!=0)
            return false;
        return cpointOnSeg(a0, d0, a1) ||
               cpointOnSeg(a0, d0, a1+d1) ||
               cpointOnSeg(a1, d1, a0) ||
               cpointOnSeg(a1, d1, a0+d0);
    }
    return side(a0, d0, a1)*side(a0, d0, a1+d1)==-1 &&
           side(a1, d1, a0)*side(a1, d1, a0+d0)==-1;
}

int N, W;
long long V, U;
pt poly[10000];

bool intersectsPoly(pt a, pt d)
{
    for(int i=0; i<N; i++)
    {
        pt p=poly[i];
        pt q=poly[(i+1)%N];
        if(intersects(a, d, p, q-p))
            return true;
    }
    return false;
}

int main()
{
    scanf("%d%d%lld%lld", &N, &W, &V, &U);
    double base=(double)W/U;
    long long OV=V;
    for(int i=0; i<N; i++)
        scanf("%lf%lf", &poly[i].x, &poly[i].y);
    while(U<W)
        U*=2, V*=2;
    if(!intersectsPoly({0, 0}, {(double)V, (double)U}))
        printf("%.9f\n", base);
    else
    {
        double lo=0.0, mid, hi=1e10;
        for(int i=0; i<60; i++)
        {
            mid=(lo+hi)/2;
            if(intersectsPoly({mid, 0}, {(double)V, (double)U}))
                lo=mid;
            else
                hi=mid;
        }
        printf("%.9f\n", base+lo/OV);
    }
    return 0;
}