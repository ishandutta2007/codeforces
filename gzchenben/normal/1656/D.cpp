#include<cstdio>
#include<algorithm>
using namespace std;
int t;
long long n;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld",&n);
        long long tmp=1;
        while(n%2==0) 
        {
            n/=2;
            tmp*=2;
        }
        if(n==1) 
        {
            printf("-1\n");
            continue;
        }
        if(tmp*2<n) printf("%lld\n",2*tmp);
        else printf("%lld\n",n);
    }
}