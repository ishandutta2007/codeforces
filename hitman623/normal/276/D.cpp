#include <bits/stdc++.h>
#define pb push_back
#define long long long
#define pll pair < long , long >
#define vll vector < pll >
#define vl vector < long >
#define io ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
using namespace std;
void bin(char a[] , long b)
{
    long i=74;a[75]=0;
    while(i>=0)
    {
        a[i]=b%2+'0';
        i--,b/=2;
    }
}
int main()
{
    io
    long l,r,i,j;
    cin>>l>>r;
    char a[75],b[75];
    bin(a,l);
    bin(b,r);
    for(i=0;i<75;++i)
    if(a[i]!=b[i]) break;
    long ans=1;
    for(j=0;j<75-i;++j)
    ans*=2;
    cout<<ans-1<<endl;
    return 0;
}