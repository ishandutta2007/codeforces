#include<bits/stdc++.h>
#define maxn 2300405
#define F first
#define S second

using namespace std;
typedef long long ll;
typedef pair<ll,ll> pi;
pi a[maxn],b[maxn];
ll p,q,t,n,m,k,x[maxn],y[maxn],s,l;
double ans;

int main()
{
    scanf("%d%d",&n,&k);
    for (int i=0;i<n;i++)
    {
        scanf("%d",&y[i]);
    }
    for (int i=0;i<n;i++)
    {
        scanf("%d",&x[i]);
    }
    for (int i=0;i<n;i++)
    {
        if (x[i]==k) ans+=1.0*y[i];
        else if (x[i]>k) a[p++]={x[i]-k,y[i]};
        else b[q++]={k-x[i],y[i]};
    }
    for (int i=0;i<p;i++) s+=a[i].F*a[i].S;
    for (int i=0;i<q;i++) t+=b[i].F*b[i].S;
    m=min(s,t); l=m;
    sort(a,a+p);sort(b,b+q);
    for (int i=0;i<p;i++)
    {
        if (m<a[i].F*a[i].S) {ans+=1.0*m/a[i].F;break;}
        m-=a[i].F*a[i].S; ans+=1.0*a[i].S;
    }
    m=l;
    for (int i=0;i<q;i++)
    {
        if (m<b[i].F*b[i].S) {ans+=1.0*m/b[i].F;break;}
        m-=b[i].F*b[i].S; ans+=1.0*b[i].S;
    }
    printf("%.10f\n",ans);
    return 0;
}