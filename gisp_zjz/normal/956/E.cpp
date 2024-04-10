#include<bits/stdc++.h>
#define maxn 10005

using namespace std;
int a[maxn],b[maxn],p,q,n,s[maxn],t[maxn],l,r,lf,rt,mid,rr;
bool f[maxn];

bool check(int x)
{
    int sum=0,s2=0;
    for (int i=0;i<x-1;i++) sum+=a[i];
    for (int i=x-1;i<p;i++) s2+=a[i];
    if (sum>r-l) return false;
    rr=r-sum;
    memset(f,false,sizeof(f));f[0]=true;
    for (int i=x-1;i<p;i++)
    {
        for (int j=min(rr,s2-1);j>=a[i];j--) f[j]|=f[j-a[i]];
        for (int j=l;j<=rr;j++) if (f[j]) return true;
    }
    for (int i=0;i<q;i++)
    {
        for (int j=rr;j>=b[i];j--) f[j]|=f[j-b[i]];
        for (int j=l;j<=rr;j++) if (f[j]) return true;
    }
    return false;
}

int main()
{
    scanf("%d%d%d",&n,&l,&r);
    for (int i=1;i<=n;i++) scanf("%d",&s[i]);
    for (int i=1;i<=n;i++) scanf("%d",&t[i]);
    for (int i=1;i<=n;i++) if (t[i]) a[p++]=s[i]; else b[q++]=s[i];
    sort(a,a+p); sort(b,b+q);
    lf=0;rt=p+1;
    while (rt-lf>1)
    {
        mid=(lf+rt)/2;
        if (check(mid)) lf=mid; else rt=mid;
    }
    cout << lf << endl;
    return 0;
}