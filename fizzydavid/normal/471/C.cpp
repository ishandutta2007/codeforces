//while(true)rp++;
#include<algorithm>
#include<cstdlib>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<map>
#include<queue>
#include<stack>
#include<string>
#include<set>
#include<utility>
#include<vector>
using namespace std;
#define ff first
#define ss second
#define pb push_back 
#define mp make_pair
typedef long long ll;
const ll INF=1<<28;
const ll LINF=1ll<<61;
ll count(ll x)
{
    return x*(x+1)+x*(x-1)/2;
}
ll n;
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    ll maxh=0;
    while(count(maxh)<=n)maxh++;
    maxh--;
    ll sum=0;
    for(ll i=1;i<=maxh;i++)if((n-count(i))%3==0)sum++;
    cout<<sum;
    return 0;
}