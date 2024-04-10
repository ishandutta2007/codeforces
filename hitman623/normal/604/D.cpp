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
long h=1e9+7;
long po(long a,long b)
{
    if(a==0) return 0;
    if(a==1 || b==0) return 1;
    long m=po(a,b/2);
    m=(m*m)%h;
    if(b&1) return (m*a)%h;
    return m;
}
int main()
{
    io
    long k,p,cur=1,i;
    cin>>p>>k;
    if(k==1) {cout<<po(p,p);return 0;}
    if(k==0) {cout<<po(p,p-1);return 0;}
    for(i=0;i<p-1;++i)
    {
        cur=(cur*k)%p;
        if(cur==1) {cout<<po(p,(p-1)/(i+1));return 0;}
    }
    return 0;
}