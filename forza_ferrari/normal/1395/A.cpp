#include<iostream>
#include<cstdio>
using namespace std;
#define int long long
int t,a,b,c,d;
signed main()
{
    scanf("%lld",&t);
    while(t--)
    {
        scanf("%lld%lld%lld%lld",&a,&b,&c,&d);
        int qwq=(a&1)+(b&1)+(c&1)+(d&1);
        if((qwq>1&&!min(a,min(b,c)))||qwq==2)
            puts("No");
        else
            puts("Yes");
    }
    return 0;
}