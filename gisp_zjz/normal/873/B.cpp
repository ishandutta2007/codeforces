#include<bits/stdc++.h>
#define maxn 200020
#define eps 1e-6
#define c 100000

using namespace std;

int n,k,ans,a[maxn],b[maxn];
char s[maxn];

int main()
{
    scanf("%d",&n);
    scanf("%s",s);
    k=0;
    for (int i=0;i<maxn;i++) a[i]=-1,b[i]=-1;
    a[c]=0;b[c]=0;
    for (int i=0;i<n;i++)
    {
        if (s[i]=='1') k++; else k--;
        if (a[c+k]==-1) a[c+k]=i+1;
        b[c+k]=i+1;
    }
    ans=0;
    for (int i=0;i<maxn;i++){
        if (a[i]!=-1) ans=max(ans,b[i]-a[i]);
    }
    printf("%d\n",ans);
    return 0;
}