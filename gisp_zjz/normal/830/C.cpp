#include<bits/stdc++.h>
#define maxn 10000000

using namespace std;
typedef long long ll;
ll n,a[maxn],b[maxn],ans,k,c,r,f,s;

int main()
{
    scanf("%d%lld",&n,&k); for (int i=0;i<n;i++) scanf("%d",&a[i]);
    for (int i=0;i<n;i++) s+=a[i]; s+=k;
    for (int i=1;i<=32000;i++) b[c++]=i;
    for (int i=0;i<n;i++)
    {
        k=int(sqrt(a[i]));
        for (int j=1;j<=k;j++) b[c++]=(a[i]-1)/j+1;
    }
    sort(b,b+c);
    for (int i=c-1;i>=0;i--)
    {
        if (i&&b[i]==b[i-1]) continue; r=0;
        for (int j=0;j<n;j++) r+=(a[j]-1)/b[i]+1;
        f=s-r*b[i]; if (f<0) continue;
        cout << f/r+b[i] << endl;
        return 0;
    }
}