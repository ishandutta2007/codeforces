#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <cmath>
#include <ctime>
#include <cstdio>
#include <set>

#define ll long long

using namespace std;

int calc(int n,int m,int k)
{
    int l;
    int blocks=min(n/(k+1),m/(k+1)),N=min(n,m);
    if (n<m)
    {
        if (m%2==0) l=1;
        else l=0;
    }
    else
    {
        if (n%2==0) l=1;
        else l=0;
    }
    N-=blocks*(k+1);
    if (N==0) return 1;
    if ((k&1&&k!=1)&&blocks&1) l^=1;
    if (N%2==0) l^=1;
    return l;
}

//int D[1002][1002]={0};

int main()
{
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int n=3,m=38,k=1,T;
    scanf("%d%d",&T,&k);
    while(T--)
    {
        scanf("%d%d",&n,&m);
    
        if (calc(n,m,k)) printf("+\n");
        else printf("-\n");
    }
    return 0;
}