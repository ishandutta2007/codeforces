#include<bits/stdc++.h>
#define maxn 230405

using namespace std;
int a[maxn],n,ans;

int main()
{
    scanf("%d",&n); ans=0;
    for (int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
        ans=max(ans,min(1000000-a[i],a[i]-1));
    }
    cout << ans << endl;
}