#include<bits/stdc++.h>
#define maxn 500020

using namespace std;

int a[maxn],n;
bool f[maxn];

int main()
{
    scanf("%d",&n);
    for (int i=1;i<=n;i++)scanf("%d",&a[i]);
    a[0]=0;memset(f,true,sizeof(f));
    int ans=0;
    for (int i=n;i>=1;i--)
    if (f[i]){
        ans++;
        int t=i; f[t]=false;
        while (t>0&&f[a[t]]){
            t=a[t];
            f[t]=false;
        }
    }
    printf("%d\n",ans);
    return 0;
}