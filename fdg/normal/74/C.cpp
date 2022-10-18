#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <cstdio>
#include <cmath>
#include <ctime>
#include <set>
#include <map>

#define ll long long

using namespace std;

int ans=0,n,m;

bool was[4][1000001]={0};
bool needExit;

void rec(int type,int x,int s)
{
    if (was[type][x]||needExit)
    {
        needExit=true;
        return;
    }
    was[type][x]=true;
    if (type==0)
    {
        if (x==1) s=1;
        if (x==m) s=-1;
        if (s>0)
        {
            if (m-x<n-1) rec(3,m-x+1,1);
            else rec(1,x+n-1,1);
        }
        else
        {
            if (x-1<n-1) rec(2,x,1);
            else rec(1,x-n+1,-1);
        }
    }
    if (type==1)
    {
        if (x==1) s=1;
        if (x==m) s=-1;
        if (s>0)
        {
            if (m-x<n-1) rec(3,n-(m-x),-1);
            else rec(0,x+n-1,1);
        }
        else
        {
            if (x-1<n-1) rec(2,n-(x-1),-1);
            else rec(0,x-n+1,-1);
        }
    }
    if (type==2)
    {
        if (s>0)
        {
            if (n-x<=m-1) rec(1,n-x+1,1);
            else rec(3,x+m-1,1);
        }
        else
        {
            if (x-1<=m-1) rec(0,x,1);
            else rec(3,x-m+1,-1);
        }
    }
    if (type==3)
    {
        if (s>0)
        {
            if (n-x<=m-1) rec(1,m-(n-x),-1);
            else rec(2,x+m-1,1);
        }
        else
        {
            if (x-1<=m-1) rec(0,m-(x-1),-1);
            else rec(2,x-m+1,-1);
        }
    }
}

int main()
{
//  freopen("input.txt","r",stdin);
//  freopen("output.txt","w",stdout);
    cin >> n >> m;
    needExit=false;
    rec(0,1,1); ans++;
    if (!was[0][m])
    {
        needExit=false;
        rec(0,m,-1);
        ans++;
    }
    if (!was[1][1])
    {
        needExit=false;
        rec(1,1,1);
        ans++;
    }
    if (!was[1][m])
    {
        needExit=false;
        rec(1,m,-1);
        ans++;
    }
    for(int i=1;i<=m;i++)
    {
        if (!was[0][i])
        {
            needExit=false;
            rec(0,i,1);
            ans++;
        }
        if (!was[1][i])
        {
            needExit=false;
            rec(1,i,1);
            ans++;
        }
    }
    for(int i=2;i<n;i++)
    {
        if (!was[2][i])
        {
            needExit=false;
            rec(2,i,1);
            ans++;
        }
        if (!was[3][i])
        {
            needExit=false;
            rec(3,i,1);
            ans++;
        }
    }
    cout << ans << endl;
    return 0;
}