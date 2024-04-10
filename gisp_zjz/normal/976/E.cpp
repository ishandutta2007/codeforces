#include<bits/stdc++.h>
#define maxn 323402
#define F first
#define S second

using namespace std;
typedef long long ll;
typedef pair<ll,ll>pi;
ll a[maxn],n,b[maxn],k,s,t,ans,d[maxn],sum[maxn];
pi c[maxn];

int main()
{
    scanf("%d%d%d",&n,&s,&t); t=min(n,t);
    for (int i=0;i<n;i++)
    {
        scanf("%d%d",&a[i],&b[i]);
        ans+=b[i];
        c[i].F=b[i]-a[i]; c[i].S=i;
    }
    sort(c,c+n); k=ans;
    if (t==0){cout << ans << endl;return 0;}
    for (int i=0;i<n;i++) d[c[i].S]=i;
    sum[0]=max(0ll,-c[0].F); for (int i=1;i<n;i++) sum[i]=sum[i-1]+max(0ll,-c[i].F);
    //for (int i=0;i<n;i++) cout << sum[i] << ' '; cout << endl;
    for (int i=0;i<n;i++){
        //cout << ans << ' ' << d[i] << endl;
        if (d[i]<t) ans=max(ans,k+sum[t-1]-max(0ll,a[i]-b[i])-b[i]+(a[i]<<s));
        else ans=max(ans,k+sum[t-2]-b[i]+(a[i]<<s));
    }
    cout << ans << endl;
}