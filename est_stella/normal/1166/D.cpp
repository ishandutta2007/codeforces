#include<bits/stdc++.h>
using namespace std;

long long q, a, b, m;

void solve()
{
    scanf("%lld %lld %lld", &a, &b, &m);

    if(a==b)
    {
        printf("1 %lld\n", a);
        return;
    }

    long long st = a + 1;
    long long ed = a + m;
    long long t=1;
    while(true)
    {
        if(st <= b && b <= ed) break;
        if( b < st )
        {
            printf("-1\n");
            return;
        }
        st <<=1 ;
        ed <<=1 ;
        t++;
    }

    b -= (a+1) << (t-1);

    vector<long long> ans;

    for(long long i=t-1; i>=0; i--)
    {
        long long mod=1;
        if(i!=0) mod <<= (i-1);

        long long k = b / mod;
        if( k >= m ) k = m-1;

        ans.push_back(k+1);
        b -= k * mod;
    }

    printf("%lld ", t+1);
    long long p = a;
    long long sum = a;
    for(long long i=0; i<t; i++)
    {
        printf("%lld ", p);
        p = sum + ans[i];
        sum += p;
    }
    printf("%lld\n", p);
}

int main()
{
    scanf("%lld", &q);

    while(q--)
    {
        solve();
    }
}