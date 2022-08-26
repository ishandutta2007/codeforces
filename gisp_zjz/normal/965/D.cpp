#include<bits/stdc++.h>
#define maxn 100050

using namespace std;
int a[maxn],s[maxn],n,w,ans;

int main()
{
    scanf("%d%d",&n,&w); ans=2e9;
    for (int i=1;i<n;i++) scanf("%d",&a[i]);
    for (int i=1;i<n;i++) s[i]=s[i-1]+a[i];
    for (int i=w;i<n;i++) ans=min(ans,s[i]-s[i-w]);
    cout << ans << endl;
}