#include<bits/stdc++.h>

using namespace std;
typedef long long ll;

ll n,k;

int main()
{
    scanf("%I64d%I64d",&n,&k);
    for (int i=1;i<=k;i++)
    {
        if (n%i==i-1) continue;
        puts("No");
        return 0;
    }
    puts("Yes");
}