#include <bits/stdc++.h>

using namespace std;

const int MOD=1000000007;

int power(int a, int b)
{
    int ans=1;
    for(int i=0; i<b; i++)
        ans=1LL*ans*a%MOD;
    return ans;
}

int main()
{
    int N;
    scanf("%d", &N);
    int ans=power(27, N)-power(7, N);
    if(ans<0)
        ans+=MOD;
    printf("%d\n", ans);
    return 0;
}