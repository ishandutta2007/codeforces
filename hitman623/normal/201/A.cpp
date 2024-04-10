#include <bits/stdc++.h>
#define pb push_back
#define long long long
#define pll pair < long , long >
#define vll vector < pll >
#define vl vector < long >
using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    long n,x;
    cin>>n;
    if(n==2) {cout<<3;exit(0);}
    if(n==3) {cout<<5;exit(0);}
    x=sqrt(2*n);
    x=x+((x*x+1)/2<n);
    if(x%2==0) x++;
    cout<<x;
    return 0;
}