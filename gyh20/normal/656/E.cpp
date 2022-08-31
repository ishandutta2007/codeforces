#include<bits/stdc++.h>
using namespace std;
int a[12][12],n,ans;
int main(){
scanf("%d",&n);
f\
o\
r(int i=1;i<=n;++i)
f\
o\
r(int j=1;j<=n;++j)scanf("%d",&a[i][j]);
f\
o\
r(int k=1;k<=n;++k)
f\
o\
r(int i=1;i<=n;++i)
f\
o\
r(int j=1;j<=n;++j) a[i][j]=min(a[i][j],a[i][k]+a[k][j]);
f\
o\
r(int i=1;i<=n;++i)
f\
o\
r(int j=1;j<=n;++j)ans=max(ans,a[i][j]);
printf("%d",ans);
}