#include <bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const int N=1005;
ll n;
vector<ll> ans;
void tryf(ll k)
{
    ll v=0,t=n/k;
    ans.push_back(t+t*(t-1)/2*k);
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n;
    for(ll i=1;i*i<=n;i++){
        if(n%i==0){
            tryf(i);
            tryf(n/i);
        }
    }
    sort(ans.begin(),ans.end());
    if(ans.size()&&ans[ans.size()-1]!=(ll)n*(n+1)/2) ans.push_back((ll)n*(n+1)/2);
    for(int i=0;i<ans.size();i++){
        if(i!=0&&ans[i]==ans[i-1]) continue;
        cout<<ans[i]<<" ";
    }
    return 0;
}