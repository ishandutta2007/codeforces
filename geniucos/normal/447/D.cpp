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
int n,m,i,j,K,P,l[1009],c[1009],a[1009][1009];
long long maxi,kst,V;
vector < long long > L,C;
priority_queue < long long > q;
vector < long long > detv(int c[],int n,int m)
{
    long long tot=0;
    vector < long long > ras;
    for(i=1;i<=m;i++)
        q.push(c[i]);
    kst=1LL*P*n;
    ras.push_back(0);
    for(i=1;i<=K;i++)
    {
        V=q.top();
        tot+=V;
        q.pop();
        q.push(V-kst);
        ras.push_back(tot);
    }
    while(!q.empty()) q.pop();
    return ras;
}
void U(long long x)
{
    if(x>maxi) maxi=x;
}
int main()
{
//freopen("input","r",stdin);
//freopen("output","w",stdout);
scanf("%d",&n);
scanf("%d",&m);
scanf("%d",&K);
scanf("%d",&P);
maxi=-(1LL<<62);
for(i=1;i<=n;i++)
    for(j=1;j<=m;j++)
    {
        scanf("%d",&a[i][j]);
        l[i]+=a[i][j];
        c[j]+=a[i][j];
    }
C=detv(c,n,m);
L=detv(l,m,n);
for(i=0;i<=K;i++)
    U(C[i]+L[K-i]-1LL*(K-i)*P*i);
printf("%I64d\n",maxi);
return 0;
}