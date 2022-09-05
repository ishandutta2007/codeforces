/*
while(true)rp++;
*/
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
const int INF=1<<28;
const long long LINF=1ll<<61;
int n;
bool mk1[500111],mk2[500111];
ll a[500111],sum,pre[500111],mk2pre[500111];
int main()
{
    ios::sync_with_stdio(false);
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        pre[i]=pre[i-1]+a[i];
        sum+=a[i];
    }
    ll cnt1=0,cnt2=0;
    for(int i=1;i<n;i++)
    {
        if(2*pre[i]==sum-pre[i])cnt1++,mk1[i]=1;
        if(pre[i]==2*(sum-pre[i]))cnt2++,mk2[i]=1;
    }
//  cout<<cnt1<<" "<<cnt2<<endl;
    for(int i=n-1;i>=1;i--)mk2pre[i]=mk2pre[i+1]+mk2[i];
    ll ans=0;
    for(int i=1;i<n;i++)
    {
        if(mk1[i])ans+=mk2pre[i+1];
    }
    cout<<ans;
    return 0;
}