#include<bits/stdc++.h>
#define maxn 2020

using namespace std;
int n,a[maxn],b[maxn],k,t,c,ans;

int main()
{
    scanf("%d",&n); n<<=1; ans=120391248;
    for (int i=0;i<n;i++) scanf("%d",&a[i]);
    sort(a,a+n);
    for (int i=0;i<n;i++)
        for (int j=i+1;j<n;j++)
        {
            t=0;
            for (int k=0;k<n;k++) if (k!=i&&k!=j) b[t++]=a[k];
            c=0; for (int i=0;i<n/2-1;i++) c+=b[i*2+1]-b[i*2];
            ans=min(ans,c);
        }
    cout << ans << endl;
}