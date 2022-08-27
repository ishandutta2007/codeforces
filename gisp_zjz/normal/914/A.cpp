#include<bits/stdc++.h>
#define maxn 2030400

using namespace std;

int n,a[maxn],ans;
bool f[maxn];

int main()
{
    scanf("%d",&n);
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    sort(a,a+n);
    memset(f,true,sizeof(f));
    for (int i=0;i<=1000;i++) f[i*i]=false;
    ans=a[0];
    for (int i=1;i<n;i++) if (a[i]<0||f[a[i]]) ans=a[i];
    printf("%d\n",ans);
    return 0;
}