#include<bits/stdc++.h>
#define maxn 5020

using namespace std;

int n,a[maxn];

int main()
{
    scanf("%d",&n); for (int i=1;i<=n;i++) scanf("%d",&a[i]);
    for (int i=1;i<=n;i++)
    {
        if (a[a[a[i]]]==i){
            puts("YES");
            return 0;
        }
    }
    puts("NO");
    return 0;
}