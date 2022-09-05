#include<cstdio>
#include<cmath>
#include<vector>
#include<cstring>
#include<cmath>
#include<queue>
#include<set>
#include<algorithm>
#include<ctime>
#include<cstdlib>
using namespace std;
int nr,i,n,k,phi[100009],EX[100009],sol[100009];
char a[100009];
int main()
{
//freopen("input","r",stdin);
//freopen("output","w",stdout);
gets(a+1);
n=strlen(a+1);
phi[1]=k=0;
for(i=2;i<=n;i++)
{
    while(k&&a[k+1]!=a[i]) k=phi[k];
    if(a[k+1]==a[i]) k++;
    phi[i]=k;
}
k=n;
while(k) EX[k]++,k=phi[k];
for(i=n;i>=1;i--)
    sol[phi[i]]++;
for(i=n;i>=1;i--)
    sol[phi[i]]+=sol[i];
for(i=1;i<=n;i++)
    nr+=(EX[i]>0);
printf("%d\n",nr);
for(i=1;i<=n;i++)
    if(EX[i]) printf("%d %d\n",i,sol[i]+1);
return 0;
}