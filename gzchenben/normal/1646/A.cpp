#include<cstdio>
using namespace std;
int t;
long long n,s;
int main()
{
    scanf("%d",&t);
    while(t--)
    {
        scanf("%lld%lld",&n,&s);
        printf("%lld\n",s/(n*n));
    }
}