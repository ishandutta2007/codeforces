#include<iostream>
#include<algorithm>
using namespace std;
#define ll long long
#define REP(i,a,b) for(ll i=a;i<b;i++)

int main()
{
    ll a[4];
    REP(i,0,4) cin>>a[i];
    sort(a,a+4);
    ll sum=0;
    REP(i,0,4) sum+=a[i];
    if(a[0]+a[3]==a[1]+a[2]||2*a[3]==sum) cout<<"YES";
    else cout<<"NO";

    return 0;
}