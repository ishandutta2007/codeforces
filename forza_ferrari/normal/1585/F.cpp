#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;
const int mod=998244353;
int n,a[200001],dp[200001],ans;
stack<int> t;
int main()
{
    cin>>n;
    dp[0]=1;
    t.emplace(0);
    for(int i=1;i<=n;++i)
    {
        cin>>a[i];
        while(a[t.top()]>=a[i])
        {
            int p=t.top();
            t.pop();
            ans=(ans-1ll*(dp[p-1]-(t.top()? dp[t.top()-1]:0)+mod)%mod*a[p]%mod+mod)%mod;
        }
        ans=(ans+1ll*(dp[i-1]-(t.top()? dp[t.top()-1]:0)+mod)%mod*a[i]%mod)%mod;
        t.emplace(i);
        dp[i]=(dp[i-1]+(mod-ans)%mod)%mod;
    }
    cout<<(n&1? ans:mod-ans)%mod<<'\n';
    return 0;
}