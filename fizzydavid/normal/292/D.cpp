/*
    Author  : JZdavid
    From    : CF
    Problem : 292D
    Time    : 2014/8/6
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
int n,m,k;
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
}l[10011],r[10011];
pair<int,int> edge[10011];
int main()
{
    ios::sync_with_stdio(false);
    cin>>n>>m;
    for(int i=1;i<=m;i++)
    {
        int x,y;
        cin>>x>>y;
        edge[i].ff=x,edge[i].ss=y;
    }
    for(int i=1;i<=m;i++)l[i]=l[i-1],l[i].unn(edge[i].ff,edge[i].ss);
    for(int i=m;i>=1;i--)r[i]=r[i+1],r[i].unn(edge[i].ff,edge[i].ss);
    cin>>k;
    while(k--)
    {
        dsu tmp;
        int x,y;
        cin>>x>>y;
        tmp=l[x-1];
        for(int i=1;i<=n;i++)tmp.unn(i,r[y+1].p[i]);
        cout<<n-tmp.size()<<endl;
    }
//  system("pause");
    return 0;
}