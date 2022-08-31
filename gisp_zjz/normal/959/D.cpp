#include<bits/stdc++.h>
#define maxn 2000040

using namespace std;
bool f[maxn],p[maxn];
int a[maxn],b[maxn],n,k,r,t,j,c[maxn];

bool check(int x)
{
    int j=2; r=0; t=x;
    while (j*j<=x){
        if (t%j==0) {
            while (t%j==0) t/=j;
            c[r++]=j;
        }
        j++;
    }
    if (t>1) c[r++]=t;
    for (int i=0;i<r;i++) if (p[c[i]]) return false;
    return true;
}

int main()
{
    memset(f,true,sizeof(f));
    for (int i=2;i<maxn;i++)
    {
        if (!f[i]) continue;
        for (int j=2;j*i<maxn;j++) f[i*j]=false;
    }
    for (int i=2;i<maxn;i++) if (f[i]) b[++t]=i;
    scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    for (int i=0;i<n;i++)
    {
        if (check(a[i])) for (int j=0;j<r;j++) p[c[j]]=true;
        else {
            while (!check(a[i])) a[i]++;
            for (int j=0;j<r;j++) p[c[j]]=true; r=1;
            for (int j=i+1;j<n;j++)
            {
                while (p[b[r]]) r++;
                a[j]=b[r++];
            }
            break;
        }
    }
    for (int i=0;i<n;i++) printf("%d ",a[i]); printf("\n");
    return 0;
}