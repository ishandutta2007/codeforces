#include<cstdio>
#include<vector>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
int i,n,a[100009];
long long ss,s,sub,sup,cm;
long long gcd(long long a,long long b)
{
    long long r;
    while(b)
    {
        r=a%b;
        a=b;
        b=r;
    }
    return a;
}
int main()
{
//freopen("input","r",stdin);
//freopen("output","w",stdout);
scanf("%d",&n);
for(i=1;i<=n;i++)
    scanf("%d",&a[i]);
sort(a+1,a+n+1);
for(i=1;i<=n;i++)
{
    s+=1LL*a[i]*(i-1);
    s-=1LL*a[i]*(n-i);
}
ss=0;
for(i=1;i<=n;i++)
    ss+=a[i];
s=1LL*s*2+1LL*ss;
sup=s;
sub=1LL*n;
cm=gcd(sub,sup);
sup/=cm;
sub/=cm;
printf("%I64d %I64d\n",sup,sub);
return 0;
}