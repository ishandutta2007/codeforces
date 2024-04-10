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
int T,OK;
long long A,B,C,n,k,d1,d2;
void Try(long long d1,long long d2)
{
    if((long long)(k-1LL*2*d1-d2)%3!=0) return;
    A=(long long)(k-1LL*2*d1-d2)/3;
    B=A+d1;
    C=B+d2;
    if(A<0||B<0||C<0) return;
    if(A<=n/3&&B<=n/3&&C<=n/3) OK=1;
}
int main()
{
//freopen("input","r",stdin);
//freopen("output","w",stdout);
scanf("%d\n",&T);
while(T)
{
    T--;
    scanf("%I64d %I64d %I64d %I64d",&n,&k,&d1,&d2);
    if(n%3!=0) printf("no\n");
    else
    {
        OK=0;
        Try(-d1,-d2);
        Try(-d1,d2);
        Try(d1,-d2);
        Try(d1,d2);
        if(OK) printf("yes\n");
        else printf("no\n");
    }
}
return 0;
}