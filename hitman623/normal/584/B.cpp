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
long h=1e9+7;
long po(long a,long b)
{
    if(a==0) return 0;
    if(b==0 || a==1) return 1;
    long m=po(a,b/2);
    if(b%2==0) return (m*m)%h;
    return (((m*m)%h)*a)%h;
}
int main()
{
    io
    long n;
    cin>>n;
    cout<<(po(27,n)-po(7,n)+h)%h;
    return 0;
}