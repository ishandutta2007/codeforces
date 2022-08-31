#include<bits/stdc++.h>
#define maxn 502030

using namespace std;
typedef long long ll;
const ll inf=10000000000ll;
ll a[maxn],p,n,k,b[maxn],l,r,mid;

bool check(ll x)
{
    int j=0;
    for (int i=0;i<n;i++)
    {
        while (j<k&&abs(a[i]-b[j])+abs(b[j]-p)>x) j++;
        if (j==k) return false;
        j++;
    }
    return true;
}

int main()
{
    scanf("%d%d%d",&n,&k,&p);
    for (int i=0;i<n;i++) scanf("%d",&a[i]); sort(a,a+n);
    for (int i=0;i<k;i++) scanf("%d",&b[i]); sort(b,b+k);
    l=-1; r=inf;
    while (r-l>1)
    {
        mid=(l+r)/2;
        if (check(mid)) r=mid; else l=mid;
    }
    cout << r << endl;
    return 0;
}