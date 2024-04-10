#include<bits/stdc++.h>
#define maxn 1050

using namespace std;
typedef long long ll;
ll a[maxn],b[maxn],n,k,p,q;

int main()
{
    scanf("%d",&n); scanf("%d%d",&p,&q); p+=q;
    for (int i=0;i<n;i++) scanf("%lld",&a[i]);
    for (int i=0;i<n;i++) scanf("%lld",&b[i]);
    for (int i=0;i<n;i++) a[i]=abs(a[i]-b[i]);
    for (int i=0;i<p;i++)
    {
        k=0;
        for (int j=1;j<n;j++) if (a[j]>a[k]) k=j;
        a[k]=abs(a[k]-1);
    }
    k=0;
    for (int i=0;i<n;i++) k+=a[i]*a[i];
    cout << k << endl;
}