#include <bits/stdc++.h>
#define long long long
#define pb push_back
#define pll pair < int , int >
#define vll vector < pll >
#define ml map < int , int >
#define mll map < pll , int >
#define x first
#define y second
#define vl vector < int >
#define io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
long isprime(long n)
{
    long i;
    for(i=2;i*i<=n;++i)
    if(n%i==0) return 0;
    return 1;
}
int main()
{
    io
    long n,m,i,a[3];
    cin>>n;
    if(n==3) {cout<<1<<endl<<3;exit(0);}
    if(n==5) {cout<<2<<endl<<2<<" "<<3;exit(0);}
    m=n-4;
    while(1)
    {
        if(isprime(m)) break;
        m--;
    }
    a[0]=m;
    m=n-m;
    for(i=2;i<=m;++i)
    if(isprime(i) && isprime(m-i))
    {
        a[1]=i;
        a[2]=m-i;
        break;
    }
    long cnt=3;
    if(a[0]==0) cnt--;
    if(a[1]==0) cnt--;
    if(a[2]==0) cnt--;
    cout<<cnt<<endl;
    for(i=0;i<3;++i)
    if(a[i])
    cout<<a[i]<<" ";
    return 0;
}