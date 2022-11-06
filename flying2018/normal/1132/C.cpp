#include<iostream>
#include<cstdio>
#include<cstring>
#define N 5010
using namespace std;
int c[N],s[N][3];
int l[N],r[N];
int main()
{
    int n,q;
    scanf("%d%d",&n,&q);
    for(int i=1;i<=q;i++)
    {
        scanf("%d%d",&l[i],&r[i]);
        c[l[i]]++,c[r[i]+1]--;
    }
    for(int i=1;i<=n;i++) c[i]+=c[i-1];
    int res=0;
    for(int i=1;i<=n;i++) res+=!!c[i];
    for(int i=1;i<=n;i++)
        for(int j=0;j<=2;j++) s[i][j]=s[i-1][j]+(c[i]==j);
    int ans=1e7;
    for(int i=1;i<=q;i++)
        for(int j=i+1;j<=q;j++)
        {
            int p=min(r[i],r[j])-max(l[i],l[j]);
            if(p<0) ans=min(ans,s[r[i]][1]-s[l[i]-1][1]+s[r[j]][1]-s[l[j]-1][1]);
            else ans=min(ans,s[max(r[i],r[j])][1]-s[min(l[i],l[j])-1][1]+s[min(r[i],r[j])][2]-s[max(l[i],l[j])-1][2]);
        }
    printf("%d\n",res-ans);
    return 0;
}