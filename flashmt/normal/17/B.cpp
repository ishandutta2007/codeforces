#include<iostream>
#define maxn 1010
#define maxm 100010
#define oo 1000000000

using namespace std;

int a[maxm],b[maxm],c[maxm];
int q[maxn],par[maxn];
bool fr[maxn];

int min(int x,int y)
{
    return x<y?x:y;
}

void sort(int l,int r)
{
     int i,j,x,y;
     i=l; j=r; x=c[(i+j)/2];
     do
     {
          while (c[i]<x) i++;
          while (c[j]>x) j--;
          if (i<=j)
          {
              y=a[i]; a[i]=a[j]; a[j]=y;
              y=b[i]; b[i]=b[j]; b[j]=y;
              y=c[i]; c[i]=c[j]; c[j]=y;
              i++; j--;
          }
     } while (i<=j);
     if (i<r) sort(i,r);
     if (l<j) sort(l,j);
}

int find(int x)
{
    if (par[x]!=x) par[x]=find(par[x]);
    return par[x];
}

int main()
{
    int n,m,i,x,y,cnt,re;
    cin >> n;
    for (i=1;i<=n;i++) cin >> q[i];
    cin >> m;
    for (i=1;i<=m;i++) cin >> a[i] >> b[i] >> c[i];
    sort(1,m);    
    for (i=1;i<=n;i++) 
    {
        par[i]=i; fr[i]=true;
    }
    cnt=0;
    re=0;
    for (i=1;i<=m;i++)
    {
        if (!fr[b[i]]) continue;
        x=find(a[i]); y=find(b[i]);
        if (x!=y)
        {
           par[y]=x;
           fr[b[i]]=false;
           re+=c[i];
           cnt++;
           if (cnt==n-1) break;
        }
    }
    if (cnt==n-1) cout << re;
    else cout << -1;
    return 0;
}