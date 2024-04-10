#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define N 100005
int n,k;
int a[1003];
int main()
{
    scanf("%d %d",&n,&k);
    for(int i=1; i<=n; i++)
        scanf("%d",&a[i]);
    sort(a+1,a+1+n);
    int ans=0;
    k=k*2;
    for(int i=1; i<=n; i++){
        while(a[i]>k){
            ans++;
            k=k*2;
        }
        k=max(k,a[i]*2);
    }
    printf("%d\n",ans);
    return 0;
}