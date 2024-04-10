#include <bits/stdc++.h>

using namespace std;

long long H, N;
long long dp[51];

long long solve(int dir, long long h, long long x)
{
    if(h==0)
        return 0;
    if(dir==0)
    {
        if(x<=(1LL<<(h-1)))
            return 1+solve(1, h-1, x);
        return (1LL<<h)+solve(0, h-1, x-(1LL<<(h-1)));
    }
    if(x<=(1LL<<(h-1)))
        return (1LL<<h)+solve(1, h-1, x);
    return 1+solve(0, h-1, x-(1LL<<(h-1)));
}

int main()
{
    cin>>H>>N;
    cout<<solve(0, H, N)<<endl;
    return 0;
}