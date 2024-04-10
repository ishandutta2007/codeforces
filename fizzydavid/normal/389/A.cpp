#include<iostream>
#include<cstdlib>
using namespace std;
#define ll long long
int gcd(ll num1,ll num2)
{
    ll t;
    if(num1<num2)swap(num1,num2);
    while(num2!=0)t=num1%num2,num1=num2,num2=t;
    return num1;
}
int main()
{
    ll n,x,res;
    cin>>n;
    cin>>res;
    for(int i=2;i<=n;i++)
    {
        cin>>x;
        res=gcd(res,x);
    }
    cout<<res*n;
    return 0;
}