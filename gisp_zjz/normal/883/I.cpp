#include<bits/stdc++.h>
#define maxn 302050

using namespace std;
int a[maxn],l,r,mid,n,k,f[maxn],g[maxn],p,mn[maxn];

bool check(int x)
{
    int j=0;
    queue <int> q;
    while (!q.empty()) q.pop();
    for (int i=0;i<n;i++)
    {
        while (j<n&&a[j]-a[i]<=x) j++;
        f[i]=i+k; g[i]=j; if (f[i]>g[i]) f[i]=n+1;
    }
    q.push(0); p=0;
    while (!q.empty())
    {
        int t=q.front(); q.pop();
        for (int j=max(p+1,f[t]);j<=g[t];j++) q.push(j);
        p=g[t];
        if (t==n) return true;
    }
    return false;
}

int main()
{
    scanf("%d%d",&n,&k);
    for (int i=0;i<n;i++) scanf("%d",&a[i]); sort(a,a+n);
    l=-1; r=1000000001;
    while (r-l>1){
        mid=(l+r)/2;
        if (check(mid)) r=mid; else l=mid;
    }
    cout << r << endl;
}