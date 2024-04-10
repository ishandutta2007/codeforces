#include <bits/stdc++.h>
#define pb push_back
#define long long long
#define pll pair < long , long >
#define vll vector < pll >
#define ml map < long , long >
#define mll map < pll , long >
#define x first
#define y second
#define vl vector < long >
#define io ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
using namespace std;

int main()
{
    io
    vl v;
    cout<<fixed;
    cout<<setprecision(10);
    double pp=0,t1,t2;
    long n,i,a[2003],c[10005]={0},p[10005]={0},j;
    cin>>n;
    for(i=0;i<n;++i)
    cin>>a[i];
    sort(a,a+n);
    for(i=0;i<n;++i)
    for(j=i+1;j<n;++j)
    {
        c[a[j]-a[i]]++;
        if(c[a[j]-a[i]]==1)
        v.pb(a[j]-a[i]);
    }
    for(i=1;i<10004;++i)
    p[i]=p[i-1]+c[i];
    t2=(n*(n-1))/2;
    t2=t2*t2*t2;
    for(i=0;i<v.size();++i)
    for(j=0;j<v.size();++j)
    {
        t1=(p[10002]-p[v[i]+v[j]])*(c[v[i]])*(c[v[j]]);
        pp+=t1/t2;
    }
    cout<<pp;
    return 0;
}