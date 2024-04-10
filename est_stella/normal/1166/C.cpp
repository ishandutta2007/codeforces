#include<bits/stdc++.h>
using namespace std;

int n;
long long ans;
int a[200001];

int main()
{
    scanf("%d", &n);

    for(int i=0; i<n; i++)
    {
        scanf("%d", &a[i]);

        if(a[i]<0) a[i] = -a[i];
    }

    sort(a, a+n);

    for(int i=0; i<n; i++)
    {
        int k = a[i];

        ans += (upper_bound(a, a+n, k*2)-a) - i - 1;
    }

    printf("%lld", ans);
}