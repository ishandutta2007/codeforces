#include<bits/stdc++.h>
using namespace std;

long long int n, q;
long long s[100001];
long long diff[100001];
long long sum[100001]={};

int main()
{
    scanf("%lld", &n);

    for(int i=0; i<n; i++)
    {
        scanf("%lld", &s[i]);
    }

    sort(s, s+n);
    for(int i=0; i<n-1; i++)
        diff[i]=s[i+1]-s[i];

    sort(diff, diff+n-1);

    for(int i=1; i<n; i++)
        sum[i] = sum[i-1]+diff[i-1];

    scanf("%lld", &q);
    while(q--)
    {
        long long int l, r;
        scanf("%lld %lld", &l, &r);

        long long int k = (long long int) (lower_bound(diff, diff+n-1, r-l+1) - diff);

        printf("%lld\n", (r-l+1)*(n-k)+sum[k]);
    }
}