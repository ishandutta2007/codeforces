#include <bits/stdc++.h>

using namespace std;

int n, k;

int main()
{
    scanf("%d%d", &n, &k);
    k=240-k;
    int ans=0;
    for(int i=1; i<=n; i++) if(i*5<=k)
        k-=i*5, ans++;
    printf("%d\n", ans);
    return 0;
}