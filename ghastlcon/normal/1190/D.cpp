#include<iostream>
#include<string>
#include<cstring>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<stdio.h>
#include<algorithm>
#include<set>
using namespace std;

const int maxn=200100;

struct data
{
    int X,Y;
} point[maxn];

set <int> s;
int bit[maxn];

int vx[maxn];
int cnt=0;

int n;
long long ans=0;

bool Comp1(data x,data y)
{
    return x.X<y.X;
}

bool Comp2(data x,data y)
{
    return ( x.Y>y.Y || ( x.Y==y.Y && x.X<y.X ) );
}

int Get(int x)
{
    int *y=upper_bound(vx,vx+cnt+1,x);
    x=(int)(y-vx);
    x--;
    return x;
}

int Query(int x)
{
    int v=0;
    while (x)
    {
        v+=bit[x];
        x-=( x&(-x) );
    }
    return v;
}

void Dec(int l,int r)
{
    r--;
    l=Get(l);
    r=Get(r);
    long long x=Query(r)-Query(l);
    ans-=( x*(x+1LL)/2LL );
}

void Update(int x)
{
    x=Get(x);
    int v=Query(x)-Query(x-1);
    if (v==1) return;
    
    while (x<=cnt)
    {
        bit[x]++;
        x+=( x&(-x) );
    }
}

int main()
{
    scanf("%d",&n);
    for (int i=1; i<=n; i++)
        scanf("%d%d",&point[i].X,&point[i].Y);
    
    sort(point+1,point+n+1,Comp1);
    for (int i=1; i<=n; i++)
        if (point[i-1].X<point[i].X) vx[++cnt]=point[i].X;
    vx[++cnt]=1500000000;
    vx[0]=-10000;
    
    sort(point+1,point+n+1,Comp2);
    s.clear();
    int k=1;
    while (k<=n)
    {
        int lk=k;
        int last=-100,ny=point[k].Y;
        while ( k<=n && point[k].Y==ny )
        {
            Dec(last,point[k].X);
            last=point[k].X;
            k++;
        }
        Dec(last,1000000100);
        
        for (int i=lk; i<k; i++)
            s.insert(point[i].X),Update(point[i].X);
        long long x=s.size();
        ans+=( x*(x+1LL)/2LL );
    }
    printf("%I64d\n",ans);
    
    return 0;
}