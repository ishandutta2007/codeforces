#include <bits/stdc++.h>

using namespace std;

long long N;
int cnt[100001];

int validate(long long x)
{
    if(x>N)
        return -1;
    int c=0;
    while(x>0)
    {
        long long y=cbrt(x);
        while(y*y*y<=x)
            y++;
        y--;
        x-=y*y*y;
        c++;
    }
    return c;
}

int main()
{
    scanf("%lld", &N);
    long long z=0;
    long long sum=0;
    for(int i=1; i<=100000; i++)
    {
        long long a=1LL*i*i*i;
        long long b=1LL*(i+1)*(i+1)*(i+1);
        b=min(b, N+1);
        cnt[i]=(b-sum-1)/a;
        sum+=cnt[i]*a;
        z+=cnt[i];
        if(b==N+1)
            break;
    }
    vector<int> v;
    for(int i=1; i<=100000; i++)
        for(int j=0; j<cnt[i]; j++)
            v.push_back(i);
    while(!v.empty())
    {
        for(int i=100000; i>=0; i--)
        {
            if(validate(sum+1LL*i*i*i-1LL*v.back()*v.back()*v.back())==z)
            {
                sum+=1LL*i*i*i-1LL*v.back()*v.back()*v.back();
                break;
            }
        }
        v.pop_back();
    }
    printf("%lld %lld\n", z, sum);
    return 0;
}