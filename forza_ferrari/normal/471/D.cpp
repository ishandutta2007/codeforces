#include<iostream>
#include<cstdio>
using namespace std;
int n,m,a[200001],b[200001],pi[200001],s[200001<<1],ans;
int main()
{
    scanf("%d%d",&n,&m);
    if(m==1)
    {
        printf("%d\n",n);
        return 0;
    }
    for(int i=1;i<=n;++i)
        scanf("%d",&a[i]);
    for(int i=1;i<=m;++i)
        scanf("%d",&b[i]);
    for(int i=1;i<m;++i)
        s[i-1]=b[i+1]-b[i];
    s[m-1]=1e9+7;
    for(int i=1;i<n;++i)
        s[i+m-1]=a[i+1]-a[i];
    for(int i=1;i<n+m-1;++i)
    {
        int j=pi[i-1];
        while(j>0&&s[i]!=s[j])
            j=pi[j-1];
        if(s[i]==s[j])
            ++j;
        pi[i]=j;
        if(i>m-1&&pi[i]==m-1)
            ++ans;
    }
    printf("%d\n",ans);
    return 0;
}