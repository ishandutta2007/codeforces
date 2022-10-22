#include<bits/stdc++.h>
using namespace std;

int n, ans = 1000000000;
int arr[300001];

int main()
{
    scanf("%d", &n);

    for(int i=1; i<=n; i++)
        scanf("%d", &arr[i]);

    for(int i=1; i<=n; i++)
    {
        int l = max(n-i, i-1);

        ans = min(ans, arr[i]/l);
    }

    printf("%d", ans);
}