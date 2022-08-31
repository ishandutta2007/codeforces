#include<bits/stdc++.h>
int n,b[500002],i,j;int main(){scanf("%d",&n);for(i=1;i<=n;++i)for(j=i+i;j<=n;j+=i)b[j]=i;std::sort(b+1,b+n+1);for(i=2;i<=n;++i)printf("%d ",b[i]);}