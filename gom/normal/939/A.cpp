#include <bits/stdc++.h>
#define N 5005
using namespace std;
int n,a[N];
int main()
{
    scanf("%d",&n);
    for(int i=1;i<=n;i++)
        scanf("%d",&a[i]);
    for(int i=1;i<=n;i++){
        if(a[a[a[i]]]==i){
            printf("YES");
            return 0;
        }
    }
    printf("NO");
    return 0;
}