/*
    Author  : JZdavid
    From    : CF
    Problem : 28B
    Time    : 2014/8/7
    Verdict : Accepting
*/
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<set>
#include<utility>
#include<vector>
using namespace std;
#define ff first
#define ss second
#define pb push_back 
#define mp make_pair
typedef long long ll;
const int INF=1<<28;
const long long LINF=1ll<<61;
int n;
struct dsu
{
    int Size;
    int p[511];
    int size()
    {
        return Size;
    }
    dsu()
    {
        Size=0;
        for(int i=1;i<=500;i++)p[i]=i;
    }
    int find(int x)
    {
        if(p[x]!=x)p[x]=find(p[x]);
        return p[x];
    }
    void unn(int x,int y)
    {
        int t1=find(x),t2=find(y);
        if(t1!=t2)Size++,p[t1]=t2;
    }
}d;
int a[111],b[111];
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++)
    {
        cin>>b[i];
        if(i-b[i]>0)d.unn(i,i-b[i]);
        if(i+b[i]<=n)d.unn(i,i+b[i]);
    }
    bool ok=1;
    for(int i=1;i<=n;i++)if(d.find(i)!=d.find(a[i]))ok=0;
    if(ok==1)puts("YES");else puts("NO");
//  system("pause");
    return 0;
}