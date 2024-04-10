#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long LL;
#define PB push_back
#define ST first
#define ND second
#define REP(x,n) for(int x=0; x<(n);x++)
#define FOR(x,b,e) for(int x=b; x<=(e);x++)
#define FORD(x,b,e) for(int x=b; x>=(e);x--)
#define SIZE(x) ((int)(x).size())

const int MAXN = 2*100000+10;
const LL INF64 = (LL)1000*1000*1000*1000*1000*1000;

struct Edge
{
    int a,b;
    LL c;
    bool operator <(const Edge &x)const
    {
        return c<x.c;
    }
};

int n,m,r,id;
LL mini=INF64;
Edge E[MAXN*3];
LL a[MAXN];
int parent[MAXN],sizer[MAXN];
LL result;

int fuf(int x)
{
    if(x==parent[x])
        return x;
    else
        parent[x]=fuf(parent[x]);
    return parent[x];
}

void fuu(int a,int b)
{
    int Ra=fuf(a),Rb=fuf(b);
    if(a!=b)
    {
        if(sizer[Ra]<sizer[Rb])
        {
            parent[Ra]=Rb;
            sizer[Rb]+=sizer[Ra];
        }
        else
        {
            parent[Rb]=Ra;
            sizer[Ra]+=sizer[Rb];
        }
    }
}

void MST()
{
    sort(E,E+r);
    REP(i,r)
    {
        if(fuf(E[i].a)!=fuf(E[i].b))
        {
            fuu(E[i].a,E[i].b);
            result+=E[i].c;
        }
    }
}

int main()
{
    cin>>n>>m;
    FOR(i,1,n) {
        cin>>a[i];
        if(mini>a[i])
        {
            mini=a[i]; id=i;
        }
    }
    REP(i,m)
    {
        Edge pom;
        cin>>pom.a>>pom.b>>pom.c;
        E[r] = pom; r++;
    }
    FOR(i,1,n)
    {
        if(i!=id)
        {
            Edge pom; pom.a=id; pom.b=i; pom.c=(LL)a[id]+a[i];
            E[r]=pom;r++;
        }
    }
    REP(i,n+1)
    {
        sizer[i]=1;
        parent[i]=i;
    }
    MST();
    cout<<result;
    return 0;
}