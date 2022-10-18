#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>

#define ll long long

using namespace std;

struct point{
    point(int a,int b) : x(a), y(b) {};
    int x,y;
};

struct cicle{
    cicle(int a,point b) : r(a), c(b) {};
    point c;
    int r;
};

bool operator ==(const cicle & a,const cicle & b)
{
    return a.r==b.r&&a.c.x==b.c.x&&a.c.y==b.c.y;
}

bool in(const cicle & a,const point & b)
{
    ll r=1LL*a.r*a.r,d=1LL*(a.c.x-b.x)*(a.c.x-b.x)+1LL*(a.c.y-b.y)*(a.c.y-b.y);
    if (r>=d) return true;
    return false;
}

bool sort1(const cicle & a,const cicle & b)
{
    return in(b,a.c)&&in(b,point(a.c.x+a.r,a.c.y));
}

vector <point> points;
vector <cicle> cicles;
vector < vector <cicle> > v;
int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    int n,m,k,a,b,c;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<n;i++)
    {
        scanf("%d%d",&a,&b);
        points.push_back(point(a,b));
    }
    for(int i=0;i<m;i++)
    {
        scanf("%d%d%d",&c,&a,&b);
        cicles.push_back(cicle(c,point(a,b)));
    }
    for(int i=0;i<n;i++)
    {
        v.push_back(vector <cicle>());
        for(int j=0;j<m;j++)
        {
            if (in(cicles[j],points[i])) v[i].push_back(cicles[j]);
        }
        sort(v[i].begin(),v[i].end(),sort1);
//      for(int t=0;t<v[i].size();t++)
//          for(int t1=0;t1<v[i].size();t1++)
//              cout << t << "  " << t1 << "    " <<  sort1(v[i][t],v[i][t1]) << endl;
//          cout << v[i][t].r << "  " << v[i][t].c.x << "   " << v[i][t].c.y << endl;
//      cout << endl;
    }
    for(int i=0;i<k;i++)
    {
        scanf("%d%d",&a,&b);
        a--; b--;
        if (a==b)
        {
            printf("0\n");
            continue;
        }
        if (v[a].size()==0||v[b].size()==0||(!(v[a].back()==v[b].back())))
        {
            printf("%d\n",v[a].size()+v[b].size());
            continue;
        }
        int l=0,r=v[a].size(),L=v[a].size(),R=v[b].size(),m;
        while(l<r)
        {
            m=(l+r)/2;
            int ind1=m,ind2=R-(L-m);
            if (ind2<0||(!(v[a][ind1]==v[b][ind2]))) l=m+1;
            else r=m;
        }
        m=(l+r)/2;
        printf("%d\n",m+R-(L-m));
    }
    return 0;
}