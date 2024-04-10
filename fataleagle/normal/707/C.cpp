#include <bits/stdc++.h>

using namespace std;

int N;

void solve(int x, int k)
{
    printf("%lld %lld\n", k*((1LL*x*x)/2), k*((1LL*x*x+1)/2));
    exit(0);
}

int main()
{
    scanf("%d", &N);
    int x=N;
    if(N<=2)
        printf("-1\n");
    else if(N%2==1)
        solve(N, 1);
    else if(x==(x&-x))
    {
        int k=1;
        while(x>4)
        {
            x/=2;
            k*=2;
        }
        printf("%lld %lld\n", 3LL*k, 5LL*k);
    }
    else
    {
        int k=1;
        while(x%2==0)
        {
            x/=2;
            k*=2;
        }
        solve(x, k);
    }
    return 0;
}