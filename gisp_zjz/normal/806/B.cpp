#include<bits/stdc++.h>

using namespace std;
int a[5],b[5],c[5],n,k,p[5],q[5],s,t;

int f(int x,int y)
{
    if (x*32<=y) return 6;
    if (x*16<=y) return 5;
    if (x*8<=y) return 4;
    if (x*4<=y) return 3;
    if (x*2<=y) return 2;
    return 1;
}

int main()
{
    scanf("%d",&n);
    for (int i=0;i<n;i++)
    {
        for (int j=0;j<5;j++)
        {
            scanf("%d",&k);
            if (i==0) a[j]=k;
            if (i==1) b[j]=k;
            if (k>=0) c[j]++;
        }
    }
    for (int i=0;i<5;i++)
    {
        if (a[i]==-1) p[i]=0; else p[i]=250-a[i];
        if (b[i]==-1) q[i]=0; else q[i]=250-b[i];
    }
    for (int i=0;i<=5000;i++)
    {
        s=0; t=0;
        for (int j=0;j<5;j++)
        {
            if (p[j]&&p[j]<q[j]) s+=p[j]*f(c[j]+i,n+i),t+=q[j]*f(c[j]+i,n+i);
            else s+=p[j]*f(c[j],n+i),t+=q[j]*f(c[j],n+i);
        }
        if (s>t) {cout << i << endl; return 0;}
    }
    cout << -1 << endl;
}