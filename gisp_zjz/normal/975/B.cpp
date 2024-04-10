#include<bits/stdc++.h>
#define maxn 15

using namespace std;
typedef long long ll;
ll a[maxn],ans,k,r,d,b[maxn];

int main()
{
    for (int i=0;i<14;i++) scanf("%lld",&a[i]);
    for (int i=0;i<14;i++) b[i]=a[i];
    for (int i=0;i<14;i++)
    {
        if (b[i]==0) continue;
        for (int j=0;j<14;j++) a[j]=b[j]; a[i]=0;
        for (int j=0;j<14;j++) a[j]+=b[i]/14;
        r=b[i]%14;
        for (int j=1;j<=r;j++) a[(i+j)%14]++;
        k=0; for (int j=0;j<14;j++) if (a[j]%2==0) k+=a[j];
        ans=max(ans,k);
        //for (int j=0;j<14;j++) cout << a[j] << ' '; cout << k << endl;
    }
    cout << ans << endl;
}