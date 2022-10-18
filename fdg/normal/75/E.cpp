#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cmath>
#include <set>
#include <map>

#define ll long long

using namespace std;

double eps=1e-7;

struct Point{
    Point(double _x = 0,double _y = 0) : x(_x), y(_y) {};
    double x,y;
};

bool operator == (const Point & a,const Point & b)
{
    return fabs(a.x-b.x)<eps&&fabs(a.y-b.y)<eps;
}

Point v[50]={0};

bool intersect;

bool on(Point a,Point b,Point c)
{
    return min(a.x,b.x)<=c.x&&c.x<=max(a.x,b.x)&&min(a.y,b.y)<=c.y&&c.y<=max(a.y,b.y);
}

Point intersection(Point a,Point b,Point c,Point d)
{
    intersect=false;
    double A1=b.y-a.y,B1=a.x-b.x,C1=-a.x*A1-a.y*B1;
    double A2=d.y-c.y,B2=c.x-d.x,C2=-c.x*A2-c.y*B2;
    if (fabs(A1*B2-B1*A2)<eps) return Point(0,0);
    C1*=-1; C2*=-1;
    Point ret;
    ret.x=(C1*B2-B1*C2)/(A1*B2-B1*A2);
    ret.y=(A1*C2-C1*A2)/(A1*B2-B1*A2);
    if (on(a,b,ret)&&on(d,c,ret)) intersect=true;
    return ret;
}

double dist(Point a,Point b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    Point s,f;
    int n;
    cin >> s.x >> s.y >> f.x >> f.y >> n;
    for(int i=0;i<n;i++)
        cin >> v[i].x >> v[i].y;
    v[n]=v[0];
    vector < pair<Point,int> > p;
    for(int i=0;i<n;i++)
    {
        Point cp=intersection(v[i],v[i+1],s,f);
        if (intersect)
            p.push_back(make_pair(cp,i));
    }
    for(int i=0;i<p.size();i++)
        for(int j=i+1;j<p.size();j++)
            if (p[i].first==p[j].first)
            {
                p.erase(p.begin()+j);
                j--;
            }
    double ans=100000000;
    if (p.size()==2)
    {
        double val=dist(s,p[0].first)+dist(f,p[1].first)+2.0*dist(p[0].first,p[1].first);
        if (val<ans) ans=val;
        val=dist(f,p[0].first)+dist(s,p[1].first)+2.0*dist(p[0].first,p[1].first);
        if (val<ans) ans=val;
        int nums[2]={p[0].second,p[1].second};
        if (nums[0]>nums[1])
        {
            swap(nums[0],nums[1]);
            swap(p[0],p[1]);
        }
        double all=0,one=0.0;
        for(int i=0;i<n;i++)
            all+=dist(v[i],v[i+1]);
        if (nums[0]==nums[1]) one=dist(p[0].first,p[1].first);
        else one=dist(p[0].first,v[nums[0]+1])+dist(v[nums[1]],p[1].first);
        for(int i=nums[0]+1;i<nums[1];i++)
            one+=dist(v[i],v[i+1]);
        val=dist(s,p[0].first)+dist(f,p[1].first)+min(one,all-one);
        if (val<ans) ans=val;
        val=dist(f,p[0].first)+dist(s,p[1].first)+min(one,all-one);
        if (val<ans) ans=val;
    } else ans=dist(s,f);
    printf("%.6lf\n",ans);
    return 0;
}