#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <ctime>
#include <set>

#define ll long long

using namespace std;

struct Point{
    Point(int _x = 0,int _y = 0) : x(_x), y(_y) {};
    int x,y,num;
};

bool operator <(const Point & a,const Point & b)
{
    return a.x<b.x||a.x==b.x&&a.y<b.y;
}

bool operator ==(const Point & a,const Point & b)
{
    return a.x==b.x&&a.y==b.y;
}

Point v[200001];
int n;

void rec(int l,int r)
{
    if (l>=r) return;
    int m=(l+r)>>1;
    rec(l,m-1); rec(m+1,r);
    for(int i=l;i<=r;i++)
        v[n++]=Point(v[m].x,v[i].y);
}

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    scanf("%d",&n);
    for(int i=0;i<n;i++)
        scanf("%d%d",&v[i].x,&v[i].y);
    sort(v,v+n);
    rec(0,n-1);
    sort(v,v+n);
    n=unique(v,v+n)-v;
    printf("%d\n",n);
    for(int i=0;i<n;i++)
        printf("%d %d\n",v[i].x,v[i].y);
    return 0;
}