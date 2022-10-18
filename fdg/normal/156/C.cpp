#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <string>
#include <vector>
#include <math.h>
using namespace std;
#define M_PI 3.14159265358979323846
#define mp make_pair
#define pb push_back
#define rs resize
#define x first
#define y second
#define ll long long
#define pll pair<ll,ll>
#define mod 1000000007
ll t;
string s;
ll dp[2505][105];
ll modul(ll a)
{return ((a%mod)+mod)%mod;}
ll rez(string S)
{
    ll sum=0;
    for (ll j=0;j<S.size();j++){sum+=S[j]-'a';}
    return sum;
}
int main()
{
   
    scanf("%I64d\n",&t);
    dp[0][0]=1;
    for (ll i=1;i<=100;i++)
    {
        for (ll j=0;j<=2500;j++)
        {
            for (ll k=0;k<=min((ll)25,j);k++)
            {
                dp[j][i]+=dp[j-k][i-1];
                dp[j][i]%=mod;
            }
        }
    }
    for (ll i=0;i<t;i++)
    {
        getline(cin,s);
        ll a=rez(s);
        if (a==0)
        {cout<<"0"<<endl;}
        else
        {cout<<modul(dp[a][s.size()]-1)<<endl;}
    }
}