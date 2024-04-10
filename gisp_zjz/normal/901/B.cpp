#include<bits/stdc++.h>
#define maxn 200050

using namespace std;
int a[maxn],b[maxn],c[maxn],n;

int cal(int x)
{
    if (x==1) return 1;
    if (x==3) return -1;
    return 0;
}

int main()
{
    scanf("%d",&n);
    a[0]=0;a[1]=1;b[0]=1;
    for (int i=1;i<n;i++)
    {
        c[0]=0; for (int j=0;j<=i;j++) c[j+1]=a[j];
        for (int j=0;j<i;j++) c[j]=(c[j]+b[j])%4;
        for (int j=0;j<=i;j++) b[j]=a[j];
        for (int j=0;j<=i+1;j++) a[j]=c[j];
    }
    printf("%d\n",n);
    for (int i=0;i<=n;i++) printf("%d ",cal(a[i])); printf("\n");
    printf("%d\n",n-1);
    for (int i=0;i<n;i++) printf("%d ",cal(b[i])); printf("\n");
    return 0;
}