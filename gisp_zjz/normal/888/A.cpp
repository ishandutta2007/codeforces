#include<bits/stdc++.h>
using namespace std;
int a[203400],n;

int main()
{
    scanf("%d",&n); int ans=0;
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    for (int i=1;i<n-1;i++) if (a[i]>a[i-1]&&a[i]>a[i+1]||a[i]<a[i-1]&&a[i]<a[i+1]) ans++;
    cout << ans << endl;
}