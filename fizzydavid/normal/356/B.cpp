#include<algorithm>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<map>
#include<queue>
#include<set>
#include<stack>
#include<string>
#include<utility>
#include<vector>
using namespace std;
#define ll long long
int gcd(ll a,ll b){return(a%b)?gcd(b,a%b):b;}
ll cnt[1001000][30],m,n;
string x,y;
int main()
{
    cin>>n>>m>>x>>y;
    ll g=gcd(x.size(),y.size());
    for(ll i=0;i<y.size();i++)
    {
        cnt[i%g][y[i]-'a']++;
    }
    ll sum=0;
    for(int i=0;i<x.size();i++)
    {
        sum+=(n*g/y.size())*cnt[i%g][x[i]-'a'];
    }
    cout<<fixed<<(ll)x.size()*n-sum;
    return 0;
}